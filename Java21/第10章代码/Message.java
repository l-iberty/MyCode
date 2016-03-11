import javax.swing.*;

public class Message extends JFrame{
	public Message(){
		JOptionPane.showMessageDialog(null,
		            "Sure to delate?",
					"Message",
					JOptionPane.INFORMATION_MESSAGE);
	}
	
	public static void main(String[] arg){
		Message msg = new Message();
	}
}