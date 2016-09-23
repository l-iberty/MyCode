/*
 *采用width(图片宽度)个线程并发,每个线程单独处理一行,
 *效果比GassianBlurTest2的效果还差......
 */

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

        double V = 3;
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
        GaussianBlurInfo gbInfo = new GaussianBlurInfo();
        gbInfo.setInfo(filename, blurRadius);

        Thread[] thread = new Thread[gbInfo.imgIn.getWidth()];
        for (int i = 0; i < thread.length; i++) {
            thread[i] = new Thread(new Runner(gbInfo, i));
        }
        for (int i = 0; i < thread.length; i++) {
            thread[i].start();
        }

        try {
            for (int i = 0; i < thread.length; i++)
                thread[i].join();
        } catch(InterruptedException e) {
            // do nothing
        }

        try {
            File pic_GaussianBlur = new File("pic_GaussianBlur.jpg");
		    ImageIO.write(gbInfo.imgOut, "jpg", pic_GaussianBlur);
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }

    private class GaussianBlurInfo {
        public int blurRadius;
        public BufferedImage imgIn, imgOut;
        public Graphics2D graph;

        public void setInfo(String filename, int blurRadius) {
            imgIn = createBufferedImage(filename);
            imgOut = new BufferedImage(imgIn.getWidth(), imgIn.getHeight(),
                            BufferedImage.TYPE_INT_RGB);
            graph = (Graphics2D) imgOut.getGraphics();
            this.blurRadius = blurRadius;

            setRGB(imgIn);
            setWeightMatrix(blurRadius);
        }
    }

    private class Runner implements Runnable {
        private GaussianBlurInfo gbInfo = null;
        private int begin;

        public Runner(GaussianBlurInfo gbInfo, int begin) {
            this.gbInfo = gbInfo;
            this.begin = begin;
        }

        @Override
        public void run() {
            for (int i = 0; i < rgbInfo[begin].length; i++) {
                if (!rgbInfo[begin][i].isVisited) {
                    int blurValue = getBlurValue(begin, i, gbInfo.blurRadius);
                    Color color = new Color(blurValue);
                    gbInfo.graph.setColor(color);
                    gbInfo.graph.drawLine(begin, i, begin+1, i+1);
                    rgbInfo[begin][i].isVisited = true;
                }
            }
        }
    }

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
            weight = weight / weightSum;
        }
    }

    private class RGBInfo {
        public int R, G, B;
        public boolean isVisited;

        public RGBInfo(int pixel) {
            R = (pixel & 0xff0000) >> 16;
            G = (pixel & 0xff00) >> 8;
            B = (pixel & 0xff) >> 0;
            isVisited = false;
        }
    }
}

public class GaussianBlurTest3 {
    public static void main(String[] args) {
        GaussianBlur gblur = new GaussianBlur();
        gblur.do_GaussianBlur("pic.jpg", Integer.parseInt(args[0]));
    }
}