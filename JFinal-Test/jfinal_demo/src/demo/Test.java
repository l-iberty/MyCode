package demo;

import com.jfinal.core.JFinal;

public class Test {

    public static void main(String args[]) {
        JFinal.start("WebContent", 80, "/", 5);
    }
}
