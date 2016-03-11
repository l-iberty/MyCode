import java.net.*;
import java.io.*;

public class WebRead{
	public static void main(String[] arg){
		
		try{
			URL page = new URL("http://www.uestc.edu.cn/");
			HttpURLConnection con = (HttpURLConnection) page.openConnection();
			con.connect();  /* 
			                   URL对象用openConnection()打开连接；获得URLConnection类对象，
			                   类型转换后再用HttpURLConnection类对象的connect（）方法进行连接
		                    */
			InputStreamReader input = new InputStreamReader( (InputStream)con.getContent() );
			BufferedReader bufr = new BufferedReader(input);
			FileWriter output = new FileWriter("UESTC.html");
			BufferedWriter bufw = new BufferedWriter(output);
			
			String str;
			do{
				str = bufr.readLine();
				bufw.write(str);
				bufw.newLine();
			}while(str != null);
			
			bufr.close();
			bufw.close();
			
		}catch(MalformedURLException mue){
			System.out.println("URL Error:" + mue.getMessage());
		}catch(IOException ioe){
			System.out.println("IO Error:" + ioe.getMessage());
		}catch(NullPointerException npe){
			System.out.println("Program terminated! File \"UESTC.html\" saved successfully!");
		}
	}
}