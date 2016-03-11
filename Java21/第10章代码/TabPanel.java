import javax.swing.*;
import java.awt.*;

public class TabPanel extends JFrame{
	
	public TabPanel(){
		super("Tabbed Panes");
		setSize(480, 218);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLookAndFeel();
		
		JPanel mainSetting = new JPanel();
		JPanel adSetting = new JPanel();
		JPanel pySetting = new JPanel();
		JPanel emSetting = new JPanel();
		
		JTabbedPane tab = new JTabbedPane();
		tab.addTab("Main", mainSetting);
		tab.addTab("Advanced", adSetting);
		tab.addTab("Privacy", pySetting);
		tab.addTab("E-Mail", emSetting);
		
		add(tab);
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
		TabPanel tabpanel = new TabPanel();
	}
}