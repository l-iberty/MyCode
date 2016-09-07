import java.io.File;

public class FileDemo {
	public static void main(String[] args) {
		File dir = new File("src");// 当前目录下名为src的文件夹
		FileDemo fileDemo = new FileDemo();
		fileDemo.showFile(dir);
	}

	public void showFile(File dir) {
		// 通过递归列出所有文件
		File[] files = dir.listFiles();

		for (File file : files) {
			if (file.isDirectory())
				showFile(file);
			else
				System.out.println(file);
			// 若不想看到路径,可用file.getName()仅显示文件名
		}
	}
}