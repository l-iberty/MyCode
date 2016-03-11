import java.nio.*;

public class Buffer{
	public static void main(String[] arg){
		int[] tmp = {23,45,33,12,98,67,77,59};
		IntBuffer tmpBuffer = IntBuffer.wrap(tmp);
		IntBuffer tempBuffer = IntBuffer.allocate(tmp.length);
		
		for(int i = 0; i < tmp.length;){
			tempBuffer.put(tmp.length - (++i), tmpBuffer.get()); 
		}
		
		for(int j = 0; tempBuffer.remaining() > 0; j++){
		    System.out.print(tempBuffer.get());
			if(j != tmp.length-1)
				System.out.print(",");
		}
	}
}