import javax.swing.*;

public class MessageFrame extends JFrame {
    public MessageFrame() {
        super("Message");
        setSize(380, 120);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLookAndFeel();
		
        MessagePanel mPanel = new MessagePanel();
        add(mPanel);
        setVisible(true);
   }

    private void setLookAndFeel() {
        try {
           UIManager.setLookAndFeel(
                "com.sun.java.swing.plaf.nimbus.NimbusLookAndFeel"
            );
            SwingUtilities.updateComponentTreeUI(this);
        } catch (Exception exc) {
            System.err.println("Couldn't use the system "
                + "look and feel: " + exc);
        }
    }
 
    public static void main(String[] arguments) {
        MessageFrame frame = new MessageFrame();
    }
}