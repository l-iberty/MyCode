import java.awt.*;
import java.io.*;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;

public class PictureReader{
	public static void main(String[] arg){
		int[] rgb = new int[3];
		int width;
		int height;
		int minx;
		int miny;
		int pixel;

        try {
        	File pic = new File("picture.jpg");
            BufferedImage bi = ImageIO.read(pic);
            FileWriter picInfo = new FileWriter("pictureInfo.txt");
            BufferedWriter bw = new BufferedWriter(picInfo);

        	width = bi.getWidth();
        	height = bi.getHeight();
        	minx = bi.getMinX();
        	miny = bi.getMinY();

        	System.out.println("width=" + width + ",height=" + height);
        	System.out.println("minx=" + minx + ",miniy=" + miny);

        	for (int i = minx; i < width; i++) {
		        for (int j = miny; j < height; j++) {
		            pixel = bi.getRGB(i, j);
		            /*getRGB()返回默认 sRGB ColorModel 中表示颜色的 RGB 值.
		            （24-31 位表示 alpha，16-23 位表示红色，8-15 位表示绿色，0-7 位表示蓝色）*/
		            rgb[0] = (pixel & 0xff0000) >> 16;
		            rgb[1] = (pixel & 0xff00) >> 8;
		            rgb[2] = (pixel & 0xff);

		            bw.write("i=" + i + ",j=" + j + ":(" + rgb[0] + ","
		                    + rgb[1] + "," + rgb[2] + ")");
		            bw.newLine();
		        }
		    }
		    bw.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

	}
}