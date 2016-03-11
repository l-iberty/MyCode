import javax.swing.*;

public class User extends JFrame{
	JTextField username = new JTextField(15);
    JPasswordField password = new JPasswordField(15);
	JTextArea commemts = new JTextArea(10,15);
	
	JLabel usernameLabel = new JLabel("Username:");
	JLabel passwordLabel = new JLabel("Password:");
	JLabel commemtsLabel = new JLabel("Comments:");
	
	JButton ok = new JButton("OK");
	JButton cancel = new JButton("CANCEL");
	
	public User(){
		super("USER'S INFORMATION");
		setSize(300,350);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JPanel panel = new JPanel();
		panel.add(usernameLabel);
		panel.add(username);
		panel.add(passwordLabel);
		panel.add(password);
		panel.add(commemtsLabel);
		panel.add(commemts);
		
		JScrollPane scroll = new JScrollPane(commemts,
		                                    ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS,
											ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);
											
		panel.add(scroll);
		panel.add(ok);
		panel.add(cancel);
		
		add(panel);
		setVisible(true);
	}
	
	public static void main(String[] arg){
		try{
			UIManager.setLookAndFeel("com.sun.java.swing.plaf.nimbus.NimbusLookAndFeel");
		}catch(Exception e){
			System.out.println(e.getMessage());
		}
		User user = new User();
	}
}