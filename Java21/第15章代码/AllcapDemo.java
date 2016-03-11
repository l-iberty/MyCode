import java.io.*;
import java.nio.file.*;

public class AllcapDemo{
	public static void main(String[] arg){
		if(arg.length < 1){
			System.out.println("Use command-argument");
			System.exit(-1);
		}
		
		Allcap cap = new Allcap(arg[0]);
		cap.convert();
	}
}

class Allcap{
	String sourceName;
	
	Allcap(String sourceArg){
		sourceName = sourceArg;
	}
	
	void convert(){
		try{
			Path source = FileSystems.getDefault().getPath(sourceName);
			Path tmp = FileSystems.getDefault().getPath("tmp" + sourceName);
			
			FileReader fr = new FileReader(sourceName);
			BufferedReader bufin = new BufferedReader(fr);
			
			FileWriter fw = new FileWriter("tmp" + sourceName);
			BufferedWriter bufout = new BufferedWriter(fw);
			
			int in;
			char inchar;
			char upper;
			boolean eof = false;
			
			while(!eof){
				in = bufin.read();
				inchar = (char)in;
				if(in == -1)
					eof = true;
				else{
					upper = Character.toUpperCase(inchar);
					bufout.write(upper);
				}	
			}
			
			bufin.close();
			bufout.close();
			
			Files.delete(source);
			Files.move(tmp, source);
		}catch(IOException|SecurityException e){
			System.out.println(e.getMessage());
		}
	}
}