import java.awt.event.*;
import java.awt.*;
import javax.swing.*;

public class TitleChanger extends JFrame implements ActionListener{
	JButton b1, b2;
	
	public TitleChanger(){
		super("TitleChanger");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLookAndFeel();
		setLayout( new FlowLayout() );
		
		b1 = new JButton("rosencrantz");
		b2 = new JButton("guildenstern");
		b1.addActionListener(this);
		b2.addActionListener(this);
		
		add(b1);
		add(b2);
		
		pack();
		setVisible(true);
	}
	
	public void actionPerformed(ActionEvent event){
		Object source = event.getSource();
		
		if( source == b1 ){
			setTitle("rosencrantz");
		}
		else if( source == b2 ){
			setTitle("guildenstern");
		}
		
		repaint();
	}
	
	private void setLookAndFeel(){
		try{
			UIManager.setLookAndFeel("com.sun.java.swing.plaf.nimbus.NimbusLookAndFeel");
			SwingUtilities.updateComponentTreeUI(this);
		}catch(Exception e){
			// do nothing
		}
	}
	
	public static void main(String[] arg){
		TitleChanger frame = new TitleChanger();
	}
}