package Factory;

import java.io.File;
import java.util.ArrayList;

public class ButtonFactory {
    public static ArrayList<String> getClassNames() {
        ArrayList<String> classNames = new ArrayList<>();
        File dir = new File("C:\\Users\\len\\Desktop\\src\\Shapes");
        if (dir == null) {
            System.out.println("Shapes Not Found");
            return null;
        }
        else
            System.out.println("Shapes Found~");

        File[] files = dir.listFiles();

        if (files == null) {
            System.out.println("Files Not Found!");
            return null;
        }

        for (File file : files) {
        	String filename = file.getName();
        	if (!filename.equals("MyShape.java") && !filename.equals(".DS_Store"))
        		classNames.add(filename.substring(0, filename.length() - 5));
        }

        return classNames;
    }
}
