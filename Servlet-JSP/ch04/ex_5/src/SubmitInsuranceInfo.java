package coreservlets;

import java.io.*;
import javax.servlet.ServletException;
import javax.servlet.http.*;
import coreservlets.beans.*;
import coreservlets.ServletUtilities;

public class SubmitInsuranceInfo extends HttpServlet {
	@Override
	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		InsuranceInfo info = new InsuranceInfo();
		BeanUtilities.populateBean(info, request);
		response.setContentType("text/html");
		PrintWriter out = response.getWriter();
		String title = "Insurance Info for " + info.getName();

		out.println(ServletUtilities.headWithTitle(title) +
					"<body>\n" +
					"<h1>" + title + "</h1>\n" +
					"<ul>\n" +
					"<li>Employee ID: " + info.getEmployeeID() + "</li>\n" +
					"<li>Number of children: " + info.getNumChildren() + "</li>\n" +
					"<li>Married?: " + info.isMarried() + "</li>\n" +
					"</ul></body></html>");
		out.close();	
	}
}