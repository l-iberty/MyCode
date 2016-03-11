public class ZipCode{
	private long zipCode;
	
	
	/* 存取器方法公有，以便任何类都能正确设置或读取私有变量 */
	
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