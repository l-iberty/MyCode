import javax.swing.*;

public class InputTitle extends JFrame{
	
	public InputTitle(){
		super("Input Title");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setSize(250,360);
		
		String response = JOptionPane.showInputDialog(null, "Enter the title:");
		
		setTitle(response);
		setVisible(true);
	}
	
	public static void main(String[] arg){
		InputTitle it = new InputTitle();
	}
}