import javax.swing.*;

public class DVR extends JFrame{
	JButton play = new JButton("����");
	JButton stopAndout = new JButton("ֹͣ\\����");
	JButton	back = new JButton("����");
	JButton quick = new JButton("���");
    JButton pause = new JButton("��ͣ");
			
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