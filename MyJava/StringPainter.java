import javax.swing.*;
import java.awt.*;

public class StringPainter extends JFrame{
	public StringPainter(String text){
		super("Painter");
		setSize(500,400);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		PanelDemo painter = new PanelDemo(text);
		add(painter);
		//setBackground(Color.red);
		
		setVisible(true);
	}
	
	public static void main(String[] arg){
		new StringPainter(arg[0]);
	}
}

class PanelDemo extends JPanel{
	String text;
	
	public PanelDemo(String inText){
		text = inText;
		//setForeground(Color.green);
	}
	
	public void paintComponent(Graphics comp){
		Graphics2D comp2D = (Graphics2D)comp;
		comp.setColor(new Color(120, 189, 23));
		Font font = new Font(text, Font.BOLD + Font.ITALIC, 50);
		FontMetrics metrics = getFontMetrics(font);
		comp2D.setFont(font);
		comp2D.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
		int x = (getSize().width - metrics.stringWidth(text)) / 2;
		int y = getSize().height / 2;
		comp2D.drawString(text, x, y);
	}
}