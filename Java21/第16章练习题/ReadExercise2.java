import java.io.*;

public class ReadExercise2{
	public static void main(String[] arg){
		try{
		    FileInputStream fr = new FileInputStream("TempClass.obj");
		    ObjectInputStream objr = new ObjectInputStream(fr);
		
		    TempClass temp = (TempClass) objr.readObject();
		
		    System.out.println("a = " + temp.a);
		    System.out.println("str = " + temp.str);
	    }catch(Exception e){
		    System.out.println(e);
	    }
	}
}