import java.io.*;

public class ConsoleInput{
	public static String readLine(){
		StringBuilder response = new StringBuilder();
		try(BufferedInputStream buff = new BufferedInputStream(System.in)){
			
			int in;
			char inchar;
			
			do{
				in = buff.read();
				inchar = (char)in;
				if( (in != -1)&&(in != '\n')&&(in != '\r') ){
					response.append(inchar);
				}
			}while( (in != -1)&&(in != '\n')&&(in != '\r') );
			
			buff.close();
			return response.toString();
			
		}catch(IOException e){
			System.out.println(e.toString());
			return null;
		}
	}
	
	public static void main(String[] arg){
		System.out.println(ConsoleInput.readLine());
	}
}