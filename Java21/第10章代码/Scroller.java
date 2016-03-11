import javax.swing.*;
import java.awt.*;

public class Scroller extends JFrame{
	public Scroller(){
		super("scroller!");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JTextArea text = new JTextArea(20,30);
		JScrollPane scroller = new JScrollPane(text,
		                            ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS,
									ScrollPaneConstants.HORIZONTAL_SCROLLBAR_AS_NEEDED);
		scroller.setPreferredSize(new Dimension(500,350));
		
		JPanel panel = new JPanel();
		panel.add(scroller);
		
		add(panel);
		pack();
		setLookAndFeel();
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
		Scroller sl = new Scroller();
	}
}