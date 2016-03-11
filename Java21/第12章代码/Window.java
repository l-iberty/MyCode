import java.awt.event.*;
import java.awt.*;
import javax.swing.*;

public class Window extends JFrame implements WindowListener{
	
	public Window(){
		super("Window");
		setSize(300,200);
		setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		addWindowListener(this);
		setVisible(true);
	}
	
	public void windowActivated(WindowEvent evt){
		System.out.println("activated"); // 窗口被激活，比如有多个窗口，鼠标点击这个窗口，它就被激活
	}
	
	public void windowClosed(WindowEvent evt){
		System.out.println("closed"); // 窗口被关闭后
	}
	
	public void windowClosing(WindowEvent evt){
		System.out.println("closing"); // 窗口被关闭时
	}
	
	public void windowDeactivated(WindowEvent evt){
		System.out.println("deactivated"); // 窗口未被激活
	}
	
	public void windowDeiconified(WindowEvent evt){
		System.out.println("deiconified"); // ？？？
	}
	
	public void windowIconified(WindowEvent evt){
		System.out.println("iconifieded"); // 窗口被最小化
	}
	
	public void windowOpened(WindowEvent evt){
		System.out.println("Opened"); // 打开窗口
	}
	
	
	public static void main(String[] arg){
		Window wd = new Window();
	}
}