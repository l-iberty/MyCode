import javax.swing.*;

public class Subscriptions0 extends JFrame {
    String[] subs = { "0xDECAFBAD", "Cafe au Lait",
        "Hack the Planet", "Ideoplex", "Inessential", "Intertwingly",
        "Markpasc", "Postneo", "RC3", "Workbench" };
    JList subList = new JList(subs);

    public Subscriptions0() {
        super("Subscriptions");
        setSize(150, 335);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JPanel panel = new JPanel();
        JLabel subLabel = new JLabel("RSS Subscriptions:");
        panel.add(subLabel);
        subList.setVisibleRowCount(8);
        JScrollPane scroller = new JScrollPane(subList);
        panel.add(scroller);
        add(panel);
        setVisible(true);
    }

    private static void setLookAndFeel() {
        try {
            UIManager.setLookAndFeel(
                "com.sun.java.swing.plaf.nimbus.NimbusLookAndFeel"
            );
        } catch (Exception exc) {
            System.out.println(exc.getMessage());
        }
    }

    public static void main(String[] arguments) {
        Subscriptions0.setLookAndFeel();
        Subscriptions0 app = new Subscriptions0();
    }
}