import javax.swing.*;

public class FormatFrame extends JFrame{
	JRadioButton[] teams = new JRadioButton[4];
	
	public FormatFrame(){
		super("Choose an Output Format");
		setSize(300,120);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		teams[0] = new JRadioButton("Atom");
		teams[1] = new JRadioButton("RSS 0.92");
		teams[2] = new JRadioButton("RSS 1.00", true);
		teams[3] = new JRadioButton("RSS 2.00", true);
		
		JPanel panel = new JPanel();
		JLabel chooseLable = new JLabel("choose an output format:");
		ButtonGroup choice = new ButtonGroup();
		
		panel.add(chooseLable);
		
		for (int i = 0; i < teams.length; i++){
			panel.add(teams[i]);
			choice.add(teams[i]);
		}
		
		this.add(panel);
		setVisible(true);
		
	}
	
	public static void main(String[] arg){
		try{
			UIManager.setLookAndFeel("com.sun.java.swing.plaf.nimbus.NimbusLookAndFeel");
		}catch(Exception e){
			System.out.println(e.getMessage());
		}
		
		FormatFrame fm = new FormatFrame();
	}
}