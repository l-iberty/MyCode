import javax.swing.*;

public class Input extends JFrame{
	String response;
	public Input(){
		this.response = JOptionPane.showInputDialog(null,
		                "Enter username:",
						"Input information",
						JOptionPane.QUESTION_MESSAGE);
	}
	
	public static void main(String[] arg){
		Input in = new Input();
		System.out.println(in.response); // returns what the user enters.
	}
}