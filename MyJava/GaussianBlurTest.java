import java.awt.Graphics2D;
import java.awt.Color;
import java.io.*;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;

class GaussianBlur {
    private WeightMatrixTbl[][] weightMatrix;
    private RGBInfo[][] rgbInfo;

    private static double Gaussian(double x, double y) {
        double E = 2.7182818284590452354;
        double PI = 3.14159265358979323846;

        double V = 3; // 方差
        double P = - (x * x + y * y) / (2 * V * V);
        double C = 1 / (2 * PI * V * V);

        return C * Math.pow(E, P);
    }

    private void setRGB(BufferedImage image) {
        // O(width * height)
        int width = image.getWidth();
        int height = image.getHeight();
        rgbInfo = new RGBInfo[width][height];

		if (image != null) {
			for (int x = image.getMinX(); x < width; x++)
                for (int y = image.getMinY(); y < height; y++)
                    rgbInfo[x][y] = new RGBInfo(image.getRGB(x, y));
		}
	}

    private BufferedImage createBufferedImage(String filename) {
        // O(1)
        try {
            File imgFile = new File(filename);
            BufferedImage image = ImageIO.read(imgFile);

            return image;
        } catch (IOException e) {
            return null;
        }
    }

    /*public void showRGBInfo(String filename) {
        setRGB(createBufferedImage(filename));

        try (FileWriter imgInfo = new FileWriter("imgInfo.txt");
             BufferedWriter bufw = new BufferedWriter(imgInfo)) {
            
            for (int i = 0; i < rgbInfo.length; i++) {
                for (int j = 0; j < rgbInfo[i].length; j++) {
                    bufw.write(rgbInfo[i][j].R + "," + rgbInfo[i][j].G + "," + rgbInfo[i][j].B);
                    bufw.newLine();
                }
            }
        } catch (IOException e) {
            // do nothing
        }
    }*/

    public void setWeightMatrix(int blurRadius) {
        // O(r^2)
        int N = blurRadius * 2 + 1;
        double weightSum = 0;        
        weightMatrix = new WeightMatrixTbl[N][N];

        for (int i = 0; i < N; i++) {
             for (int j = 0; j < N; j++) {
                weightMatrix[i][j] = new WeightMatrixTbl(i - blurRadius, j - blurRadius);
                weightSum += weightMatrix[i][j].getWeight();
            }
        }
        setWeight(weightSum);
    }

    private void setWeight(double weightSum) {
        for (int i = 0; i < weightMatrix.length; i++)
            for (int j = 0; j < weightMatrix[i].length; j++)
                weightMatrix[i][j].setWeight(weightSum);
    }

    /*public void showWeightMatrix(int blurRadius) {
        int N = blurRadius * 2 + 1;
        double weightSum = 0;

        for (int i = 0; i < weightMatrix.length; i++) {
            for (int j = 0; j < weightMatrix[i].length; j++) {
                //System.out.print("(" + weightMatrix[i][j].x + "," + weightMatrix[i][j].y + ")\t");
                System.out.print(weightMatrix[i][j].weight + "\t");
                weightSum += weightMatrix[i][j].getWeight();
            }
            System.out.println("");
        }
        System.out.println(weightSum);
    }*/

    private RGBInfo[][] getMatrix(int x, int y, int blurRadius) {
        // O(r^2)
        int N = blurRadius * 2 + 1;
        RGBInfo[][] tmp_rgbInfo = new RGBInfo[N][N];

        for (int i = x - blurRadius,a = 0; i <= x + blurRadius && a < N; i++,a++) {
            for (int j = y - blurRadius,b = 0; j <= y + blurRadius && b < N; j++,b++) {
                try {
                    tmp_rgbInfo[a][b] = rgbInfo[i][j];
                } catch (ArrayIndexOutOfBoundsException e) {
                    tmp_rgbInfo[a][b] = rgbInfo[Math.abs(i - x)][Math.abs(j - y)];
                }
            }
        }
        return tmp_rgbInfo;
    }

    private int getBlurValue(int x, int y, int blurRadius) {
        // O(r^2)
        int blurValue;
        int blurValue_R, blurValue_G, blurValue_B;
        RGBInfo[][] tmp_rgbInfo = getMatrix(x, y, blurRadius);

        blurValue_R = blurValue_G = blurValue_B = 0;
        for (int i = 0; i < tmp_rgbInfo.length; i++) {
            for (int j = 0; j < tmp_rgbInfo[i].length; j++) {
                blurValue_R += (int) ((double)tmp_rgbInfo[i][j].R * weightMatrix[i][j].weight);
                blurValue_G += (int) ((double)tmp_rgbInfo[i][j].G * weightMatrix[i][j].weight);
                blurValue_B += (int) ((double)tmp_rgbInfo[i][j].B * weightMatrix[i][j].weight);
            }
        }
        blurValue = ((255 & 0xff) << 24) |
                    ((blurValue_R & 0xff) << 16) |
                    ((blurValue_G & 0xff) << 8) |
                    ((blurValue_B & 0xff) << 0);
        return blurValue;
    }

    public void do_GaussianBlur(String filename, int blurRadius) {
        /*
         * O(width * height * r^2)
         */
        BufferedImage imgIn = createBufferedImage(filename);
        BufferedImage imgOut = new BufferedImage(imgIn.getWidth(), imgIn.getHeight(),
                BufferedImage.TYPE_INT_RGB);
        Graphics2D graph = (Graphics2D) imgOut.getGraphics();
        setRGB(imgIn); // O(width * height)
        setWeightMatrix(blurRadius); // O(r^2)

        // O(width * height * r^2)
        for (int i = 0; i < rgbInfo.length; i++) {
            for (int j = 0; j < rgbInfo[i].length; j++) {
                int blurValue = getBlurValue(i, j, blurRadius);// O(r^2)
                Color color = new Color(blurValue);
                graph.setColor(color);
                graph.drawLine(i, j, i+1, j+1);
            }
        }

        try {
            File pic_GaussianBlur = new File("pic_GaussianBlur.jpg");
		    ImageIO.write(imgOut, "jpg", pic_GaussianBlur);
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }

    /*public void test() {
        int blurValue;
        setRGB(createBufferedImage("pic.jpg"));
        setWeightMatrix(1);
        RGBInfo[][] tmp_rgbInfo = getMatrix(10,10,1);
        RGBInfo center;
        int centerR, centerG, centerB;
        centerR = centerG = centerB = 0;

        for (int i = 0; i < tmp_rgbInfo.length; i++) {
            for (int j = 0; j < tmp_rgbInfo[i].length; j++) {
                centerR += (int) ((double)tmp_rgbInfo[i][j].R * weightMatrix[i][j].weight);
                centerG += (int) ((double)tmp_rgbInfo[i][j].G * weightMatrix[i][j].weight);
                centerB += (int) ((double)tmp_rgbInfo[i][j].B * weightMatrix[i][j].weight);

                //System.out.print(tmp_rgbInfo[i][j].R_blurValue + "," +
                        //tmp_rgbInfo[i][j].G_blurValue + "," + tmp_rgbInfo[i][j].B_blurValue + "\t");
                System.out.print(tmp_rgbInfo[i][j].R + "," + tmp_rgbInfo[i][j].G + "," + tmp_rgbInfo[i][j].B + "\t");
            }
            System.out.println("");
        }
        System.out.println(centerR + "," + centerG + "," + centerB);
    }*/

    private class WeightMatrixTbl {
        private int x, y;
        private double weight;

        public WeightMatrixTbl(int x, int y) {
            this.x = x;
            this.y = y;
            weight = Gaussian((double)x, (double)y);
        }

        public double getWeight() {
            return weight;
        }

        public void setWeight(double weightSum) {
            weight = weight / weightSum; // 将每个点的权重除以权重和,使得新的权重之和为1
        }
    }

    private class RGBInfo {
        public int R, G, B;

        public RGBInfo(int pixel) {
            R = (pixel & 0xff0000) >> 16;
            G = (pixel & 0xff00) >> 8;
            B = (pixel & 0xff) >> 0;
        }
    }
}

public class GaussianBlurTest {
    public static void main(String[] args) {
        GaussianBlur gblur = new GaussianBlur();
        gblur.do_GaussianBlur("pic.jpg", Integer.parseInt(args[0]));
    }
}