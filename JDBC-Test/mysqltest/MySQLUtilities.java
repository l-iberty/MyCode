package mysqltest;

public class MySQLUtilities {
	private static String driverClass = "com.mysql.jdbc.Driver";
	private static String url = "jdbc:mysql://[$host]:3306/[$dbName]";

	public static String makeURL(String host, String dbName) {
		StringBuffer urlbuff = new StringBuffer(url);
		MySQLUtilities.replace(urlbuff, "[$host]", host);
		MySQLUtilities.replace(urlbuff, "[$dbName]", dbName);

		return urlbuff.toString();
	}

	public static String getDriverClass() {
		return driverClass;
	}

	private static void replace(StringBuffer buffer, String match, String value) {
		int index = buffer.toString().indexOf(match);
		buffer.replace(index, index + match.length(), value);
	}
}