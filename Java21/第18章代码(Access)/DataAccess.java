import java.sql.*;
import java.io.*;

public class DataAccess{
	public void dataWrite(){
		try{
			String dbur = "jdbc:odbc:driver={Microsoft Access Driver (*.mdb)};DBQ=c://Users//len//Desktop//Program//sample.mdb";  
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver"); 
			Connection conn = DriverManager.getConnection(dbur,"","");
			PreparedStatement prep = conn.prepareStatement("insert into sample.Table values(?,?,?,?,?,?,?)");
			                                                // 若连接方式为OBDC，sample.Table替换为数据源引用
			prep.setString(1, "3");
			prep.setString(2, "$6.45");
			prep.setString(3, "$4.40");
			prep.setString(4, "2003/03/22/");
			prep.setString(5, "$0.33");
			prep.setString(6, "$5.50");
			prep.setString(7, "$6.09");
			prep.executeUpdate();
			
			conn.close();
			prep.close();
			
		}catch(SQLException e){
			System.out.println(e);
		}catch(ClassNotFoundException e){
			System.out.println(e);
		}
	}
	
	public static void main(String[] arg){
		DataAccess da = new DataAccess();
		da.dataWrite();
	}
}