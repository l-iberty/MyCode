package Factory;

import Shapes.MyShape;

public class ShapeFactory {
    public static MyShape createShapeInstance(String className) {
    	System.out.println(className);
        MyShape s = null;

        try {
            s = (MyShape) Class.forName(className).newInstance();
        } catch (InstantiationException | ClassNotFoundException | IllegalAccessException e) {
            e.printStackTrace();
        }
        
        return s;
    }
}
