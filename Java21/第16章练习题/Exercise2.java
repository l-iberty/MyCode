import java.io.*;

public class Exercise2{
	public static void main(String[] arg){
		
		try{
			Class tmp = TempClass.class;
			TempClass temp = (TempClass) tmp.newInstance();
			
			FileOutputStream fw = new FileOutputStream("TempClass.obj");
			ObjectOutputStream objw = new ObjectOutputStream(fw);
			
			objw.writeObject(temp);
			objw.close();
			
			System.out.println("Object created successfully.");
		}catch(IOException|InstantiationException|IllegalAccessException e){
			System.out.println(e);
		}
	}
}

class TempClass implements Serializable{
	int a = 1;
	String str = "Java";
}