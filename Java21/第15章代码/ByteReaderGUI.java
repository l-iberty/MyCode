import javax.swing.*;
import java.io.*;
import java.util.*;

public class ByteReaderGUI extends JFrame{
	JTextArea text;
	
	public ByteReaderGUI(){
		super("ByteReader.java");
		setSize(600,300);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		text = new JTextArea();
		text.setLineWrap(true);
		text.setWrapStyleWord(true);
		JScrollPane scroll = new JScrollPane(text,
		                         ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS,
								 ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);
								 
		add(scroll);
		setVisible(true);
	}
	
	public static void main(String[] arg){
		ByteReaderGUI frame = new ByteReaderGUI();
		
		try( FileInputStream file = new FileInputStream("ByteReader.java") ){
			
			boolean eof = false;
			int count = 0;
			ArrayList<Integer> list = new ArrayList<>();
			
			while(!eof){
				int input = file.read();
				list.add(new Integer(input));
				if(input == -1)
					eof = true;
				else
					count++;
			}
			frame.text.setText(list + "\nByte read:" + count);
			
			file.close();
			
		}catch(IOException e){
			frame.text.setText(e.getMessage());
		}
	}
}