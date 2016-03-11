import javax.swing.*;
import java.awt.*;

public class Menu extends JFrame{
	
	public Menu(){
		// 框架设置
		super("Menu");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		// 工具栏设置
		JButton load = new JButton("Load");
		JButton save = new JButton("Save");
		JButton subscribe = new JButton("Subscribe");
		JButton delete = new JButton("Delete");
		
		JToolBar tool = new JToolBar();
		tool.add(load);
		tool.add(save);
		tool.add(subscribe);
		tool.add(delete);
		
		// 菜单设置--2组
		/* 1组 */
		JMenuItem i1 = new JMenuItem("open");
		JMenuItem i2 = new JMenuItem("save");
		JMenuItem i3 = new JMenuItem("save as");
		JMenuItem i4 = new JMenuItem("print");
		JMenuItem i5 = new JMenuItem("close");
		
		JMenu m1 = new JMenu("File");
		m1.add(i1);
		m1.add(i2);
		m1.add(i3);
		m1.addSeparator();
		m1.add(i4);
		m1.add(i5);
		
		/* 2组 */
		JMenuItem i6 = new JMenuItem("copy");
		JMenuItem i7 = new JMenuItem("paste");
		JMenuItem i8 = new JMenuItem("trim");
		JMenuItem i9 = new JMenuItem("delete");
		JMenuItem i10 = new JMenuItem("select all");
		
		JMenu m2 = new JMenu("Edit");
		m2.add(i6);
		m2.add(i7);
		m2.addSeparator();
		m2.add(i8);
		m2.add(i9);
		m2.add(i10);
		
		JMenuBar menubar = new JMenuBar();
		menubar.add(m1);
		menubar.add(m2);
		
		JTextArea edit = new JTextArea(8,40);
		JScrollPane scroll = new JScrollPane(edit,
		                         ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS,
								 ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);
		
		add("North", tool);
		add("Center", scroll);
		setJMenuBar(menubar);
		pack();
		setLookAndFeel();
		setVisible(true);
	}
	
	private void setLookAndFeel(){
		try{
			UIManager.setLookAndFeel("com.sun.java.swing.plaf.nimbus.NimbusLookAndFeel");
			SwingUtilities.updateComponentTreeUI(this);
		}catch(Exception e){
			System.out.println(e.getMessage());
		}
	}
	
	public static void main(String[] arg){
		Menu menu = new Menu();
	}
}