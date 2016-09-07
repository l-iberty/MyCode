import javax.swing.*;
import java.awt.*;

import Frame.DrawFrame;

public class DrawTest implements {
    public static void main(String args[]) {
        EventQueue.invokeLater(new Runnable() {
            public void run() {
                JFrame frame = new DrawFrame();
                /*
                 *对象既可作为它本身的类型使用,也可作为它的基类的类型使用.
                 *把这种将某个对象的引用视为其基类类型的引用的做法称为[向上转型].
                 *引用变量frame的类型是JFrame,但实际调用方法时仍从子类开始
                 *检索.
                 */
                frame.setTitle("DrawBoard");
                frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                frame.setVisible(true);
            }
        });
    }
}
