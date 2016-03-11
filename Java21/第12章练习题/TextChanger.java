import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class TextChanger extends JFrame{
	JTextField number1, number2;
	
	public TextChanger(){
		super("Text Changer");
		setSize(200, 150);
		setLayout(new FlowLayout());
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		number1 = new JTextField(5);
		number2 = new JTextField(5);
		Text text = new Text(this);
		number1.addFocusListener(text);
		number2.addFocusListener(text);
		
		JPanel pane = new JPanel();
		BoxLayout box = new BoxLayout(pane, BoxLayout.Y_AXIS);
		pane.setLayout(box);
		pane.add(number1);
		pane.add(number2);
		
		add(pane);
		setVisible(true);
	}
	
	public static void main(String[] arg){
		new TextChanger();
	}

}

class Text extends FocusAdapter{
	TextChanger change;
	
	Text(TextChanger change){
		this.change = change;
	}
	
	public void focusGained(FocusEvent evt){
		int tmp;
		
		try{
			tmp = Integer.parseInt(change.number1.getText());
			if( tmp < 0 ){
				change.number1.setText( "" + (-1)*tmp );
			    change.number1.repaint();
			}
			
			tmp = Integer.parseInt(change.number2.getText());
			if( tmp < 0 ){
				change.number2.setText( "" + (-1)*tmp );
			    change.number2.repaint();
			}
			
		}catch(NumberFormatException e){
			// do nothing
		}
	}
}
