import javax.swing.*;
import java.awt.*;

public class Alphabet extends JFrame{
	
	public Alphabet(){
		super("Alphabet");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setSize(360, 120);
		setLookAndFeel();
		// FlowLayout lm = new FlowLayout(FlowLayout.LEFT, 30, 10);
		// lm.setVgap(10);
		// lm.setHgap(30);
		
		JButton a = new JButton("App");
		JButton b = new JButton("Bike");
		JButton c = new JButton("Contented");
		JButton d = new JButton("Delight");
		JButton e = new JButton("Entail");
		JButton f = new JButton("Foremost");
		JButton g = new JButton("Gigantic");
		
		JPanel pane = new JPanel();
		pane.add(a);
		pane.add(b);
		pane.add(c);
		pane.add(d);
		pane.add(e);
		pane.add(f);
		pane.add(g);
		
		// 由于使用了面板JPanel，将默认使用FlowLayout
		
		// pane.setLayout(lm);
		add(pane);
		setVisible(true);
	}
	
	private void setLookAndFeel(){
		try{
			UIManager.setLookAndFeel("com.sun.java.swing.plaf.nimbus.NimbusLookAndFeel");
			SwingUtilities.updateComponentTreeUI(this);
		}catch(Exception e){
			System.out.println(e.getMessage());
		}
	}
	
	public static void main(String[] arg){
		Alphabet frame = new Alphabet();
	}
}