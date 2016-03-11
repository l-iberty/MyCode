import java.io.*;

// Source file will not be gone when the program terminates.

public class ByteCover{
	public static void main(String[] arg){
		try( FileInputStream fr = new FileInputStream("SourceWriter.txt");
		     BufferedInputStream bufr = new BufferedInputStream(fr);
			 FileOutputStream fw = new FileOutputStream("SourceWriter_Covered.txt");
			 BufferedOutputStream bufw = new BufferedOutputStream(fw); ){
			
			int in, count = 0;
			boolean eof = false;
			
			while(!eof){
				in = bufr.read();
				if(in != -1){
					count++;
					in = 0;
					bufw.write(in);
				}
				else
					eof = true;
			}
			
			bufr.close();
			bufw.close();
			
			System.out.println("Byte: " + count);
		}catch(IOException e){
			System.out.println(e);
		}
	}
}