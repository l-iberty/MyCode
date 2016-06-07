/** 本代码中所用的图像处理类在读取RGB时会有误差，
微小的误差将被解密函数的累乘急剧放大，导致无法
恢复.然而测试时使用的RGB(255,0,0)的图像在一组特
殊密钥的作用下不会产生误差，但不产生误差必须要
特定的RGB和特定的密钥，但实际应用时这不可能满足
**/

import java.awt.*;
import java.io.*;
import java.util.*;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;

class PicEncryptionCRT{
	private int[][] getRGB(BufferedImage image){
		int[][] rgb = new int[image.getWidth()][image.getHeight()];

		if(image != null){
			for(int x = image.getMinX(); x < image.getWidth(); x++)
				for(int y = image.getMinY(); y < image.getHeight(); y++)
					rgb[x][y] = image.getRGB(x, y);
		}
		return rgb;
	}

	public void fileEncrypt(BufferedImage inImage, int[] m) throws IOException{
		int i, x, y, pixel;
		int width = inImage.getWidth();
		int height = inImage.getHeight();
		int[][] rgb = getRGB(inImage);

		BufferedImage[] image = new BufferedImage[m.length];
		Graphics2D[] graph = new Graphics2D[m.length];
		Color[] color = new Color[m.length];
		File[] picture = new File[m.length];
		for(i = 0; i < image.length; i++){
			image[i] = new BufferedImage(width, height,
				BufferedImage.TYPE_INT_RGB);
			graph[i] = (Graphics2D) image[i].getGraphics();
		}

		for(i = 0; i < m.length; i++)
			for(x = image[i].getMinX(); x < width; x++)
				for(y = image[i].getMinY(); y < height; y++){
					color[i] = new Color(rgb[x][y] % m[i]);
					graph[i].setColor(color[i]);
					graph[i].drawLine(x, y, x+1, y+1);
				}

		for(i = 0; i < image.length; i++){
			picture[i] = new File("E_" + i + "Image.jpg");
			ImageIO.write(image[i], "jpg", picture[i]);
		}

		//检测原图的RGB
		/*System.out.println("Original info:");
		for(int w = 0; w < inImage.getWidth(); w++)
			for(int h = 0; h < inImage.getHeight(); h++)
				System.out.println("(" + w + "," + h + "): " + inImage.getRGB(w,h));

		//检测分存结果的RGB
		System.out.println("Image0 info:");
		for(int w = 0; w < image[0].getWidth(); w++)
			for(int h = 0; h < image[0].getHeight(); h++)
				System.out.println("(" + w + "," + h + "): " + image[0].getRGB(w,h));*/
		// 结果显示，分存是没有问题的
	}

	public void fileDecrypt(String[] filename, int[] m) throws IOException{
		/* 将每张图片的每个像素的RGB获取后组成一个数组，
		对应于原图的相应像素点的RGB，将此数组作为参数即
		可恢复 */
		int i, x, y, pixel, width, height;
		int[] cipher = new int[m.length];
		File[] picture = new File[filename.length];
		BufferedImage[] image = new BufferedImage[filename.length];

		for(i = 0; i < filename.length; i++){
			picture[i] = new File(filename[i]);
			image[i] = ImageIO.read(picture[i]);
		}

		// 再次检测
		/*System.out.println("Image0 info:");
		for(int w = 0; w < image[0].getWidth(); w++)
			for(int h = 0; h < image[0].getHeight(); h++)
				System.out.println("(" + w + "," + h + "): " + image[0].getRGB(w,h));*/

		width = image[0].getWidth();
		height = image[0].getHeight();
		// 所有图片的尺寸都一样
		BufferedImage outImage = new BufferedImage(width, height,
			BufferedImage.TYPE_INT_RGB); // 用于输出图像

		for(x = 0; x < width; x++){
			for(y = 0; y < height; y++){
				for(i = 0; i < cipher.length; i++)
					cipher[i] = image[i].getRGB(x,y);

				//System.out.println("cipher: " + Arrays.toString(cipher));
				pixel = (int)decrypt(cipher, m);
				//System.out.println("pixel=" + pixel);
				Color color = new Color(pixel);
				Graphics2D graph = (Graphics2D) outImage.getGraphics();
				graph.setColor(color);
				graph.drawLine(x, y, x+1, y+1);
			}
		}

		ImageIO.write(outImage, "jpg", new File("decryptImage.jpg"));
	}

	private long decrypt(int[] a, int[] m){
		long x = 0, M = 1;
		long[] N;
		long[] Mi = new long[a.length];
		
		for(int i = 0; i < m.length; i++)
			M *= m[i];
		for(int i = 0; i < Mi.length; i++)
			Mi[i] = M / m[i];
		
		N = calc_N(m, Mi);
		for(int i = 0; i < a.length; i++)
			x += a[i]*N[i]*Mi[i];
		
		return x % M;
	}
	
	private long[] calc_N(int m[], long Mi[]){
		long[] N = new long[m.length];
		long tmpN;
		boolean flag;
		
		for(int i = 0; i < N.length; i++){
			flag = true;
			tmpN = 1;
			while(flag){
				if( tmpN * Mi[i] % m[i] == 1 ){
					N[i] = tmpN;
					flag = false;
				}else
					tmpN++;
			}
		}
		return N;
	}
}

public class PicEncryptionCRTDemo{
	public static void main(String[] arg){
		if(arg.length < 1){
			System.out.println("Usage: java <classname> <filename>");
			return;
		}

		int[] m = {223,53,97,29};
		PicEncryptionCRT pec = new PicEncryptionCRT();
		try{
			File pic = new File(arg[0]);
			BufferedImage bi = ImageIO.read(pic);

			String[] filename = {"E_0Image.jpg","E_1Image.jpg","E_2Image.jpg","E_3Image.jpg"};
			pec.fileEncrypt(bi, m);
			pec.fileDecrypt(filename, m);
		}catch(IOException e){
			e.printStackTrace();
		}
	}
}