import javax.swing.*;

public class ProgressMonitor2 extends JFrame{
	
	JProgressBar current;
	JTextField numtext;
	int num;
	
	public ProgressMonitor2(){
		super("Progress Monitor");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setSize(205, 148);
		
		current = new JProgressBar(0, 20000);
		current.setValue(0);
		current.setStringPainted(true);
		
		numtext = new JTextField( "" + num, 10);
		
		JPanel pane = new JPanel();
		pane.add(current);
		pane.add(numtext);
		
		add(pane);
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
		for( num = 0; num < 20000+1; num++ ){
			current.setValue(num);
			numtext.setText("" + num);
			try{
				Thread.sleep(1);
			}catch(InterruptedException e){
				// do nothing
			}
		}
	}
	
	public static void main(String[] arg){
		ProgressMonitor2 pm = new ProgressMonitor2();
		pm.iterator();
	}
}