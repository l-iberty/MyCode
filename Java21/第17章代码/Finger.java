import java.io.*;
import java.net.*;
import java.util.*;

public class Finger{
	public static void main(String[] arg){
		String user, host;
		
		if((arg.length == 1) && (arg[0].indexOf('@') > -1)){
			StringTokenizer split = new StringTokenizer(arg[0], "@");
			user = split.nextToken();
			host = split.nextToken();
		}else{
			System.out.println("Usage: java Finger user@host");
			return;
		}
		
		try(Socket digit = new Socket(host, 80);
		    BufferedReader bufr = new BufferedReader(new InputStreamReader(digit.getInputStream())); ){
			
			digit.setSoTimeout(20000);
			PrintStream out = new PrintStream(digit.getOutputStream());
			
			String line;
			boolean eof = false;
			while(!eof){
				line = bufr.readLine();
				if(line == null)
					eof = true;
				else
					System.out.println(line);
			}
			digit.close();
			
		}catch(IOException e){
			System.out.println(e);
		}
	}
}