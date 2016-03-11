import java.io.*;
import java.util.*;

public class PrimeWriter{
	public static boolean isPrime(int checkNumber){
		double root = Math.sqrt(checkNumber);
		for(int i = 2; i <= root; i++){
			if(checkNumber % i == 0)
				return false;
		}
		return true;
	}
	
	public static void main(String[] arg){
		ArrayList<Integer> list = new ArrayList<>();
		
		
		
		/* for(int number = 2; number < 100; number++){
			if(isPrime(number))
				list.add(new Integer(number));
		} */
		int numberPrime = 0;
		int tmp = 2;
		while(numberPrime < 100){
			if(isPrime(tmp)){
				list.add(new Integer(tmp));
				numberPrime++;
			}
			tmp++;
		}
		
		try( FileOutputStream file = new FileOutputStream("PrimeNumber.dat");
         	 BufferedOutputStream buff = new BufferedOutputStream(file);
			 DataOutputStream data = new DataOutputStream(buff);){
			
			/* for(Iterator i = list.iterator(); i.hasNext();){
				data.writeInt( ((Integer)i.next()).intValue() );
			} */
			for(int count = 0; count < list.size(); count++){
				data.writeInt(list.get(count).intValue());
			}
			
			data.close();
		}catch(IOException e){
			System.out.println(e.toString());
		}
	}
}