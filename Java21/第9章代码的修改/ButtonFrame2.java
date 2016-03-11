import javax.swing.*;

// 设置组件的一些属性

public class ButtonFrame2 extends JFrame{
	JButton load, save, fuck;
	
	load.setSize(10,15);
	save.setEnale(false);
	fuck.setVisible(false);
	
	load = new JButton("Load");
	save = new JButton("Save");
	fuck = new JButton("Fuck");
	
	public ButtonFrame2(){
		super("Button Frame");
		setSize(500,500);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JPanel panel = new JPanel();
		panel.add(load);
		panel.add(save);
		panel.add(fuck);
		
		this.add(panel);
		
		try{
			UIManager.setLookAndFeel("com.sun.java.swing.plaf.nimbus.NimbusLookAndFree");
		}catch(Exception e){
			//do nothing
		
		}
		
		setVisible(true);
	}
	
	public static void main(String[] arg){
		ButtonFrame2 button = new ButtonFrame2();
	}
}