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
             * ����ODBC���ӷ�ʽ ��ν���ODBC���ӣ� 
             * ����windows�£�����ʼ��->��������塿->�����ܺ�ά����->�������ߡ�->������Դ����������Դ�������һ��ָ��quotedata.mdb�ļ�������Դ�� 
             * ���紴������Ϊquotedata_ptr 
             */ 
            String dbur = "jdbc:odbc:quotedata_ptr"; // ��ΪODBC���ӷ�ʽ  
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