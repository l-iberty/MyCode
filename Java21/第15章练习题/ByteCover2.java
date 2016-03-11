import java.io.*;
import java.nio.file.*;

// Source file will be gone when the program terminates.

public class ByteCover2{
	public static void main(String[] arg){
		try{
			
		    Path source = FileSystems.getDefault().getPath("SourceWriter.txt");
		    Path temp = FileSystems.getDefault().getPath("Tmp");
		
		    FileInputStream fr = new FileInputStream("SourceWriter.txt");
		    BufferedInputStream bufr = new BufferedInputStream(fr);
		
		    FileOutputStream fw = new FileOutputStream("Tmp");
		    BufferedOutputStream bufw = new BufferedOutputStream(fw);
		
		    int in, count = 0;
		    boolean eof = false;
		    while(!eof){
			    in = bufr.read();
			    if(in == -1)
				    eof = true;
			    else{
				    in = 0;
				    bufw.write(in);
				    count++;
			    }
		    }
		
		    bufr.close();
		    bufw.close();
			
			System.out.println("Byte: " + count);
		
		    Files.delete(source);
		    Files.move(temp, source);
	    }catch(IOException|SecurityException e){
		    System.out.println(e);
	    }
	}
}