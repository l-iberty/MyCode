import java.io.*;

public class SourceWriter{
	public static void main(String[] arg){
		try( FileReader fileread = new FileReader("SourceWriter.java");
             BufferedReader buffread = new BufferedReader(fileread);
		     FileWriter filewrite = new FileWriter("SourceWriter.txt");
		     BufferedWriter buffwrite = new BufferedWriter(filewrite); ){
			
			int in;
			char inchar;
			boolean eof = false;
			while(!eof){
				in = buffread.read();
				inchar = (char)in;
				if(in == -1)
					eof = true;
				else{
					buffwrite.write(inchar);
					System.out.print(inchar);
				}
					
			}
			
			buffread.close();
			buffwrite.close();
			
		}catch(IOException e){
			System.out.println(e.toString());
		}
	}
}