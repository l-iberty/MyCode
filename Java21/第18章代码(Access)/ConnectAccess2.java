import java.sql.*;

public class ConnectAccess2{
	public static void main(String[] arg){
		ConnectAccess2 ca = new ConnectAccess2();
		ca.ConnectAccessDataSource();
	}
	
	
    public void ConnectAccessDataSource(){  
        
		try{
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");  
            /** 
             * 采用ODBC连接方式 如何建立ODBC连接？ 
             * 答：在windows下，【开始】->【控制面板】->【性能和维护】->【管理工具】->【数据源】，在数据源这里添加一个指向quotedata.mdb文件的数据源。 
             * 比如创建名字为quotedata_ptr 
             */ 
            String dbur = "jdbc:odbc:quotedata_ptr"; // 此为ODBC连接方式  
            Connection conn = DriverManager.getConnection(dbur, "", "");  
            Statement stmt = conn.createStatement();  
            ResultSet rs = stmt.executeQuery("select * from Stocks");  
            while (rs.next()) {  
                System.out.println("\ndex:" + rs.getString(1));
                System.out.println("ticker:" + rs.getString(2));
                System.out.println("price:$" + rs.getString(3));
                System.out.println("quoteData:" + rs.getString(4)); 
			    System.out.println("change:$0" + rs.getString(5)); 			
            }  
            rs.close();  
            stmt.close();  
            conn.close();
			
		}catch(SQLException e){
			System.out.println("SQL Error:" + e.getMessage());
		}catch(ClassNotFoundException e){
			System.out.println(e);
		}
	}	
}