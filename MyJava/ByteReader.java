import java.io.*;

public class ByteReader{
	public static void main(String[] arg){
		if(arg.length < 1)
			System.out.println("Usage: java <classname> <filename>");

		try(FileInputStream in = new FileInputStream(arg[0]);
			BufferedInputStream buff = new BufferedInputStream(in);){

			int ch;
			boolean eof = false;
			do{
				ch = buff.read();
				if(ch != -1)
					System.out.print(ch + " ");
				else
					eof = true;
			}while(!eof);
			buff.close();
		}catch(IOException e){
			System.out.println(e.getMessage());
		}
	}
}