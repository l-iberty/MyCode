import java.io.*;


public class HexReader2{
	public static void main(String[] arg){
		String tmpFile = HexReader2.CutSpace("Hex_HexReader.txt");
		
		try( FileReader fr = new FileReader(tmpFile);
		     BufferedReader bufr = new BufferedReader(fr);
			 FileWriter fw = new FileWriter("Hex_HexReader2.txt");
			 BufferedWriter bufw = new BufferedWriter(fw); ){
			
			int incount, hexin;
			String tmpstr;
			char[] cbuf = new char[2];
			boolean eof = false;
			
			while(!eof){
				incount = bufr.read(cbuf, 0, cbuf.length);
				
				if(incount < 2)
					eof = true;
				else {
					tmpstr = String.valueOf(cbuf);
					hexin = Integer.parseInt(tmpstr, 16);
					bufw.write(hexin + " ");
				}	
			}
			
			bufr.close();
			bufw.close();
			
		}catch(IOException e){
			System.out.println(e);
		}
	}
	
	private static String CutSpace(String sourceName){
		String tmpName = "TEMP.txt";
		
		try( FileReader fr = new FileReader(sourceName);
		     BufferedReader bufr = new BufferedReader(fr);
			 FileWriter fw = new FileWriter(tmpName);
			 BufferedWriter bufw = new BufferedWriter(fw); ){
			
			int in;
			boolean eof = false;
			
			while(!eof){
				in = bufr.read();
				if(in == -1)
					eof = true;
				else if(in == 32)
					continue;
				else
					bufw.write(in);
			}
			bufr.close();
			bufw.close();
			
			return tmpName;
			
		}catch(IOException e){
			System.out.println(e.getMessage());
			return null;
		}
	}
}