import javax.swing.*;
import java.awt.*;

public class Stacker extends JFrame{
	
	public Stacker(){
		super("Stacker");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setSize(400, 150);
		setLookAndFeel();
		
		JPanel pane = new JPanel();
		BoxLayout horizontal = new BoxLayout(pane, BoxLayout.X_AXIS);
		pane.setLayout(horizontal);
		
		JButton save = new JButton("Save");
		JButton load = new JButton("Load");
		JButton delete = new JButton("Delete");
		JButton print = new JButton("Print");
		pane.add(save);
		pane.add(load);
		pane.add(delete);
		pane.add(print);
		
		JTextArea text = new JTextArea(3, 30);
		JScrollPane scroll = new JScrollPane(text);
								 
		FlowLayout flow = new FlowLayout();
		setLayout(flow); // 框架中有pane,scroll两个组件，若不用FlowLayout，pane将被scroll覆盖而不可见
		add(pane);
		add(scroll);
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
		Stacker frame = new Stacker();
	}
}