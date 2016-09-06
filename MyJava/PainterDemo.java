import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import javax.swing.*;
import java.util.*;
import java.io.*;

public class PainterDemo extends JFrame implements ActionListener{
	private JMenuItem sFile, oFile;
	private JRadioButton ellButton, recButton, lineButton, dragButton;
	private JButton clearButton;
	private Painter pt;
	
	public PainterDemo(){
		super("Painter");
		setSize(500, 400);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLookAndFeel();
		
		/* 设置菜单栏 */
		// 文件选项
		JMenu file = new JMenu("File(F)");
		sFile = new JMenuItem("Sava File");
		sFile.addActionListener(this);
		oFile = new JMenuItem("Open File");
		oFile.addActionListener(this);
		file.add(sFile);
		file.addSeparator();
		file.add(oFile);
		JMenuBar bar = new JMenuBar();
		bar.add(file);
		
		// 图形选项
		ButtonGroup shapeItem = new ButtonGroup();
		ellButton = new JRadioButton("ellipse");
		ellButton.addActionListener(this);
		recButton = new JRadioButton("rectangle");
		recButton.addActionListener(this);
		lineButton = new JRadioButton("line");
		lineButton.addActionListener(this);
		dragButton = new JRadioButton("drag");
		dragButton.addActionListener(this);
		shapeItem.add(ellButton);
		shapeItem.add(recButton);
		shapeItem.add(lineButton);
		shapeItem.add(dragButton);
		bar.add(ellButton);
		bar.add(recButton);
		bar.add(lineButton);
		bar.add(dragButton);
		
		// 清空选项
		clearButton = new JButton("Clear(C)");
		clearButton.addActionListener(this);
		bar.add(clearButton);
		
		setJMenuBar(bar);
		pt = new Painter();
		add(pt);
		setVisible(true);
	}
	
	private void setLookAndFeel() {
        try {
            UIManager.setLookAndFeel("com.sun.java.swing.plaf.nimbus.NimbusLookAndFeel");
			SwingUtilities.updateComponentTreeUI(this);
        } catch (Exception e) {
            // do nothing
        }
    }
	
	public void actionPerformed(ActionEvent evt){
		Object source = evt.getSource();
		
		if(source == sFile){
			pt.setShapeArray();
			pt.saveFile();
		}else if(source == oFile){
			pt.setShapeListAndRepaint(pt.openFile());
		}else if(source == ellButton){
			pt.setItem(ellButton.getText());
		}else if(source == recButton){
			pt.setItem(recButton.getText());
		}else if(source == lineButton){
			pt.setItem(lineButton.getText());
		}else if (source == dragButton){
			pt.setItem(dragButton.getText());
		}else if(source == clearButton){
			pt.clearPainting();
		}
	}
	
	public static void main(String[] arg){
		new PainterDemo();
	}
}

class Painter extends JPanel implements MouseListener, MouseMotionListener{
	private int x1,y1,x2,y2,w,h;
	private int prevX, prevY, currentX, currentY, dw, dh; //用于拖动
	private boolean isDrag = false;
	private String msg;
	private Ellipse2D.Float ellipse;
	private Rectangle2D.Float rectangle;
	private Line2D.Float line;
	private ArrayList<Shape> shapeList = new ArrayList<>();
	private Shape[] shapeArray;
	private int count = 0;
	
	public Painter(){
		addMouseListener(this);
		addMouseMotionListener(this);
	}
	
	public void paintComponent(Graphics comp){
        Graphics2D comp2D = (Graphics2D)comp;
		BasicStroke pen = new BasicStroke(2.0f, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND);
        
		Rectangle2D.Float recClear = new Rectangle2D.Float(0F, 0F,
			(float)getSize().width, (float)getSize().height);
		comp2D.setColor(getBackground());
		comp2D.fill(recClear); //清屏代码
		
		comp2D.setColor(Color.BLACK);
		comp2D.setStroke(pen);
		comp2D.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
			RenderingHints.VALUE_ANTIALIAS_ON);
		for(Iterator it = shapeList.iterator(); it.hasNext();){
			Shape tshape = (Shape)it.next();
			comp2D.draw(tshape);
		}
		
		if(msg != null){
			switch (msg){
				case "ellipse":
					ellipse = new Ellipse2D.Float( Math.min(x1,x2), Math.min(y1,y2), w, h );
					comp2D.draw(ellipse);
					break;
				case "rectangle":
					rectangle = new Rectangle2D.Float( Math.min(x1,x2), Math.min(y1,y2), w, h );
					comp2D.draw(rectangle);
					break;
				case "line":
					line = new Line2D.Float( x1, y1, x2, y2 );
					comp2D.draw(line);
					break;
				case "drag":
					dragShape();
					break;
			}
		}
		
    }
	
	public void setItem(String inMsg){
		msg = inMsg;
	}
	
	public void setShapeArray(){
		shapeArray = new Shape[shapeList.size()];
		for(int i = 0; i < shapeList.size(); i++)
			shapeArray[i] = shapeList.get(i);
	}
	
	public void setShapeListAndRepaint(Shape[] s){
		for(int i = 0; i < s.length; i++)
			shapeList.add(s[i]);
		repaint();// 自动调用paintComponent()
	}
	
	public void clearPainting(){
		setItem(null);
		shapeList.clear();
		ellipse = null;
		rectangle = null;
		line = null;
		repaint();
	}

	private void dragShape(){
		isDrag = true;
	}
	
	// 监听器
	public void mouseClicked(MouseEvent evt){
        ;
    }
    public void mouseEntered(MouseEvent evt){
        ;
    }
    public void mouseExited(MouseEvent evt){
        ;
    }
    public void mousePressed(MouseEvent evt){
        x1 = evt.getX();
        y1 = evt.getY();
        prevX = x1;
        prevY = y1;
    }
    public void mouseReleased(MouseEvent evt){
        if(ellipse != null)
			shapeList.add(ellipse);
		if(rectangle != null)
			shapeList.add(rectangle);
		if(line != null)
			shapeList.add(line);
    }

    public void mouseDragged(MouseEvent evt){
		x2 = evt.getX();
        y2 = evt.getY();
        w = Math.abs(x1 - x2);
		h = Math.abs(y1 - y2);

        if (isDrag){
        	currentX = x2;
	        currentY = y2;
	        dw = currentX - prevX;
	        dh = currentY - prevY;

	        Rectangle2D.Float shapeToDrag = (Rectangle2D.Float)shapeList.get(0);

	        float newX = (float)(x1 + dw);
	        float newY = (float)(y1 + dh);
	        float newWidth = (float)shapeToDrag.getWidth();
	        float newHeight = (float)shapeToDrag.getHeight();

	        Rectangle2D.Float newRec = new Rectangle2D.Float(newX, newY, newWidth, newHeight);
	        shapeList.clear();
			shapeList.add(newRec);

			isDrag = false;
        }

		repaint();
    }
    public void mouseMoved(MouseEvent evt){
       ;
    }
	
	// 读写文件
	public void saveFile(){
		try(FileOutputStream painting = new FileOutputStream("Painting.dat");
			ObjectOutputStream obj = new ObjectOutputStream(painting);){
			
			obj.writeObject(shapeArray);
			obj.close();
		}catch(IOException e){
			System.out.println(e.getMessage());
		}
	}
	
	public Shape[] openFile(){
		try(FileInputStream painting = new FileInputStream("Painting.dat");
			ObjectInputStream obj = new ObjectInputStream(painting);){
			
			Shape[] tmp = (Shape[])obj.readObject();
			obj.close();
			return tmp;
		}catch(Exception e){
			System.out.println(e.getMessage());
			return null;
		}
	}
}