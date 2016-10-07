package coreservlets;

import java.io.*;
import java.sql.SQLException;
import javax.servlet.ServletException;
import javax.servlet.http.*;
import coreservlets.util.DatabaseUtilities;

public class DeleteServlet extends HttpServlet {
	private DatabaseUtilities database = new DatabaseUtilities("directory");
	private String script1 =
				"<script>" +
					"alert(\"You entered nothing! Back to the original page!\");" +
					"window.location.href = \"../../../MyPage/index.html\";" +
				"</script>";
	private String script2 =
				"<script>" +
					"alert(\"Record Deleted!\");" +
					"window.location.href = \"../../../MyPage/index.html\";" +
				"</script>";

	@Override
	public void doGet(HttpServletRequest request, HttpServletResponse response)
		throws ServletException, IOException {
		String name = request.getParameter("name");
		response.setContentType("text/html");
		PrintWriter out = response.getWriter();

		if ((name == null) || name.equals("")) {
			out.println(script1);
			out.close();
			return;
		}

		try {
			database.deleteRecords("table_1", name);
			out.println(script2);
		} catch (SQLException e) {
			out.println("Database Error!");
		} finally {
			out.close();
		}
	}
}