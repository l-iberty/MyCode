import javax.swing.*;

public class Subscription extends JFrame{
	String[] sub = {"arraylist", "stack", "hashmap", "bitset", "java", "c#", "pascal", "php", "javaweb", "obj-c"};
	JList sublist = new JList(sub);
	
	public Subscription(){
		super("Subscriprion");
		setSize(150,355);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JPanel panel = new JPanel();
		JLabel subLable = new JLabel("RSS Subscriprion:");
		panel.add(subLable);
		
		sublist.setVisibleRowCount(6);
		
		JScrollPane subScroll = new JScrollPane(sublist,
		                                         ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS,
										         ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);
		panel.add(subScroll);
		panel.add(sublist);

        this.add(panel);
		setVisible(true);
     		
        
	}
	
	public static void main(String[] arg){
		try{
			UIManager.setLookAndFeel("com.sun.java.swing.plaf.nimbus.NimbusLookAndFeel");
		}catch(Exception e){
			System.out.println(e.getMessage());
		}
		
		Subscription sb = new Subscription();
	}
}