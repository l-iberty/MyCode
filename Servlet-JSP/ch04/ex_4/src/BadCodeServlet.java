package coreservlets;

import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class BadCodeServlet extends HttpServlet {
	public void doGet(HttpServletRequest request, HttpServletResponse response)
		throws ServletException, IOException {

			response.setContentType("text/html");
			PrintWriter out = response.getWriter();
			String title = "Code Sample";

			out.println(ServletUtilities.headWithTitle(title) +
						"<body style=\"background-color: #FDF5E6\">\n" +
						"<h1 style=\"text-align:center\">" + title + "</h1>\n" +
						"<pre>\n" +
						getCode(request) +
						"</pre>\n" +
						"</body></html>");
			out.close();
	}

	private String getCode(HttpServletRequest request) {
		return request.getParameter("code");
	}
}