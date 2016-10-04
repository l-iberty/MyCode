package gamedemo.util;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class GameFrame extends JFrame implements ActionListener, FocusListener, ItemListener {
	private People p1 = new People();
	private People p2 = new People();
	private OrdinaryPeople op = new OrdinaryPeople();
	private AdvancedPeople ap = new AdvancedPeople();
	
	private JTextArea precess;
	private JTextField offensive, defensive;
	private JRadioButton[] mod = new JRadioButton[2];
	private Object item;
	private JButton begin;
	public static StringBuilder attackPrecess = new StringBuilder();
	
	public GameFrame(){
		super("Game");
		setSize(600, 500);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		offensive = new JTextField(5);
		defensive = new JTextField(5);
		offensive.addFocusListener(this);
		defensive.addFocusListener(this);
		JLabel iniLabel = new JLabel("Offensive Position");
		JLabel defLabel = new JLabel("Defensive Position");
		
		ButtonGroup group = new ButtonGroup();
		mod[0] = new JRadioButton("Ordinary Mode");
		mod[1] = new JRadioButton("Advanced Mode");
		mod[0].addItemListener(this);
		mod[1].addItemListener(this);
		group.add(mod[0]);
		group.add(mod[1]);
		
		begin = new JButton("Start!");
		begin.addActionListener(this);
		precess = new JTextArea();
		precess.setEditable(false);
		JScrollPane scroll = new JScrollPane(precess,
		                        ScrollPaneConstants.VERTICAL_SCROLLBAR_AS_NEEDED,
								ScrollPaneConstants.HORIZONTAL_SCROLLBAR_AS_NEEDED);
		scroll.setPreferredSize( new Dimension(500, 300) );
		
		JPanel pane = new JPanel();
		pane.setLayout(new FlowLayout(FlowLayout.CENTER, 30, 5));
		
		JPanel paneSub1 = new JPanel();
		paneSub1.setLayout(new FlowLayout());
		paneSub1.add(iniLabel);
		paneSub1.add(offensive);
		
		JPanel paneMod = new JPanel();
		paneMod.setLayout(new FlowLayout());
		paneMod.add(mod[0]);
		paneMod.add(mod[1]);
		
		JPanel paneSub2 = new JPanel();
		paneSub2.setLayout(new FlowLayout());
		paneSub2.add(defLabel);
		paneSub2.add(defensive);
		
		pane.add(paneSub1);
		pane.add(paneSub2);
		
		JPanel panebegin = new JPanel();
		panebegin.setLayout(new FlowLayout());
		
		panebegin.add(begin);
		
		JPanel panel = new JPanel();
		BoxLayout box = new BoxLayout(panel, BoxLayout.Y_AXIS);
		panel.setLayout(box);
		
		panel.add(pane);
		panel.add(paneMod);
		panel.add(panebegin);
		panel.add(scroll);
		
		add(panel);
		setVisible(true);
	}
	
	@Override
	public void focusGained(FocusEvent evt){
		p1.setName(offensive.getText());
		op.setName(p1.getName());
		p2.setName(defensive.getText());
		ap.setName(p2.getName());
	}
	
	@Override
	public void focusLost(FocusEvent evt){
		focusGained(evt);
	}
	
	@Override
	public void itemStateChanged(ItemEvent evt){
		item = evt.getItem();
	}

	@Override
	public void actionPerformed(ActionEvent evt){
		Object source = evt.getSource();
		if(source == begin){
			startGame();	
		}
	}

	private void startGame() {
		if (item == mod[0]) {
			p1.showInfo();
			p2.showInfo();
		    while (p1.getHP() > 0 && p2.getHP() > 0) {
		        p1.showAttack(p2);
		        p2.showJudgement(p1);
	    
		        if (p2.getHP() > 0){
		            p2.showAttack(p1);
		        	p1.showJudgement(p2);
		        }
            }
		    precess.setText(attackPrecess.toString());
			
	    } else if (item == mod[1]) {
			op.showInfo();
			ap.showInfo();
		    while (op.getHP() > 0 && ap.getHP() > 0) {
		        op.showAttack(ap);
		        ap.showJudgement(op);
	    
		        if (ap.getHP() > 0){
		            ap.showAttack(op);
		            op.showJudgement(ap);
		        }
            }
		    precess.setText(attackPrecess.toString());
	    }
	}
}