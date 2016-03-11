public class ReadSet{
	public static void main(String[] arg){
		ZipCode pz = new ZipCode();
		
		pz.setZipCode(23455);
		
		System.out.println("Private variable ZipCode = " + pz.gZipCode());
	}
}