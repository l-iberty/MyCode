public class ZipCode{
	private long zipCode;
	
	
	/* ��ȡ���������У��Ա��κ��඼����ȷ���û��ȡ˽�б��� */
	
	public void setZipCode(long x){
		if ( ( x >=10000 && x <= 99999 ) || ( x >= 100000000 && x <= 999999999 ) )
			this.zipCode = x;
		else
			System.out.println("Invalid Number!");
	}
	
	public long gZipCode(){
		return zipCode;
	}
}