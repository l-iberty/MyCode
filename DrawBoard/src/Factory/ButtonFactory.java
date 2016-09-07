package Factory;

import java.io.File;
import java.io.FileFilter;
import java.util.ArrayList;

public class ButtonFactory {
    public static ArrayList<String> getClassNames() {
        ArrayList<String> classNames = new ArrayList<>();
        File dir = new File("..\\Shapes");
        File[] files = dir.litFiles();

        for (File file : files) {
        	String filename = file.getName();
        	if (!filename.equals("MyShape.java") && !filename.equals(".DS_Store"))
        		classNames.add(filename.substring(0, filename.length() - 5));
        }

        return classNames;
    }
}
