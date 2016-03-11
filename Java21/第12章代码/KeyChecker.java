import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class KeyChecker extends JFrame {
    JLabel keyLabel = new JLabel("Hit any key");

    public KeyChecker() {
        super("Hit a Key");
        setSize(300, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new FlowLayout(FlowLayout.CENTER));
		setLookAndFeel();
		
        KeyMonitor monitor = new KeyMonitor(this); /* This "this" prefers to the object of class KeyChecker
		                                              rather than the object of class KeyMonitor,otherwise
													  it doesn't make sense logically. */
		                                              
        // setFocusable(true); This statement seems to be useless here.
        addKeyListener(monitor);
		
        add(keyLabel);
        setVisible(true);
    }

    private static void setLookAndFeel() {
        try {
            UIManager.setLookAndFeel(
                "com.sun.java.swing.plaf.nimbus.NimbusLookAndFeel"
            );
        } catch (Exception exc) {
            System.err.println("Couldn't use the system "
                + "look and feel: " + exc);
        }
    }

    public static void main(String[] arguments) {
        new KeyChecker();
    }
}

class KeyMonitor extends KeyAdapter {
    KeyChecker display;

    KeyMonitor(KeyChecker display) {
        this.display = display;
    }

    public void keyTyped(KeyEvent event) {
        display.keyLabel.setText("" + event.getKeyChar());
        display.repaint();
    }
}