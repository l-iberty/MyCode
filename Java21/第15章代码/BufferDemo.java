import java.io.*;

public class BufferDemo{
	public static void main(String[] arg){
		int start = 0;
		int finish = 255;
		
		if(arg.length > 1){
			start = Integer.parseInt(arg[0]);
			finish = Integer.parseInt(arg[1]);
		}else if(arg.length > 0){
			start = Integer.parseInt(arg[0]); 
		}
		
		ArgStream as = new ArgStream(start, finish);
		System.out.println("\nWriting:");
		
		boolean success = as.writeStream();
		System.out.println("\nReading:");
		boolean readsuccess = as.readStream();
	}
}

class ArgStream{
	int start = 0;
	int finish = 255;
	
	ArgStream(int instart, int infinish){
		start = instart;
		finish = infinish;
	}
	
	boolean writeStream(){
		try( FileOutputStream file = new FileOutputStream("numbers.dat");
		     BufferedOutputStream buff = new BufferedOutputStream(file) ){
			
			for(int out = start; out <= finish; out++){
				buff.write(out);
				System.out.print(out + " ");
			}
			buff.close();
			return true;
		}catch(IOException e){
			System.out.println(e.toString());
			return false;
		}
	}
	
	boolean readStream(){
		try( FileInputStream file = new FileInputStream("numbers.dat");
       		 BufferedInputStream buff = new BufferedInputStream(file)){
			
			boolean eof = false;
			while(!eof){
				int in = buff.read();
				System.out.print(in + " ");
				
				if(in == -1)
					eof = true;
			}
			
			buff.close();
			return true;
		}catch(IOException e){
			System.out.println(e.toString());
			return false;
		}
	}
}