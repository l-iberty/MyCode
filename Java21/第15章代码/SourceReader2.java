import java.io.*;

public class SourceReader2{
	public static void main(String[] arg){
		try( FileReader file = new FileReader("SourceReader2.java");
		     BufferedReader buff = new BufferedReader(file); ){
			
			boolean eof = false;
			while(!eof){
				String line = buff.readLine();
				if(line == null)
					eof = true;
				else
					System.out.println(line);
			}
			
			buff.close();
		}catch(IOException e){
			System.out.println(e.getMessage());
		}
	}
}