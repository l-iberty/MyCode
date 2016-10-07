package coreservlets;

import java.io.*;
import java.sql.SQLException;
import javax.servlet.ServletException;
import javax.servlet.http.*;
import coreservlets.util.*;

public class QueryServlet extends HttpServlet {
	private DatabaseUtilities database = new DatabaseUtilities("directory");
	private String script =
				"<script>" +
					"alert(\"You entered nothing! Back to the original page!\");" +
					"window.location.href = \"../../../MyPage/index.html\";" +
				"</script>";
	private String link = "<a href=\"../../../MyPage/index.html\">Back to original page</a>";

	@Override
	public void doGet(HttpServletRequest request, HttpServletResponse response)
		throws ServletException, IOException{
		String name = request.getParameter("name");
		response.setContentType("text/html");
		PrintWriter out = response.getWriter();

		if ((name == null) || name.equals("")) {
			out.println(script);
			out.close();
			return;
		}

		try {
			String origRecords = database.queryRecords("table_1", name);
			String fmtRecords = DatabaseReader.getFmtRecords(origRecords);
			out.println(fmtRecords);
			out.println(link);
		} catch (SQLException e) {
			out.println("Database Error!");
		} finally {
			out.close();
		}
	}
}