import java.awt.*;
import java.io.*;
import java.util.*;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;

class PictureWriter{
	public int[][] getRGB(BufferedImage image){
		int[][] rgb = new int[image.getWidth()][image.getHeight()];

		if(image != null){
			for(int x = image.getMinX(); x < image.getWidth(); x++)
				for(int y = image.getMinY(); y < image.getHeight(); y++)
					rgb[x][y] = image.getRGB(x, y);
		}
		return rgb;
	}

	public void paint(int[][] rgb, int width, int height) throws IOException{
		BufferedImage image = new BufferedImage(width, height,
			BufferedImage.TYPE_INT_RGB); // 表示创建的图像具有合成整数像素的8位RGB图像
		Graphics2D graph = (Graphics2D) image.getGraphics();
		// graph对象的行为将映射到image对象
		int pixel;

		for(int x = image.getMinX(); x < width; x++)
			for(int y = image.getMinY(); y < height; y++){
				pixel = rgb[x][y];
				// 获取原图x,y处的RGB
				Color color = new Color(pixel);
				graph.setColor(color);
				graph.drawLine(x, y, x+1, y+1);
				// 绘制一个像素点
			}

		File picture = new File("Image.jpg");
		ImageIO.write(image, "jpg", picture);
	}
}

public class PictureWriterDemo{
	public static void main(String[] arg){
		if(arg.length < 1){
			System.out.println("Usage: java <classname> <filename>");
			return;
		}

		PictureWriter pec = new PictureWriter();
		try{
			File pic = new File(arg[0]);
			BufferedImage image = ImageIO.read(pic);
			int[][] rgb = new int[image.getWidth()][image.getHeight()];

			rgb = pec.getRGB(image);
			pec.paint(rgb, image.getWidth(), image.getHeight());
		}catch(IOException e){
			e.printStackTrace();
		}
	}
}