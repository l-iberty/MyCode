package mysqltest;

import java.sql.*;

public class DataBaseTest {
	private String driverClass;
	private String url;
	private String username;
	private String password;

	public DataBaseTest(String driverClass, String url, String username, String password) {
		this.driverClass = driverClass;
		this.url = url;
		this.username = username;
		this.password = password;
	}

	public void testConnection() {
		System.out.println("Testing database connection...");
		Connection connection = getConnection();
		if (connection == null) {
			System.out.println("Test failed.\n");
			return;
		}

		try {
			DatabaseMetaData dbMetaData = connection.getMetaData();
			// DatabaseMetaData接口提供了一组用以获取数据库信息的方法
			String productName = dbMetaData.getDatabaseProductName();
			String productVersion = dbMetaData.getDatabaseProductVersion();
			String driverName = dbMetaData.getDriverName();
			String driverVersion = dbMetaData.getDriverVersion();
			System.out.println("Product Name: " + productName);
			System.out.println("Product Version: " + productVersion);
			System.out.println("Driver Name: " + driverName);
			System.out.println("Driver Version: " + driverVersion);
		} catch (SQLException e) {
			System.err.println("Error connecting: " + e);
		} finally {
			closeConnection(connection);
		}
	}

	public void createTable() {
		System.out.println("\nCreating authors table...");
		Connection connection = getConnection();
		if (connection == null) {
			System.out.println("Failure");
			return;
		}

		try {
			String format =
				"(id INT, name VARCHAR(12))";
			String[] records = {"(1, 'Marty')", "(2, 'Larry')", "(3, 'Roman')"};
			Statement statement = connection.createStatement();
			
			// 保证不重复建表
			try {
				statement.execute("DROP TABLE authors");
			} catch (SQLException e) {
				// do nothing
			}

			String createCommand = "CREATE TABLE authors " + format;
			statement.execute(createCommand);

			String insertPrefix = "INSERT INTO authors (id,name) VALUES ";
			for (int i = 0; i < records.length; i++) {
				statement.execute(insertPrefix + records[i]);
			}
			System.out.println("Successful");
		} catch (SQLException e) {
			System.err.println("Error creating table: " + e);
		} finally {
			closeConnection(connection);
		}
	}

	public void executeQuery() {
		System.out.println("\nQuerying authors table...");
		Connection connection = getConnection();
		if (connection == null) {
			System.out.println("Failure");
			return;
		}

		try {
			Statement statement = connection.createStatement();
			String query = "SELECT * FROM authors";
			ResultSet resultSet = statement.executeQuery(query);
			ResultSetMetaData resultSetMetaData = resultSet.getMetaData();
			int columnCount = resultSetMetaData.getColumnCount();

			System.out.println("columnCount: " + columnCount);
			while (resultSet.next()) {
				System.out.println("id: " + resultSet.getInt(1));
				System.out.println("name: " + resultSet.getString(2));
			}
		} catch (SQLException e) {
			System.err.println("Error executing query");
		} finally {
			closeConnection(connection);
		}
	}

	public Connection getConnection() {
		try {
			Class.forName(driverClass);// 加载驱动程序类到Java解释器中
			Connection connection = DriverManager.getConnection(url, username, password);// 连接数据库
			return connection;
		} catch (ClassNotFoundException e) {
			System.err.println("Error loading driverClass: " + e);
			return null;
		} catch (SQLException e) {
			System.err.println("Error connecting: " + e);
			return null;
		}
	}

	private void closeConnection(Connection connection) {
		try {
			connection.close();
		} catch (SQLException e) {
			System.err.println("Error closing: " + e);
			connection = null;
		}
	}

	public static void main(String[] args) {
		if (args.length < 4) {
			System.out.println("arguments: [host] [database_name] [username] [password]");
			return;
		}

		String driverClass = MySQLUtilities.getDriverClass();
		String host = args[0];
		String dbName = args[1];
		String url = MySQLUtilities.makeURL(host, dbName);
		String username = args[2];
		String password = args[3];

		DataBaseTest database = new DataBaseTest(driverClass, url, username, password);
		database.testConnection();
		database.createTable();
		database.executeQuery();
	}
}