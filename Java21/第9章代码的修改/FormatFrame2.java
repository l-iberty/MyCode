import javax.swing.*;

public class FormatFrame2 extends JFrame{
	String[] format = {"Atem", "Rss 0.92", "RSS 1.00", "RSS 2.00"};
	JComboBox combo = new JComboBox();
	
	public FormatFrame2(){
		super("Choose an Output Format");
		setSize(300,120);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JPanel panel = new JPanel();
		JLabel chooseLable = new JLabel("choose an output format:");
		
		panel.add(chooseLable);
		for(int i = 0; i < format.length; i++)
			combo.addItem(format[i]);
		
		this.add(panel);
		setVisible(true);
		
	}
	
	public static void main(String[] arg){
		try{
			UIManager.setLookAndFeel("com.sun.java.swing.plaf.nimbus.NimbusLookAndFeel");
		}catch(Exception e){
			System.out.println(e.getMessage());
		}
		
		FormatFrame2 fm = new FormatFrame2();
	}
}