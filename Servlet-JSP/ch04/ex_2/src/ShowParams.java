package coreservlets;

import java.io.*;
import java.util.Enumeration;
import javax.servlet.*;
import javax.servlet.http.*;

public class ShowParams extends HttpServlet {
	public void doGet(HttpServletRequest request, HttpServletResponse response)
		throws ServletException, IOException {

		response.setContentType("text/html");
		PrintWriter out = response.getWriter();
		String title = "Reading All Request Parameters";

		out.println(ServletUtilities.headWithTitle(title) +
					"<body>\n" +
					"<h1>" + title + "</h1>\n" +
					"<table border=\"1\">\n" +
					"<tr>\n" +
					"<th>Parameter Name</th>\n" +
					"<th>Parameter Value(s)</th>\n" +
					"</tr>");

		Enumeration paramNames = request.getParameterNames();
		while(paramNames.hasMoreElements()) {
			String paraName = (String)paramNames.nextElement();
			out.println("<tr><td>" + paraName + "</td>");

			String[] paramValues = request.getParameterValues(paraName);
			if (paramValues.length == 1) {
				String paramValue = paramValues[0];
				if (paramValue.length() == 0)
					out.println("<td><i>No Value</i></td>");
				else
					out.println("<td>" + paramValue + "</td>");
			}
			else {
				out.println("<td><ul>");
				for (int i = 0; i < paramValues.length; i++) {
					out.println("<li>" + paramValues[i] + "</li>");
				}
				out.println("</ul></td>");
			}
			out.println("</tr>");
		}
		out.println("</table>\n</body></html>");
		out.close();	
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
		throws ServletException, IOException {

		doGet(request, response);
	}
}