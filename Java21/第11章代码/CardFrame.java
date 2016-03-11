import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class CardFrame extends JFrame{
	public CardFrame(){
		super("Card");
		setSize(400,350);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Card cardPanel = new Card();
		
		add(cardPanel);
		setVisible(true);
	}
	
	public static void main(String[] arg){
		new CardFrame();
	}
}