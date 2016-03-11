import javax.swing.*;

public class Confirm extends JFrame{
	/* public Confirm(){
		int response = JOptionPane.showConfirmDialog(null,
		            "try again?",
					"file error",
					JOptionPane.YES_NO_OPTION,
					JOptionPane.ERROR_MESSAGE);
	} */
	
	public static void main(String[] arg){
		// Confirm con = new Confirm();
		int response = JOptionPane.showConfirmDialog(null,
		            "try again?",
					"file error",
					JOptionPane.YES_NO_OPTION,
					JOptionPane.ERROR_MESSAGE);
		System.out.println(response); // returns -1
	}
}