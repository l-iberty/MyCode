import java.awt.*;
import javax.swing.*;

/* 将组件加入到网格袋布局的步骤：
   1.创建该组件
   2.创建约束条件对象GirdBagConstraints
   3.调用布局管理器的setConstraints(Compenent, GirdBagConstraints)方法，
     将该组件和约束条件对象作为参数传递给它
   4.将组件加入到使用该管理器的容器中
*/

public class MessagePanel extends JPanel {
	GridBagLayout gridbag = new GridBagLayout();

    public MessagePanel() {
        super();
        setLayout(gridbag);

        JLabel toLabel = new JLabel("To: ");
        JTextField to = new JTextField();
        JLabel subjectLabel = new JLabel("Subject: ");
        JTextField subject = new JTextField();
        JLabel ccLabel = new JLabel("CC: ");
        JTextField cc = new JTextField();
        JLabel bccLabel = new JLabel("BCC: ");
        JTextField bcc = new JTextField();

        addComponent(toLabel, 0, 0, 1, 1, 10, 100,
            GridBagConstraints.NONE, GridBagConstraints.EAST);
        addComponent(to, 1, 0, 9, 1, 90, 100,
            GridBagConstraints.HORIZONTAL, GridBagConstraints.WEST);
        addComponent(subjectLabel, 0, 1, 1, 1, 10, 100,
            GridBagConstraints.NONE, GridBagConstraints.EAST);
        addComponent(subject, 1, 1, 9, 1, 90, 100,
            GridBagConstraints.HORIZONTAL, GridBagConstraints.WEST);
        addComponent(ccLabel, 0, 2, 1, 1, 10, 100,
            GridBagConstraints.NONE, GridBagConstraints.EAST);
        addComponent(cc, 1, 2, 4, 1, 40, 100,
            GridBagConstraints.HORIZONTAL, GridBagConstraints.WEST);
        addComponent(bccLabel, 5, 2, 1, 1, 10, 100,
            GridBagConstraints.NONE, GridBagConstraints.EAST);
        addComponent(bcc, 6, 2, 4, 1, 40, 100,
            GridBagConstraints.HORIZONTAL, GridBagConstraints.WEST);
    }

    private void addComponent(Component component, int gridx, int gridy,
        int gridwidth, int gridheight, int weightx, int weighty, int fill,
        int anchor) {

        GridBagConstraints constraints = new GridBagConstraints();
        constraints.gridx = gridx;
        constraints.gridy = gridy;
        constraints.gridwidth = gridwidth;
        constraints.gridheight = gridheight;
        constraints.weightx = weightx;
        constraints.weighty = weighty;
        constraints.fill = fill;
        constraints.anchor = anchor;
        gridbag.setConstraints(component, constraints);
        add(component);
    }
}