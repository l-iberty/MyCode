import javax.swing.*;

public class Authenticator extends JFrame{
	JTextField username = new JTextField(15);
	JPasswordField password = new JPasswordField(15);
	JTextArea comments = new JTextArea(4,15);
	/*JScrollPane scroll = new JScrollPane(comments, 
	                                     ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS,
										 ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER); */
	
	
	JButton ok = new JButton("OK");
	JButton cancel = new JButton("Cancel");
	
	public Authenticator(){
		super("Account Information");
		setSize(300,250);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JPanel panel = new JPanel();
		
		JLabel usernameLable = new JLabel("Username:", SwingConstants.CENTER);
		JLabel passwordLable = new JLabel("Password:", SwingConstants.CENTER);
		JLabel commentsLable = new JLabel("Comments:", SwingConstants.CENTER);
		comments.setLineWrap(true);
		comments.setWrapStyleWord(true);
		
		
		panel.add(usernameLable);
		panel.add(username);
		panel.add(passwordLable);
		panel.add(password);
		panel.add(commentsLable);
		panel.add(comments);
		
		// 放在构造器外面不能添加滚动条，why?
		JScrollPane scroll = new JScrollPane(comments, 
	                                     ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS,
										 ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);
		panel.add(scroll);
		panel.add(ok);
		panel.add(cancel);
		
		this.add(panel);
		
		setVisible(true);
	}
	
	public static void main(String[] arg){
		try{
			UIManager.setLookAndFeel("com.sun.java.swing.plaf.nimbus.NimbusLookAndFeel");
		}catch(Exception e){
			System.out.println(e.getMessage());
		}
		
		Authenticator auth = new Authenticator();
	}
}