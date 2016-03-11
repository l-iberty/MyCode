import java.nio.*;

public class ByteBufferShow{
	public static void main(String[] arg){
		int count = 10;
		int size = 8;
		int BUFFSIZE = count*size;
		ByteBuffer tmpBuffer = ByteBuffer.allocate(BUFFSIZE);
		
	    double n = 1L;	
		for(int i = 0; i < count; i++)
			tmpBuffer.putDouble(n++);
		
		System.out.println(tmpBuffer.position());
		tmpBuffer.position(0);
		
		for(int j = 0; tmpBuffer.remaining() > 0; j++){
		    System.out.print(tmpBuffer.get());
			if((j+1) % size != 0)
				System.out.print(",");
			if((j+1) % size == 0 && j != 0)
				System.out.print("\n");
		}
	}
}