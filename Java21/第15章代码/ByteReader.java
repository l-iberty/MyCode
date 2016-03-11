import java.io.*;

public class ByteReader{
	public static void main(String[] arg){
		try( FileInputStream file = new FileInputStream("ByteReader.java") ){
			
			boolean eof = false;
			int count = 0;
			
			while(!eof){
				int input = file.read();
				System.out.print(input + " ");
				if(input == -1)
					eof = true;
				else
					count++;
			}
			file.close();
			System.out.println("\nByte read:" + count);
		}catch(IOException e){
			System.out.println(e.getMessage());
		}
	}
}