import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class CardPanel extends JLabel implements ActionListener{
	JButton next, back, finish;
	CardLayout card = new CardLayout();
	JPanel pane;
	
	public CardPanel(){
		super();
		setLayout(card);
		
		back = new JButton("Back");
		next = new JButton("Next");
		finish = new JButton("Finish");
		back.addActionListener(this);
		next.addActionListener(this);
		finish.addActionListener(this);
		
		pane = new JPanel();
		pane.add(next);
		pane.add(back);
		pane.add(finish); 
		
		add(pane, "card"); // 将用作卡片的容器指定为pane.
		
	}
	
	public void actionPerformed(ActionEvent evt){
		Object source = evt.getSource();
		
		if(source == back){
			card.show(pane, "card");
		}else if(source == next){
			card.show(pane, "card");
		}else if(source == finish){
			card.show(pane, "card");
		}
	}
	
	
}