// 如何将多个对象序列化进同一个文件？
// 方法就是将对象们装进一个数组，把这个数组序列化，
// 读取的时候直接将整个数组读取出来

import java.io.*;
import java.util.Arrays;

public class SerializationDemo{
	
	public static void main(String[] arg){
		Data[] dataRef = new Data[8];
		Data tmpdata;
		Data[] dataArray = new Data[dataRef.length];
		
		/* for(int i = 0; i < dataRef.length; i++){
			dataRef[i] = new Data(i);
			try(FileOutputStream fo = new FileOutputStream("msg.dat", true);
				ObjectOutputStream oo = new ObjectOutputStream(fo);){
			
				oo.writeObject(dataRef[i]);
				oo.close();
				System.out.println("save");
			}catch(IOException e){
				System.out.println(e.getMessage());
			}
		} */
		
		for(int i = 0; i < dataRef.length; i++)
			dataRef[i] = new Data(i);
		
		try(FileOutputStream fo = new FileOutputStream("msg.dat");
			ObjectOutputStream oo = new ObjectOutputStream(fo);){
		
			oo.writeObject(dataRef);
			oo.close();
			System.out.println("save");
		}catch(IOException e){
			System.out.println(e.getMessage());
		}
		
		try(FileInputStream fi = new FileInputStream("msg.dat");
			ObjectInputStream oi = new ObjectInputStream(fi);){
			
			dataArray = (Data[])oi.readObject();
			oi.close();
			System.out.println("Open");
		}catch(Exception e){
			System.out.println("Error: " + e.getClass().getName());
		}
		
		for(int i = 0; i < dataArray.length; i++)
			System.out.println("data = " + dataArray[i].data);
	
		/* for(int i = 0; i < dataRef.length; i++){
			try(FileInputStream fi = new FileInputStream("msg.dat");
				ObjectInputStream oi = new ObjectInputStream(fi);){
				
				tmpdata = (Data)oi.readObject();
				System.out.println("data = " + tmpdata.data);
				oi.close();
				System.out.println("Open");
			}catch(Exception e){
				System.out.println(e.getMessage());
			}
		} */
		
		/* try(FileInputStream fi = new FileInputStream("msg.dat");
			ObjectInputStream oi = new ObjectInputStream(fi);){
			
			for(int i = 0; i < dataRef.length; i++){
				tmpdata = (Data)oi.readObject();
				System.out.println("data = " + tmpdata.data);
			}
			
			oi.close();
		}catch(Exception e){
			System.out.println(e.getMessage());
		} */
		
	}
}

class Data implements Serializable{
	public int data;
	public Data(int data){
		this.data = data;
	}
}