import java.util.Arrays;

class CRT{
	public long[] encrypt(long c, long[] m){
		long[] a = new long[m.length];
		for(int i = 0; i < m.length; i++)
			a[i] = c % m[i];
		return a;
	}
	
	public long decrypt(long[] a, long[] m){
		long x = 0, M = 1;
		long[] N;
		long[] Mi = new long[a.length];
		
		for(int i = 0; i < m.length; i++)
			M *= m[i];
		for(int i = 0; i < Mi.length; i++)
			Mi[i] = M / m[i];
		
		N = calc_N(m, Mi);
		for(int i = 0; i < a.length; i++)
			x += a[i]*N[i]*Mi[i];
		
		return x % M;
	}
	
	private long[] calc_N(long m[], long Mi[]){
		long[] N = new long[m.length];
		long tmpN;
		boolean flag;
		
		for(int i = 0; i < N.length; i++){
			flag = true;
			tmpN = 1;
			while(flag){
				if( tmpN * Mi[i] % m[i] == 1 ){
					N[i] = tmpN;
					flag = false;
				}else
					tmpN++;
			}
		}
		return N;
	}
}

public class CRTDemo{
	public static void main(String[] arg){
		CRT crt = new CRT();
		long[] m = {15,17,19,23,29,97};
		long[] Mi;
		long[] a;
		long c;
		
		a = crt.encrypt(9438, m);
		System.out.println("a = " + Arrays.toString(a));
		c = crt.decrypt(a, m);
		System.out.println("c = " + c);
		/* long[] A = {15,70};
		long[] B = {29,97};
		c = crt.decrypt(A, B);
		System.out.println("c = " + c); */
	}
}