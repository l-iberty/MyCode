import javax.swing.*;
import java.awt.*;

public class Calendar extends JFrame{
	
	public Calendar(){
		super("Calendar");
		setSize(310, 310);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		GridBagLayout gridbag = new GridBagLayout();
		setLayout(gridbag);
		setLookAndFeel();
		
		JLabel month = new JLabel("October 2016");
		JLabel Sun = new JLabel("Sun");
		JLabel Mon = new JLabel("Mon");
		JLabel Tue = new JLabel("Tue");
		JLabel Wed = new JLabel("Wed");
		JLabel Thu = new JLabel("Thu");
		JLabel Fri = new JLabel("Fri");
		JLabel Sat = new JLabel("Sat");
		
		JLabel[] Date = new JLabel[31];
		for(int date = 1; date <= 31; date++){
			Date[date-1] = new JLabel(date + "");
		}
		
		JPanel paneMonth = new JPanel();
		JPanel paneWeek = new JPanel();
		JPanel paneDate = new JPanel();
		paneMonth.setLayout(new FlowLayout(FlowLayout.CENTER));
		paneWeek.setLayout(new GridLayout(1,7,18,5));
		paneDate.setLayout(new GridLayout(5,7,28,5));
		
		paneMonth.add(month);
		paneWeek.add(Sun);
		paneWeek.add(Mon);
		paneWeek.add(Tue);
		paneWeek.add(Wed);
		paneWeek.add(Thu);
		paneWeek.add(Fri);
		paneWeek.add(Sat);
		
		for(int i = 0; i < 31; i++){
			paneDate.add(Date[i]);
		}
		
		GridBagConstraints constraintMonth = new GridBagConstraints();
		GridBagConstraints constraintWeek = new GridBagConstraints();
		GridBagConstraints constraintDate = new GridBagConstraints();
		
		constraintMonth.gridx = 0;
		constraintMonth.gridy = 0;
		constraintMonth.gridwidth = 10;
		constraintMonth.gridheight = 1;
		constraintMonth.weightx = 10;
		constraintMonth.weighty = 1;
		constraintMonth.anchor = GridBagConstraints.SOUTH;
		
		constraintWeek.gridx = 0;
		constraintWeek.gridy = 1;
		constraintWeek.gridwidth = 10;
		constraintWeek.gridheight = 1;
		constraintWeek.weightx = 10;
		constraintWeek.weighty = 1;
		constraintWeek.anchor = GridBagConstraints.SOUTH;
		
		constraintDate.gridx = 0;
		constraintDate.gridy = 2;
		constraintDate.gridwidth = 10;
		constraintDate.gridheight = 5;
		constraintDate.weightx = 10;
		constraintDate.weighty = 1;
		constraintDate.anchor = GridBagConstraints.NORTH;
		
		gridbag.setConstraints(paneMonth, constraintMonth);
		gridbag.setConstraints(paneWeek, constraintWeek);
		gridbag.setConstraints(paneDate, constraintDate);
		add(paneMonth);
		add(paneWeek);
		add(paneDate);
		
		setVisible(true);
	}
	
	private void setLookAndFeel(){
		try{
			UIManager.setLookAndFeel("com.sun.java.swing.plaf.nimbus.NimbusLookAndFeel");
			SwingUtilities.updateComponentTreeUI(this);
		}catch(Exception e){
			// do nothing
		}
	}
	
	public static void main(String[] arg){
		Calendar cal = new Calendar();
	}
}