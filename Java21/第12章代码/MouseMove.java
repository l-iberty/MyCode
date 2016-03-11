import java.awt.event.*;
import java.awt.*;
import javax.swing.*;

public class MouseMove extends JFrame implements MouseMotionListener{
	JTextField x, y;
	
	public MouseMove(){
		super("MouseMove Test");
		setSize(550, 450);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(new FlowLayout());
		addMouseMotionListener(this);
		setLookAndFeel();
		
		x = new JTextField(5);
		y = new JTextField(5);
		JLabel xLabel = new JLabel("x:", SwingConstants.RIGHT);
		JLabel yLabel = new JLabel("y:", SwingConstants.RIGHT);
		
		JPanel pane = new JPanel();
		pane.setLayout(new GridLayout(2,2));
		pane.add(xLabel);
		pane.add(x);
		pane.add(yLabel);
		pane.add(y);
		
		add(pane);
		setVisible(true);
	}
	
	public void mouseMoved(MouseEvent evt){
		x.setText("" + evt.getX());
		y.setText("" + evt.getY());
	}
	
	public void mouseDragged(MouseEvent evt){
		System.out.println("dragged"); // 拖动鼠标将引发该事件
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
		MouseMove frame = new MouseMove();
	}
}