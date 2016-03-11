import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Calc extends JFrame implements ActionListener{
	JButton plus, minus, multiply, divide;
	JTextField a, b;
	JTextArea c;
	
	public Calc(){
		super("Calculator");
		setSize(400, 380);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(new FlowLayout());
		
		plus = new JButton("+");
		minus = new JButton("-");
		multiply = new JButton("*");
		divide = new JButton("/");
		JLabel equal = new JLabel("=");
		plus.addActionListener(this);
		minus.addActionListener(this);
		multiply.addActionListener(this);
		divide.addActionListener(this);
		
		a = new JTextField("0", 5);
		b = new JTextField("0", 5);
		c = new JTextArea("0", 1, 10);
		c.setEditable(false);
		
		JPanel symbol = new JPanel();
		symbol.setLayout(new GridLayout(4,1));
		symbol.add(plus);
		symbol.add(minus);
		symbol.add(multiply);
		symbol.add(divide);
		
		add(a);
		add(symbol);
		add(b);
		add(equal);
		add(c);
		
		setVisible(true);
	}
	
	public void actionPerformed(ActionEvent evt){
		Object source = evt.getSource();
		
		float tmp;
		try{
			if(source == plus){
				tmp = Float.parseFloat(a.getText()) + Float.parseFloat(b.getText());
				c.setText("" + tmp);
			}else if(source == minus){
				tmp = Float.parseFloat(a.getText()) - Float.parseFloat(b.getText());
				c.setText("" + tmp);
			}else if(source == multiply){
				tmp = Float.parseFloat(a.getText()) * Float.parseFloat(b.getText());
				c.setText("" + tmp);
			}else if(source == divide){
				tmp = Float.parseFloat(a.getText()) / Float.parseFloat(b.getText());
				c.setText("" + tmp);
			}
		}catch(NumberFormatException e){
			c.setText("Invalid Input");
		}
	}
	
	public static void main(String[] arg){
		new Calc();
	}
}