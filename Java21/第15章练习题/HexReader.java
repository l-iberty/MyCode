import java.io.*;

// ���ļ��е��ֽڶ�ȡ��������ת��Ϊʮ���������Ϊ���ļ��������пո�ָ�

public class HexReader{
	public static void main(String[] arg){
		try( FileInputStream fr = new FileInputStream("HexReader.java");
		     BufferedInputStream bufr = new BufferedInputStream(fr);
			 FileWriter fw = new FileWriter("Hex_HexReader.txt");
			 BufferedWriter bufw = new BufferedWriter(fw); ){
			
			int in;
			String hexin;
			boolean eof = false;
			
			while(!eof){
				in = bufr.read();
				if(in == -1)
					eof = true;
				else{
					hexin = Integer.toHexString(in);
					bufw.write(hexin + " ");
				}
			}
			bufr.close();
			bufw.close();
			
		}catch(IOException e){
			System.out.println(e);
		}
	}
}