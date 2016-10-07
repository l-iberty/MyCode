package coreservlets;

import java.io.*;
import java.sql.SQLException;
import javax.servlet.ServletException;
import javax.servlet.http.*;
import coreservlets.util.DatabaseUtilities;

public class IndexInfo extends HttpServlet {
	@Override
	public void doGet(HttpServletRequest request, HttpServletResponse response)
		throws ServletException, IOException {
		String name = request.getParameter("name");
		String tel = request.getParameter("tel");
		String tbName = "table_1";

		response.setContentType("text/html");
		PrintWriter out = response.getWriter();

		/*
		 *Make sure that the MySQL service has already been startted, and the
		 *database named "directory" has already been created, unless the following
		 *operations will throw exceptions.
		 */
		try {
			DatabaseUtilities database = new DatabaseUtilities("directory");
			database.createTable(tbName);
			database.addRecords(tbName, name, tel);

			String title0 = "Information submitted!";
			String title1 = "Nothing to submit!";
			boolean hasValue = ((name != null) && !name.equals("")) &&
							   ((tel != null) && !tel.equals(""));
			String title = hasValue ? title0 : title1;
			out.println(ServletUtilities.headWithTitle(title) +
						"<body><center>\n" +
						"<h1>" + title + "</h1>\n" +
						"<a href=\"../../../MyPage/index.html\">Add Information</a></br>" +
						"<a href=\"../../../MyPage/delete.jsp\">Delete Information</a></br>" +
						"<a href=\"../../../MyPage/query.html\">Query Information</a></br>" +
						"<a href=\"../../../MyPage/modify.html\">Modify Information</a></br>" +
						"</center></body></html>\n");
		} catch (SQLException e) {
			String title = "Error submitting! Database Error!";
			out.println(ServletUtilities.headWithTitle(title) +
						"<body><center>\n" +
						"<h1>" + title + "</h1>\n" +
						"</center></body></html>\n");
		} finally {
			out.close();
		}
	}
}