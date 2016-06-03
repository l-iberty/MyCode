import java.io.*;
import java.util.Arrays;

class FileEncryptionCRT{
	public void showBytes(String filename){
		try(FileInputStream in = new FileInputStream(filename);
			BufferedInputStream bufin = new BufferedInputStream(in);){

			boolean eof = false;
			int ch;
			do{
				ch = bufin.read();
				if(ch != -1)
					System.out.print(ch + " ");
				else
					eof = true;
			}while(!eof);
			bufin.close();

		} catch(IOException e){
			System.out.println(e.getMessage());
		}
	}

	public void fileEncrypt(String filename, int[] m){
		int i;
		int[] a = new int[m.length];

		try(FileInputStream in = new FileInputStream(filename);
			BufferedInputStream bufin = new BufferedInputStream(in);){

			FileOutputStream[] fw = new FileOutputStream[m.length];
			BufferedOutputStream[] bufw = new BufferedOutputStream[m.length];

			for(i = 0; i < bufw.length; i++){
				fw[i] = new FileOutputStream("E_" + i + filename);
				bufw[i] = new BufferedOutputStream(fw[i]);
			}

			boolean eof = false;
			int ch;
			do{
				ch = bufin.read();
				if(ch != -1){
					for(i = 0; i < m.length; i++){
						a[i] = ch % m[i];
						bufw[i].write(a[i]);
					}
					System.out.println(Arrays.toString(a));
				}
				else
					eof = true;
			}while(!eof);

			bufin.close();
			for(i = 0; i < bufw.length; i++)
				bufw[i].close();

		} catch(IOException e){
			System.out.println(e.getMessage());
		}
	}

	public void fileDecrypt(String[] filename, int[] m){
		int[] cipher = new int[filename.length];
		int i, j;

		try{
			FileInputStream[] in = new FileInputStream[filename.length];
			BufferedInputStream[] bufin = new BufferedInputStream[filename.length];
			FileOutputStream out = new FileOutputStream("Decrypted_file.txt");
			BufferedOutputStream bufout = new BufferedOutputStream(out);

			for(i = 0; i < bufin.length; i++){
				in[i] = new FileInputStream(filename[i]);
				bufin[i] = new BufferedInputStream(in[i]);
			}

			int ch;
			boolean eof = false;
			boolean flag1 = false, flag2 = false;
			do{
				for(j = 0; j < m.length && !flag1; j++){
					for(i = 0; i < bufin.length && !flag2; i++){
						ch = bufin[i].read();
						if(ch != -1)
							cipher[i] = ch;
						else
							flag1 = flag2 = eof = true;
					}
					if(!flag2){
						System.out.println("cipher:" + Arrays.toString(cipher));
						int c = decrypt(cipher, m);
						bufout.write(c);
					}
				}
				
			}while(!eof);
			bufout.close();
			for(i = 0; i < bufin.length; i++)
				bufin[i].close();

		} catch(IOException e){
			System.out.println(e.getMessage());
		}
	}

	private int decrypt(int[] a, int[] m){
		int x = 0, M = 1;
		int[] N;
		int[] Mi = new int[a.length];
		
		for(int i = 0; i < m.length; i++)
			M *= m[i];
		for(int i = 0; i < Mi.length; i++)
			Mi[i] = M / m[i];
		
		N = calc_N(m, Mi);
		for(int i = 0; i < a.length; i++)
			x += a[i]*N[i]*Mi[i];
		
		return x % M;
	}
	
	private int[] calc_N(int m[], int Mi[]){
		int[] N = new int[m.length];
		int tmpN;
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

public class FileEncryptionCRTDemo{
	public static void main(String[] arg){
		if(arg.length < 1)
			System.out.println("Usage: java <classname> <filename>");

		FileEncryptionCRT fec = new FileEncryptionCRT();
		int[] m = {31,37,43};
		System.out.println("Original bytes:");
		fec.showBytes(arg[0]);
		System.out.println("\nEncrypted bytes:");
		fec.fileEncrypt(arg[0], m);

		String[] filename = {"E_0msg.txt", "E_1msg.txt", "E_2msg.txt"};
		fec.fileDecrypt(filename, m);
	}
}