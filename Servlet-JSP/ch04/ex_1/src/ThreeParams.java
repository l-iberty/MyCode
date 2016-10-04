package coreservlets;

import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class ThreeParams extends HttpServlet {
	public void doGet(HttpServletRequest request, HttpServletResponse response)
		throws ServletException, IOException {

		response.setContentType("text/html");
		PrintWriter out = response.getWriter();
		String title = "Reading Three Request Parameters";

		out.println(ServletUtilities.headWithTitle(title) +
					"<body>\n" +
					"<h1>" + title + "</h1>\n" +
					"<ul>\n" +
					"<li><b>Param1</b>: " + request.getParameter("param1") + "</li>\n" +
					"<li><b>Param2</b>: " + request.getParameter("param2") + "</li>\n" +
					"<li><b>Param3</b>: " + request.getParameter("param3") + "</li>\n" +
					"</ul>\n" +
					"</body></html>\n");
		out.close();	
	}	
}