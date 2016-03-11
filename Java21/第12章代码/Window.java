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
		System.out.println("activated"); // ���ڱ���������ж�����ڣ������������ڣ����ͱ�����
	}
	
	public void windowClosed(WindowEvent evt){
		System.out.println("closed"); // ���ڱ��رպ�
	}
	
	public void windowClosing(WindowEvent evt){
		System.out.println("closing"); // ���ڱ��ر�ʱ
	}
	
	public void windowDeactivated(WindowEvent evt){
		System.out.println("deactivated"); // ����δ������
	}
	
	public void windowDeiconified(WindowEvent evt){
		System.out.println("deiconified"); // ������
	}
	
	public void windowIconified(WindowEvent evt){
		System.out.println("iconifieded"); // ���ڱ���С��
	}
	
	public void windowOpened(WindowEvent evt){
		System.out.println("Opened"); // �򿪴���
	}
	
	
	public static void main(String[] arg){
		Window wd = new Window();
	}
}