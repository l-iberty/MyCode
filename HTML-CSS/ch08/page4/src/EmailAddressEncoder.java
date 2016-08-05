import java.io.*;

class EmailAddressEncoderDemo{
	private String EmailAddress;

	public EmailAddressEncoderDemo(String EmailAddress){
		this.EmailAddress = EmailAddress;
	}

	public String getCiphertext(){
		StringBuilder ciphertext = new StringBuilder();
		int ch;
		String tmpMsg;

		for(int i = 0;i < this.EmailAddress.length();i++){
			ch = (int)this.EmailAddress.charAt(i);
			tmpMsg = "&#" + ch + ";";
			ciphertext.append(tmpMsg);
		}

		return ciphertext.toString();
	}
}

class Text{
	String msg;

	public Text(String msg){
		this.msg = msg;
	}

	public boolean writeFile(){
		try(FileWriter fw = new FileWriter("ciphertext.txt");
			BufferedWriter bw = new BufferedWriter(fw);){

			bw.write(this.msg);
			bw.close();

		}catch(IOException e){
			System.out.println("ERROR:" + e.getMessage());
			return false;
		}
		return true;
	}
}

public class EmailAddressEncoder{
	public static void main(String[] arg){
		if(arg.length < 1)
			System.out.println("Usage: java <classname> <EmailAddress>");
		else{
			String ciphertext;
			EmailAddressEncoderDemo encoder = new EmailAddressEncoderDemo(arg[0]);
			ciphertext = encoder.getCiphertext();
			Text text = new Text(ciphertext);

			if(text.writeFile())
				System.out.println(ciphertext);
		}
	}
}