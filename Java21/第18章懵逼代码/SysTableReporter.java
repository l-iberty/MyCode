import java.sql.*;

public class SysTableReporter{
    public static void main(String[] arg){
        String data = "jdbc:derby://localhost:1527/sample";
        try(Connection conn = DriverManager.getConnection(data, "app", "APP");
            Statement st = conn.createStatement();){
            
            Class.forName("org.apache.derby.jdbc.ClientDriver");
            
            ResultSet rec = st.executeQuery("select * " +"from SYS.SYSTABLES"
                                            + "order by TABLENAME");
            while(rec.next()){
                System.out.println("TABLEID:\t" + rec.getString(1));
                System.out.println("TABLENAME:\t" + rec.getString(2));
                System.out.println("TABLETYPE:\t" + rec.getString(3));
                System.out.println("SCHEMAID:\t" + rec.getString(4));
            }
            st.close();
        }catch(SQLException e){
            System.out.println("SQL ERROR:" + e.getErrorCode());
            System.out.println("SQL ERROR:" + e.getSQLState());
        }catch(Exception e){
            System.out.println("ERROR:" + e.getMessage());
        }
    }
}