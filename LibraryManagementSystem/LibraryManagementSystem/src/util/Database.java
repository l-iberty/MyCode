/**
 * 数据库操作类，封装MySQL的连接管理和增删改查操作
 */
package util;

import java.sql.*;
import java.util.*;

public class Database {
    private String driverClass;
    private String url;
    private String username;
    private String passwd;

    public Database(String username, String passwd, String hostname, String dbName) {
        this.driverClass = MysqlUtilities.getDriverClass();
        this.url = MysqlUtilities.makeURL(hostname, dbName);
        this.username = username;
        this.passwd = passwd;
    }

    /**
     * @param tbName    数据表名
     * @param colNames  列名, 遵循sql语法, 形如 "(colname1,colname2,colname3)"
     * @param colValues 列值, 遵循sql语法, 与列名一一对应, 形如 "(\'123\',\'abc\',\'1a2b\')"
     */
    public void insert(String tbName, String colNames, String colValues) {
        Connection conn;

        conn = getConnection();
        if (conn == null) {
            System.err.println("Cannot get connection!");
            return;
        }

        try {
            Statement stm = conn.createStatement();
            // 组装sql语句
            String sql = "INSERT INTO " + tbName + " ";
            sql += colNames + " VALUES " + colValues;
            // 执行
            stm.execute(sql);
        } catch (SQLException e) {
            System.err.println("Error inserting: " + e.getMessage());
        } finally {
            closeConnection(conn);
        }
    }

    /**
     * @param tbName     数据表名
     * @param colNames   列名, 遵循sql语法, 以逗号隔开, 形如 "colname1,colname2,colname3"; 或为通配符 "*"
     * @param conditions 查询条件, 遵循sql语法, 形如 "colname1=value1 and colname2=value2"
     * @return 将查询结果组装为易读的字符串, 调用者可以直接使用而无须临行解析
     */
    public String query(String tbName, String colNames, String conditions) {
        Connection conn;
        String ret = "";

        conn = getConnection();
        if (conn == null) {
            return null;
        }

        try {
            Statement stm = conn.createStatement();
            // 组装sql语句
            String sql = "SELECT " + colNames + " FROM " + tbName;
            if (conditions != null)
                sql += " WHERE " + conditions;
            // 执行查询
            ResultSet resultSet = stm.executeQuery(sql);
            ResultSetMetaData metaData = resultSet.getMetaData();

            // 将查询结果格式化为html表格的形式
            int colNum = metaData.getColumnCount();

            while (resultSet.next()) {
                /*for (int i = 1; i <= colNum; i++) {
                    ret += metaData.getColumnName(i) + ": " + resultSet.getString(i) + "\n";
                }
                ret += "\n";*/
                ret += "<table>";
                for (int i = 1; i <= colNum; i++) {
                    ret += "<tr><td><b>" + metaData.getColumnName(i) + "</b></td>";
                    ret += "<td>" + resultSet.getString(i) + "</td></tr>";
                }
                ret += "</table><hr/>";
            }


            if (!ret.contains("<td>")) {
                // Empty set
                ret = null;
            }
        } catch (SQLException e) {
            System.err.println("Error querying: " + e.getMessage());
        } finally {
            closeConnection(conn);
        }
        return ret;
    }

    /**
     * @param tbName     数据表名
     * @param conditions 查询条件, 遵循sql语法
     */
    public void delete(String tbName, String conditions) {
        Connection conn;

        conn = getConnection();
        if (conn == null) {
            System.err.println("Cannot get connection!");
            return;
        }

        try {
            Statement stm = conn.createStatement();
            // 组装sql语句
            String sql = "DELETE FROM " + tbName;
            if (conditions != null && !conditions.trim().equals("")) {
                sql += " WHERE " + conditions;
            }
            // 执行
            stm.execute(sql);
        } catch (SQLException e) {
            System.err.println("Error deleting: " + e.getMessage());
        } finally {
            closeConnection(conn);
        }
    }

    /**
     * @param tbName     数据表名
     * @param colNames   列名, 以逗号隔开, 形如 "colname1,colname2,colname3"
     * @param colValues  新的列值, 以逗号隔开, 与列名一一对应, 形如 "\'123\',\'abc\',\'1a2b\'"
     * @param conditions 更新条件, 遵循sql语法
     */
    public void update(String tbName, String colNames, String colValues, String conditions) {
        Connection conn;
        List<String> colNameList;
        List<String> colValueList;

        conn = getConnection();
        if (conn == null) {
            System.err.println("Cannot get connection!");
            return;
        }

        if (conditions == null || conditions.trim().equals("")) {
            System.err.println("No conditions!");
            return;
        }

        // 解析列名与列值, 用于组装sql语句
        colNameList = new LinkedList<>();
        colValueList = new LinkedList<>();
        if (colNames.contains(",") && colValues.contains(",")) {
            StringTokenizer token1 = new StringTokenizer(colNames, ",");
            StringTokenizer token2 = new StringTokenizer(colValues, ",");
            while (token1.hasMoreTokens() && token2.hasMoreTokens()) {
                colNameList.add(token1.nextToken());
                colValueList.add(token2.nextToken());
            }
        } else {
            colNameList.add(colNames);
            colValueList.add(colValues);
        }

        try {
            Statement stm = conn.createStatement();
            // 组装sql语句
            StringBuilder sql = new StringBuilder("UPDATE " + tbName + " SET ");
            for (int i = 0; i < colNameList.size(); i++) {
                sql.append(colNameList.get(i) + "=" + colValueList.get(i) + ",");
            }
            int index = sql.lastIndexOf(",");
            sql.replace(index, index + 1, "");
            sql.append(" WHERE " + conditions);
            // 执行
            stm.execute(sql.toString());
        } catch (SQLException e) {
            System.err.println("Error updating: " + e.getMessage());
        } finally {
            closeConnection(conn);
        }
    }

    /**
     * 连接数据库
     *
     * @return 返回可用的Connection对象, 若连接失败则返回null
     */
    private Connection getConnection() {
        Connection conn = null;

        try {
            Class.forName(driverClass); //加载驱动程序类
            conn = DriverManager.getConnection(url, username, passwd); //连接数据库
        } catch (ClassNotFoundException e) {
            System.err.println("Error loading driverClass: " + e.getMessage());
        } catch (SQLException e) {
            System.err.println("Error connecting: " + e.getMessage());
        }
        return conn;
    }

    /**
     * 关闭数据库连接
     *
     * @param conn 由 getConnection() 返回的Connection对象
     */
    private void closeConnection(Connection conn) {
        try {
            conn.close();
        } catch (SQLException e) {
            System.err.println("Error closing: " + e.getMessage());
            conn = null;
        }
    }
}
