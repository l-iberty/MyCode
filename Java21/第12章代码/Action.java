import java.awt.event.*;
import java.awt.*;
import javax.swing.*;

public class Action extends JFrame implements ActionListener{
	JButton button;
	JMenuItem menuitem;
	
	public Action(){
		super("Action");
		setSize(200,100);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout( new FlowLayout() );
		
		button = new JButton("Button");
		menuitem = new JMenuItem("MenuItem");
		button.setActionCommand("Sort Files");
		menuitem.setActionCommand("Sort Files");
		JMenu menu = new JMenu("Menu");
		JMenuBar menubar = new JMenuBar();
		
		button.addActionListener(this);
		menuitem.addActionListener(this);
		menu.add(menuitem);
		menubar.add(menu);
		
		add(button);
		setJMenuBar(menubar);

		setVisible(true);
	}
	
	public void actionPerformed(ActionEvent evt){
		Object source = evt.getSource();
		
		if(source==button){
			setTitle("Button");
		}else if(source==menuitem){
			setTitle("MenuItem");
		}
		
		repaint();
	}
	
	public static void main(String[] arg){
		Action frame = new Action();
	}
}