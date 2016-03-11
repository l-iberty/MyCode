import javax.swing.*;

public class Option extends JFrame{
	String[] gender = {"male", "famale", "not sure", "hard to say"};
	
	public Option(){
		JOptionPane.showOptionDialog(null,
		            "what is you gender?",
					"Option",
					0,
					JOptionPane.QUESTION_MESSAGE,
					null,
					gender,
					gender[3]);
	}
	
	public static void main(String[] arg){
		Option op = new Option();
	}
}