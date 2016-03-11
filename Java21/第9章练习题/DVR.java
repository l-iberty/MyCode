import javax.swing.*;

public class DVR extends JFrame{
	JButton play = new JButton("播放");
	JButton stopAndout = new JButton("停止\\弹出");
	JButton	back = new JButton("倒带");
	JButton quick = new JButton("快进");
    JButton pause = new JButton("暂停");
			
	public DVR(){
		super("DVR");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JPanel panel = new JPanel();
		panel.add(play);
		panel.add(stopAndout);
		panel.add(back);
		panel.add(quick);
		panel.add(pause);
		
		add(panel);
		pack();
		setVisible(true);
	}
	
	public static void main(String[] arg){
		try{
			UIManager.setLookAndFeel("com.sun.java.swing.plaf.nimbus.NimbusLookAndFeel");
		}catch(Exception e){
			System.out.println(e.getMessage());
		}
		
		DVR dvr = new DVR();
	}
}