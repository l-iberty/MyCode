package Shapes;

import util.Mover;

import java.awt.*;
import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import java.io.Serializable;
import java.util.Vector;

public class MyLine extends MyShape implements Serializable {
    private Line2D line2D = new Line2D.Double(); //这个构造函数里什么都没有
    private Point2D[] points = new Point2D[2];

    @Override
    public void setPoints(Vector<Point2D> p) {
        /*
         *Vector是类似于ArrayList的动态数组,但Vector是同步访问的,ArrayList
         *是非同步访问的.因此,Vector在涉及到多线程的设计中更加适合.
         */ 
        /*关于同步访问:
         *java中的同步是指当多个线程要同时访问某个对象、方法、变量等的时候,
         *保证只有唯一线程访问同步的对象.实现同步需要使用synchronized关键字
         *修饰;Vector的许多公有方法都有synchronized修饰.
         */
        p.toArray(points);//把Vector内的元素拷贝到数组points中.
    }

    @Override
    public String getButtonName() {
        return "line";
    }

    @Override
    public String getClassName() {
        return "MyLine";
    }

    @Override
    public void init() {
        line2D.setLine(points[0], points[1]);
        /*
         *  public void setLine(Point2D p1, Point2D p2) {
         *      etLine(p1.getX(), p1.getY(), p2.getX(), p2.getY());
         *  }
         */
    }

    @Override
    public void draw(Graphics g) {
        Graphics2D graphics2D = (Graphics2D) g;
        graphics2D.draw(line2D);
    }

    @Override
    public boolean contains(Point2D p) {
        return (line2D.ptLineDist(p.getX(), p.getY()) < 2.0);
        /*
         *注释文档云:
         * "Tests if a specified coordinate is inside the boundary of this
         * Line2D."
         *如果是这样的话应该返回布尔值,而且如文档所述,总返回false;
         *可源代码显示,该方法和ptLineDist(double px, double py)一样,都是——
         * "Returns the distance from a <code>Point2D</code> to this line."
         */
    }

    @Override
    public void move(Point2D p1, Point2D p2) {
        Mover.mover(p1, p2, points);
        init();
    }
}
