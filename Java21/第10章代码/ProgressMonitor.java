import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class ProgressMonitor extends JFrame{
	
	JProgressBar current;
	
	public ProgressMonitor(){
		super("Progress Monitor");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setSize(205, 68);
		setLayout(new FlowLayout());
		
		current = new JProgressBar(0, 20);
		current.setValue(0);
		current.setStringPainted(true);
		
		add(current);
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
	
	public void iterator(){
		for( int num = 0; num < 20+1; num++ ){
			current.setValue(num);
			try{
				Thread.sleep(1000);
			}catch(InterruptedException e){
				// do nothing
			}
		}
	}
	
	public static void main(String[] arg){
		ProgressMonitor pm = new ProgressMonitor();
		pm.iterator();
	}
}