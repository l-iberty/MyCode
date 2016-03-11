import java.io.*;

public class SourceWriter2{
	public static void main(String[] arg){
		try( FileReader fileread = new FileReader("SourceWriter2.java");
             BufferedReader buffread = new BufferedReader(fileread);
		     FileWriter filewrite = new FileWriter("SourceWriter2.txt");
		     BufferedWriter buffwrite = new BufferedWriter(filewrite); ){
		
			boolean eof = false;
			while(!eof){
				String line = buffread.readLine();
				
				if(line == null)
					eof = true;
				else{
					buffwrite.write(line );
					buffwrite.newLine();
					System.out.println(line);
				}
					
			}
			
			buffread.close();
			buffwrite.close();
			
		}catch(IOException e){
			System.out.println(e.toString());
		}
	}
}