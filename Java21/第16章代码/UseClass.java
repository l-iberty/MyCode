import java.lang.reflect.*;

public class UseClass{
	public static void main(String[] arg){
		// use "getClass()":
		ObjectReader ptr = new ObjectReader();
		Class ObjectReaderClass = ptr.getClass();
		String name1 = ObjectReaderClass.getName();
		System.out.println("ObjectReaderClass:" + name1);
		
		// use ".class":
		Class ThreadClass = Thread.class;
		String name2 = ThreadClass.getName();
		System.out.println("ThreadClass:" + name2);
		
		// use "forName()":
		try{
			Class JPanelClass = Class.forName("javax.swing.JPanel");
		    String name3 = JPanelClass.getName();
		    System.out.println("javax.swing.JPanel:" + name3);
		}catch(ClassNotFoundException e){
			System.out.println(e);
		}
		
		// array:
		long[] num = {1,2,3,3,4,5,7};
		Class numClass = num.getClass();
		String name4 = numClass.getName();
		System.out.println("numClass:" + name4);
		
		String[][] str = new String[5][4];
		Class strClass = str.getClass();
		String name5 = strClass.getName();
		System.out.println("strClass" + name5);
		
		// use "newInstance()" to create a new object:
		try{
			Class tmp = ObjectReader.class;
		    ObjectReader temp = (ObjectReader) tmp.newInstance();
		    System.out.println("Created an object of class " + tmp.getName());
		}catch(InstantiationException|IllegalAccessException e){
			System.out.println(e);
		}
		
	}
}