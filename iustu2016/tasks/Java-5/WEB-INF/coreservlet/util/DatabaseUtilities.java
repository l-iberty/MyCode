package coreservlets.util;

import java.sql.*;

public class DatabaseUtilities {
	private String dbName;

	public DatabaseUtilities(String dbName) {
		this.dbName = dbName;
	}

	public void createTable(String tbName) throws SQLException {
		if (isExisted(tbName)) {
			return;
		}

		Connection connection = getConnection();
		if (connection == null) {
			return;
		}

		String format = " (name VARCHAR(12), tel VARCHAR(12))";
		String cmd = "CREATE TABLE " + tbName + format;
		Statement statement = connection.createStatement();
		statement.execute(cmd);

		closeConnection(connection);
	}

	public boolean isExisted(String tbName) {
		boolean returnValue = false;
		Connection connection = getConnection();
		if (connection == null) {
			return returnValue;
		}

		try {
			String cmd = "SELECT * FROM " + tbName;
			Statement statement = connection.createStatement();
			ResultSet resultSet = statement.executeQuery(cmd);

			returnValue = resultSet.next();
			return returnValue;
		} catch (SQLException e) {
			returnValue = false;
			return returnValue;
		} finally {
			return returnValue;
		}
	}

	public String getRecords(String tbName) throws SQLException {
		Connection connection = getConnection();
		if (connection == null) {
			return null;
		}

		String cmd = "SELECT * FROM " + tbName;

		Statement statement = connection.createStatement();
		ResultSet resultSet = statement.executeQuery(cmd);

		StringBuffer results = new StringBuffer();
		while (resultSet.next()) {
			results.append("<b>name</b>: ");
			results.append(resultSet.getString(1));
			results.append(", <b>tel</b>: ");
			results.append(resultSet.getString(2));
			results.append(";");
		}
		closeConnection(connection);

		return results.toString();
	}

	public void addRecords(String tbName, String name, String tel) throws SQLException {
		Connection connection = getConnection();
		if (connection == null) {
			return;
		}

		boolean hasName = !((name == null) || name.equals(""));
		boolean hasTel = !((tel == null) || tel.equals(""));
		if (!hasName || !hasTel) {
			return;
		}

		String fmt_name = "'" + name + "'";
		String fmt_tel = "'" + tel + "'";
		String values = "(" + fmt_name + "," + fmt_tel + ")";
		String cmd = "INSERT INTO " + tbName + " (name, tel)" + " VALUES " + values;

		Statement statement = connection.createStatement();
		statement.execute(cmd);
		closeConnection(connection);
	}

	public void deleteRecords(String tbName, String name) throws SQLException {
		Connection connection = getConnection();
		if (connection == null) {
			return;
		}

		String fmt_name = "'" + name + "'";
		String condition = "(name=" + fmt_name + ")";
		String cmd = "DELETE FROM " + tbName + " WHERE " + condition;

		Statement statement = connection.createStatement();
		statement.execute(cmd);
		closeConnection(connection);
	}

	public String queryRecords(String tbName, String name) throws SQLException {
		Connection connection = getConnection();
		if (connection == null) {
			return null;
		}

		String fmt_name = "'" + name + "'";
		String condition = "(name=" + fmt_name + ")";
		String cmd = "SELECT * FROM " + tbName + " WHERE " + condition;

		Statement statement = connection.createStatement();
		ResultSet resultSet = statement.executeQuery(cmd);

		StringBuffer results = new StringBuffer();
		while (resultSet.next()) {
			results.append("<b>name</b>: ");
			results.append(resultSet.getString(1));
			results.append(", <b>tel</b>: ");
			results.append(resultSet.getString(2));
			results.append(";");
		}
		closeConnection(connection);

		return results.toString();
	}

	public void modifyRecords(String tbName, String name, String newTel) throws SQLException {
		Connection connection = getConnection();
		if (connection == null) {
			return;
		}

		String fmt_name = "'" + name + "'";
		String fmt_newTel = "'" + newTel + "'";
		String newValue = "tel=" + fmt_newTel;
		String condition = "(name=" + fmt_name + ")";
		String cmd = "UPDATE " + tbName + " SET " + newValue + " WHERE " + condition;

		Statement statement = connection.createStatement();
		statement.execute(cmd);
		closeConnection(connection);
	}

	private Connection getConnection() {
		String host = "localhost";
		String username = "root";
		String password = "2015Liberty";
		String driverClass = "com.mysql.jdbc.Driver";
		String urlPattern = "jdbc:mysql://[$host]:3306/[$dbName]";
		String url = makeURL(urlPattern, host, dbName);

		try {
			Class.forName(driverClass);
			Connection connection = DriverManager.getConnection(url, username, password);
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

	private String makeURL(String urlPattern, String host, String dbName) {
		StringBuffer urlbuff = new StringBuffer(urlPattern);
		replace(urlbuff, "[$host]", host);
		replace(urlbuff, "[$dbName]", dbName);

		return urlbuff.toString();
	}

	private void replace(StringBuffer buffer, String match, String value) {
		int index = buffer.toString().indexOf(match);
		buffer.replace(index, index + match.length(), value);
	}
}