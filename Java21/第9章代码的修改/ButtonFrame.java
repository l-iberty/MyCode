import javax.swing.*;

public class ButtonFrame extends JFrame{
	JButton load = new JButton("Load");
	JButton save = new JButton("Save");
	JButton fuck = new JButton("Fuck");
	
	public ButtonFrame(){
		super("Button Frame");
		setSize(500,500);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JPanel panel = new JPanel();
		panel.add(load);
		panel.add(save);
		panel.add(fuck);
		
		this.add(panel);
		
		try{
			UIManager.setLookAndFeel("com.sun.java.swing.plaf.nimbus.NimbusLookAndFree");
		}catch(Exception e){
			//do nothing
		
		}
		
		setVisible(true);
	}
	
	public static void main(String[] arg){
		ButtonFrame button = new ButtonFrame();
	}
}