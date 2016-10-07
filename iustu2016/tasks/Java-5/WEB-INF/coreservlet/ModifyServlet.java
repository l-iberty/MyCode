package coreservlets;

import java.io.*;
import java.sql.SQLException;
import javax.servlet.ServletException;
import javax.servlet.http.*;
import coreservlets.util.*;

public class ModifyServlet extends HttpServlet {
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
		String newTel = request.getParameter("newTel");
		response.setContentType("text/html");
		PrintWriter out = response.getWriter();

		boolean hasName = (name != null) && !name.equals("");
		boolean hasNewTel = (newTel != null) && !newTel.equals("");
		if (!hasName || !hasNewTel) {
			out.println(script);
			out.close();
			return;
		}

		try {
			database.modifyRecords("table_1", name, newTel);
			out.println("Record has been updated!");
			out.println(link);
		} catch (SQLException e) {
			out.println("Database Error!");
		} finally {
			out.close();
		}
	}
}