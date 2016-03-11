import java.sql.*;  

public class ConnectAccess {  
    public static void main(String args[]) {  
        ConnectAccess ca = new ConnectAccess();  
        ca.ConnectAccessFile(); 
    }
	
    public void ConnectAccessFile(){
		try{
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");  
          
            String dbur = "jdbc:odbc:driver={Microsoft Access Driver (*.mdb)};DBQ=c://Users//len//Desktop//Program//quotedata.mdb";  
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
