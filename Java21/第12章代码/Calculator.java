import java.awt.event.*;
import java.awt.*;
import javax.swing.*;

public class Calculator extends JFrame implements FocusListener{
	JTextField value1, value2, sum;
	JLabel plus, equals;
	
	public Calculator(){
		super("Calculator");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setSize(350, 90);
		setLookAndFeel();
		setLayout( new FlowLayout() );
		
		value1 = new JTextField("0", 5);
		value2 = new JTextField("0", 5);
		sum = new JTextField("0", 5);
		sum.setEditable(false);
		plus = new JLabel("+");
		equals = new JLabel("=");
		
		value1.addFocusListener(this);
		value2.addFocusListener(this);
		
		add(value1);
		add(plus);
		add(value2);
		add(equals);
		add(sum);
		setVisible(true);
	}
	
	public void focusGained(FocusEvent evt){
		try{
			float total = Float.parseFloat(value1.getText()) + Float.parseFloat(value2.getText());
			sum.setText("" + total);
		}catch(NumberFormatException e){
			value1.setText("0");
			value2.setText("0");
			sum.setText("0");
		}
	}
	
	public void focusLost(FocusEvent evt){
		focusGained(evt);
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
		Calculator calc = new Calculator();
	}
}