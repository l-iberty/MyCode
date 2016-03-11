import java.io.*;
import java.net.*;
import java.util.*;

public class TimeServer extends Thread{
	ServerSocket sock;
	
	public TimeServer(){
		super();
		try{
			sock = new ServerSocket(4415);
			System.out.println("TimeServer running......");
		}catch(IOException e){
			System.out.println(e);
		}
	}
	
	public void run(){
		Socket client = null;
		
		while(true){
			if(sock == null)
				return;
			
			try{
				client = sock.accept();
				BufferedOutputStream bos = new BufferedOutputStream(client.getOutputStream());
				PrintWriter os = new PrintWriter(bos, false);
				
				Date now = new Date();
				os.println("Time: " + now);
				os.flush();
				
				os.close();
				client.close();
			}catch(IOException e){
				System.out.println(e);
			}
		}
	}
	
	public static void main(String[] arg){
		TimeServer server = new TimeServer();
		server.start();
	}
}