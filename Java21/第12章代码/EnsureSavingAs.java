import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class EnsureSavingAs extends JFrame implements ActionListener, KeyListener{
	JButton yes, no;
	JLabel text;
	
	public EnsureSavingAs(){
		super("Ensure Saving As");
		setSize(250, 150);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(new BorderLayout());
		setLookAndFeel();
		
		yes = new JButton("Yes(Y)");
		no = new JButton("No(N)");
		yes.addActionListener(this);
		yes.addKeyListener(this);
		no.addActionListener(this);
		no.addKeyListener(this);
		
		text = new JLabel(); 
		JPanel pane = new JPanel();
		pane.add(yes);
		pane.add(no);
		
		add(BorderLayout.NORTH, pane);
		add(BorderLayout.CENTER, text);
		
		setVisible(true);
	}
	
	public void actionPerformed(ActionEvent evt){
		Object source = evt.getSource();
		
		if(source == yes){
			text.setText("Save the file");
		}else if(source == no){
			text.setText("Don't save the file");
		}
	}
	
	public void keyPressed(KeyEvent evt){
		char c = evt.getKeyChar();
		
		if(c == 'y'){
			text.setText("Save the file");
		}else if(c == 'n'){
			text.setText("Don't save the file");
		}
	}
	
	public void keyReleased(KeyEvent evt){
		keyPressed(evt);
	}
	
	public void keyTyped(KeyEvent evt){
		keyPressed(evt);
	}
	
	private void setLookAndFeel() {
        try {
            UIManager.setLookAndFeel("com.sun.java.swing.plaf.nimbus.NimbusLookAndFeel");
			SwingUtilities.updateComponentTreeUI(this);
        } catch (Exception e) {
            // do nothing
        }
    }
	
	public static void main(String[] arg){
		EnsureSavingAs frame = new EnsureSavingAs();
	}
}