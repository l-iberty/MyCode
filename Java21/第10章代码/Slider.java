import javax.swing.*;
import java.awt.event.*;

public class Slider extends JFrame{
	JSlider slider = new JSlider( SwingConstants.VERTICAL, 0, 200, 100 );
	
	public Slider(){
		super("SLIDER");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JPanel panel = new JPanel();
		slider.setMajorTickSpacing(10);
		slider.setMinorTickSpacing(2);
		slider.setPaintTicks(true);
		slider.setPaintLabels(true);
		
		panel.add(slider);
		add(panel);
		pack();
		setLookAndFeel();
		setVisible(true);
	}
	
	private void setLookAndFeel(){
		try{
			UIManager.setLookAndFeel("com.sun.java.swing.plaf.nimbus.NimbusLookAndFeel");
			// SwingUtilities.updateComponentTreeUI(this);
		}catch(Exception e){
			System.out.println(e.getMessage());
		}
	}
	
	public static void main(String[] arg){
		Slider sl = new Slider();
	}
}