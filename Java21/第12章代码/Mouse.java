import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Mouse extends JFrame implements MouseListener{
	JButton click;
	JTextField cltimes, x, y;
	
	public Mouse(){
		super("Mouse Test");
		setSize(550, 450);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(new FlowLayout(FlowLayout.CENTER, 30, 10));
		setLookAndFeel();
		
		click = new JButton("Click");
		click.addMouseListener(this);
		cltimes = new JTextField(5);
		x = new JTextField(5);
		y = new JTextField(5);
		JLabel cltimesLabel = new JLabel("clicking times:");
		JLabel xLabel = new JLabel("x:", SwingConstants.RIGHT);
		JLabel yLabel = new JLabel("y:", SwingConstants.RIGHT);
		
		JPanel pane = new JPanel();
		pane.setLayout(new GridLayout(3, 3));
		
		pane.addMouseListener(this);
		pane.add(cltimesLabel);
		pane.add(cltimes);
		pane.add(xLabel);
		pane.add(x);
		pane.add(yLabel);
		pane.add(y);
		
		add(pane);
		add(click);
		
		addMouseListener(this);
		setVisible(true);
	}
	
	public void mouseClicked(MouseEvent evt){
		cltimes.setText("" + evt.getClickCount()); // 鼠标干脆地点击
	}
	
	public void mouseEntered(MouseEvent evt){
		System.out.println("Entered"); // 鼠标进入
	}
	
	public void mouseExited(MouseEvent evt){
		System.out.println("Exited"); // 鼠标离开
	}
	
	public void mousePressed(MouseEvent evt){
		x.setText("" + evt.getX());
		y.setText("" + evt.getY()); // 鼠标点击位置获取
	}
	
	public void mouseReleased(MouseEvent evt){
		System.out.println("Released"); // 鼠标释放
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
		Mouse frame = new Mouse();
	}
}