import java.io.*;

public class SourceReader{
	public static void main(String[] arg){
		try( FileReader file = new FileReader("SourceReader.java");
             BufferedReader buff = new BufferedReader(file); ){
			
			int in;
			char inchar;
			boolean eof = false;
			while(!eof){
				in = buff.read();
				inchar = (char)in;
				if(in == -1)
					eof = true;
				else
					System.out.print(inchar);
			}
			buff.close();
			
		}catch(IOException e){
			System.out.println(e.getMessage());
		}
	}
}