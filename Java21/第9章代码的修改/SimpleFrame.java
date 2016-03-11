import javax.swing.*;
import java.awt.*;

public class SimpleFrame extends JFrame{
	public SimpleFrame(){
		super("Frame Title");
		setSize( new Dimension(300,100) );
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		try{
			UIManager.setLookAndFeel("com.sun.java.swing.plaf.nimbus.NimbusLookAndFree");
		}catch(Exception e){
			//do nothing
		
		}
		setVisible(true);
	}
	
	public static void main(String[] arg){
		SimpleFrame sf = new SimpleFrame();
	}
}