import java.io.*;

public class PrimeReader{
	public static void main(String[] arg){
		try( FileInputStream file = new FileInputStream("PrimeNumber.dat");
		     BufferedInputStream buff = new BufferedInputStream(file);
			 DataInputStream data = new DataInputStream(buff);){
			
			int in;
			try{
				while(true){
					in = data.readInt();
					System.out.print(in + " ");
				}
			}catch(EOFException eof){
				data.close();
			}
			
		}catch(IOException ioe){
			System.out.println(ioe.toString());
		}
	}
}