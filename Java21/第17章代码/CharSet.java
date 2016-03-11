import java.nio.*;
import java.nio.charset.*;

public class CharSet{
	public static void main(String[] arg){
		byte[] data = new byte[256];
		for(int n = 0; n < data.length; n++)
			data[n] = (byte)n;
		ByteBuffer dataBuf = ByteBuffer.wrap(data);
		char[] tmp = {'a','b','c','d','e','A','B','C','D','E'};
		CharBuffer tmpBuf = CharBuffer.wrap(tmp);
		
		try{
			Charset set = Charset.forName("ISO-8859-1");
		    CharsetDecoder decoder = set.newDecoder();
		    CharsetEncoder encoder = set.newEncoder();
		
		    CharBuffer dataChar = decoder.decode(dataBuf);
		    ByteBuffer tmpByte = encoder.encode(tmpBuf);
		
		    System.out.println("dataChar:");
		    while(dataChar.remaining() > 0)
			    System.out.print(dataChar.get() + " ");
		
		    System.out.println("\ntmpByte:");
		    while(tmpByte.remaining() > 0)
			    System.out.print(tmpByte.get() + " ");
		}catch(CharacterCodingException e){
			System.out.println(e);
		}
	}
}