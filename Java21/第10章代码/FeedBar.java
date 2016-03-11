import javax.swing.*;
import java.awt.*;

public class FeedBar extends JFrame{
	
	public FeedBar(){
		super("FeedBar");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JButton load = new JButton("Load");
		JButton save = new JButton("Save");
		JButton subscribe = new JButton("Subscribe");
		JButton delete = new JButton("Delete");
		
		JToolBar tool = new JToolBar();
		tool.add(load);
		tool.add(save);
		tool.add(subscribe);
		tool.add(delete);
		
		JTextArea edit = new JTextArea();
		JScrollPane scroll = new JScrollPane(edit,
		                          ScrollPaneConstants.VERTICAL_SCROLLBAR_AS_NEEDED,
								  ScrollPaneConstants.HORIZONTAL_SCROLLBAR_AS_NEEDED);
		scroll.setPreferredSize(new Dimension(350,450));
		
		BorderLayout bord = new BorderLayout();
		setLayout(bord);
		
		add("South", tool);
		add("Center", scroll);
		
		setLookAndFeel();
		pack();
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
		FeedBar fb = new FeedBar();
	}
}