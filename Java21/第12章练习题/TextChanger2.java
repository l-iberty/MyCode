import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class TextChanger2 extends JFrame implements FocusListener{
	JTextField number1, number2;
	
	public TextChanger2(){
		super("Text Changer");
		setSize(200, 150);
		setLayout(new FlowLayout());
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		number1 = new JTextField(5);
		number2 = new JTextField(5);
		number1.addFocusListener(this);
		number2.addFocusListener(this); 
		
		JPanel pane = new JPanel();
		BoxLayout box = new BoxLayout(pane, BoxLayout.Y_AXIS);
		pane.setLayout(box);
		pane.add(number1);
		pane.add(number2);
		
		add(pane);
		setVisible(true);
	}
	
	public void focusGained(FocusEvent evt){
		int tmp;
		
		try{
			tmp = Integer.parseInt(number1.getText());
			if( tmp < 0 ){
				number1.setText( "" + (-1)*tmp );
			    number1.repaint();
			}
			
			tmp = Integer.parseInt(number2.getText());
			if( tmp < 0 ){
				number2.setText( "" + (-1)*tmp );
			    number2.repaint();
			}
			
		}catch(NumberFormatException e){
			// do nothing
		}
	}
	
	public void focusLost(FocusEvent evt){
		focusGained(evt);
	}
	
	public static void main(String[] arg){
		new TextChanger2();
	}
}
