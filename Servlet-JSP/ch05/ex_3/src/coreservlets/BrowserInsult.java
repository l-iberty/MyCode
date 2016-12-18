package coreservlets;

import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class BrowserInsult extends HttpServlet {
    @Override
    public void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        String title = null;
        String message = null;
        String userAgent = request.getHeader("User-Agent");
        if ((userAgent != null) && (userAgent.contains("Mozilla"))) {
            title = "Mozilla";
            message = "Mozilla";
        }
        if ((userAgent != null) && (userAgent.contains("AppleWebKit"))) {
            title += ", AppleWebKit";
            message += ", AppleWebKit";
        }
        if ((userAgent != null) && (userAgent.contains("AppleWebKit"))) {
            title += ", Chrome";
            message += ", Chrome";
        }

        out.println("<html><head><title>" + title + "</title></head>\n" +
                "<body>" + message + "</body></html>");
    }
}
