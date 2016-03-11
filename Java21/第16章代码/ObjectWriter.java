import java.io.*;
import java.util.*;

public class ObjectWriter{
	public static void main(String[] arg){
		Message msg = new Message();
		String author = "Sam";
		String recipient = "Shorlock";
		String[] letter = {"you", "fucking", "motherfucker"};
		
		Date now = new Date();
		
		msg.writeMessage(author, recipient, letter);
		try{
			FileOutputStream fo = new FileOutputStream("Message.obj");
			ObjectOutputStream oo = new ObjectOutputStream(fo);
			
			oo.writeObject(msg);
			System.out.print("Object created successfully");
		}catch(IOException e){
			System.out.print(e);
		}
	}
}

class Message implements Serializable{
	transient int lineCount; // ObjectReader 的此项输出将会变为0，而不再是3
	String from, to;
	String[] text;
	
	void writeMessage(String infrom, String into, String[] intext){
		lineCount = intext.length;
		from = infrom;
		to = into;
		text = intext;
	}
}