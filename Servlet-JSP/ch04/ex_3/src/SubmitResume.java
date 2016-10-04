package coreservlets;

import java.io.*;
import java.util.StringTokenizer;
import javax.servlet.*;
import javax.servlet.http.*;

public class SubmitResume extends HttpServlet {
	public void doGet(HttpServletRequest request, HttpServletResponse response)
		throws ServletException, IOException {

		response.setContentType("text/html");
		PrintWriter out = response.getWriter();
		if (request.getParameter("previewBtn") != null) {
			//
			showReview(request, out);
		}
		else {
			showConfirmation(request, out);
		}
	}

	private void showReview(HttpServletRequest request, PrintWriter out) {
		String headingFont = request.getParameter("headingFont");
		headingFont = replaceIfMissingOfDefault(headingFont, "");

		int headingSize = getSize(request.getParameter("headingSize"), 32);

		String bodyFont = request.getParameter("bodyFont");
		bodyFont = replaceIfMissingOfDefault(bodyFont, "");

		int bodySize = getSize(request.getParameter("bodySize"), 18);

		String fgColor = request.getParameter("fgColor");
		fgColor = replaceIfMissing(fgColor, "black");

		String bgColor = request.getParameter("bgColor");
		bgColor = replaceIfMissing(bgColor, "white");

		String name = request.getParameter("name");
		name = replaceIfMissing(name, "Empty Name");

		String title = request.getParameter("title");
		title = replaceIfMissing(title, "Empty Title");

		String email = request.getParameter("email");
		email = replaceIfMissing(email, "Empty Email");

		String languages = request.getParameter("languages");
		languages = replaceIfMissing(languages, "No Languages");
		String languageList = makeList(languages);

		String skills = request.getParameter("skills");
		skills = replaceIfMissing(skills, "No Skills");

		String header = ServletUtilities.headWithTitle("Resume for " + name);
		String styleSheet = makeStyleSheet(headingFont, headingSize,
								bodyFont, bodySize,
								fgColor, bgColor);
		String header2 = header + styleSheet + "</head>\n";
		out.println(header2 +
					"<body>\n" +
					"<h1>Resume for " + name + "</h1>\n" +
					"<center>\n" +
					"<span class=\"heading-1\">" + name + "</span></br>\n" +
					"<span class=\"heading-2\">" + title + "</span></br>\n" +
					"<span><a href=\"mailto:" + email + "\">" + email + "</a></span>\n" +
					"</center></br></br>\n" +
					"<span class=\"heading-3\">" + "Programming Languages" + "</span>\n" +
					languageList + "</br></br>\n" +
					"<span class=\"heading-3\">" + "Skills and Experience" + "</span></br></br>\n" +
					skills + "\n" +
					"</body></html>");
		out.close();
	}

	private String makeStyleSheet(String headingFont, int heading1Size,
								String bodyFont, int bodySize,
								String fgColor, String bgColor) {
		int heading2Size = heading1Size * 7 / 10;
		int heading3Size = heading1Size * 6 / 10;

		String styleSheet = 
			"<style type=\"text/css\">\n" +
			".heading-1 {" +
						"font-size:" + heading1Size + "pt;\n" +
						"font-weight: bold;\n" +
						"font-family: " + headingFont + "Georgia,Verdana,Arial,Helvetica,sans-serif;\n" +
						"}\n" +
			".heading-2 {" +
						"font-size:" + heading2Size + "pt;\n" +
						"font-weight: bold;\n" +
						"font-family: " + headingFont + "Georgia,Verdana,Arial,Helvetica,sans-serif;\n" +
						"}\n" +
			".heading-3 {" +
						"font-size:" + heading3Size + "pt;\n" +
						"font-weight: bold;\n" +
						"font-family: " + headingFont + "Georgia,Verdana,Arial,Helvetica,sans-serif;\n" +
						"}\n" +
			".body {" +
						"color: " + fgColor + ";\n" +
						"background-color: " + bgColor + ";\n" +
						"font-size: " + bodySize + "pt;\n" +
						"font-family: " + bodyFont + "Georgia,Verdana,Arial,Helvetica,sans-serif;\n" +
						"}\n" +
			"a:hover { color: red; }\n" +
			"</style>";

			return styleSheet;
	}

	private String replaceIfMissing(String orig, String replacement) {
		if ((orig == null) || (orig.trim().equals("")))
			return replacement;
		else
			return orig;
	}
	// Replace the null strings, empty strings

	private String replaceIfMissingOfDefault(String orig, String replacement) {
		if ((orig == null) ||
			(orig.trim().equals("")) ||
			(orig.equals("default"))) {

			return replacement;
		}
		else {
			return orig + ",";
		}
	}

	private int getSize(String size, int defaultSize) {
		try {
			return Integer.parseInt(size);
		} catch (NumberFormatException nfe) {
			return defaultSize;
		}
	}

	private String makeList(String listItems) {
		StringTokenizer token = new StringTokenizer(listItems, ",");
		String list = "<ul>\n";
		while (token.hasMoreTokens()) {
			list = list + "<li>" + token.nextToken() + "</li>\n";
		}
		list += "</ul>";

		return list;
	}

	private void showConfirmation(HttpServletRequest request, PrintWriter out) {
		String title = "Submission Confirmed";
		out.println(ServletUtilities.headWithTitle(title) +
					"<body>\n" +
					"<h1>" + title + "</h1>" +
					"Your resume should appear online within\n" +
					"24 hours. If it doesn't, try submitting\n" +
					"again with a different email address.\n" +
					"</body></html>");
		out.close();
	}
}