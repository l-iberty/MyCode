import java.io.*;
import java.util.*;

public class ObjectReader{
	public static void main(String[] arg){
		try{
			FileInputStream fr = new FileInputStream("Message.obj");
			ObjectInputStream obr = new ObjectInputStream(fr);
			
			Message msg = (Message)obr.readObject();
			System.out.println("lineCount: " + msg.lineCount);
			System.out.println("from: " + msg.from);
			System.out.println("to:" + msg.to);
			System.out.println("text:" + Arrays.toString(msg.text));
		}catch(Exception e){
			System.out.println(e);
		}
	}
}