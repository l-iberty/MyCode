import java.awt.*;
import java.awt.event.*;
import javax.swing.*; 

public class ProgressMonitor3 extends JFrame {

    JProgressBar current;
    JTextField numField;
    JButton find;
    Thread runner;
    int num = 0;

    public ProgressMonitor3() {
        super("ProgressMonitor2");
        setSize(190, 80);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JPanel pane = new JPanel();
        pane.setLayout(new FlowLayout());
        numField = new JTextField("" + num, 8);
        pane.add(numField);
        current = new JProgressBar(0, 2000);
        current.setValue(0);
        current.setStringPainted(true);
        pane.add(current);
        setContentPane(pane);
        setVisible(true);
    }


    public void iterate() {
        while (num < 2000) {
            current.setValue(num);
            numField.setText("" + num);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) { }
            num += 95;
        }
    }

    public static void main(String[] arguments) {
        ProgressMonitor3 frame = new ProgressMonitor3();
        frame.iterate();
    }
}