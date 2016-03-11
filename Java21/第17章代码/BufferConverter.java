import java.nio.*;
import java.nio.charset.*;
import java.nio.channels.*;
import java.io.*;

public class BufferConverter{
	public static void main(String[] arg){
		try{
			String data = "Stdio.java";
			FileInputStream inData = new FileInputStream(data);
			FileChannel inChannel = inData.getChannel();
			long inSize = inChannel.size();
			ByteBuffer source = ByteBuffer.allocate((int)inSize);
			inChannel.read(source, 0);
			
			source.position(0);
			System.out.println("Original byte date:");
			while(source.remaining() > 0)
				System.out.print(source.get() + " ");
			
			source.position(0);
			Charset ASCIIset = Charset.forName("US-ASCII");
			CharsetDecoder decoder = ASCIIset.newDecoder();
			CharBuffer destination = ASCIIset.decode(source);
			
			destination.position(0);
			System.out.println("\n\nNew Character data:");
			while(destination.remaining() > 0)
				System.out.print(destination.get());
		}catch(IOException e){
			System.out.println(e);
		}
	}
}