package coreservlets;

import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.util.*;

public class ShowRequestHeaders extends HttpServlet {
    @Override
    public void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        String title = "Servlet Example: Showing Request Headers";
        out.println("<html>\n" +
                "<head><title>" + title + "</title></head>\n" +
                "<body>\n" +
                "<h1>" + title + "</h1>\n" +
                "<b>Request Method: </b>" + request.getMethod() + "</br>\n" +
                "<b>Request URI: </b>" + request.getRequestURI() + "</br>\n" +
                "<b>Request Protocol: </b>" + request.getProtocol() + "</br></br>\n" +
                "<table>\n" +
                "<tr>\n" +
                "<th>Header Name</th>\n" +
                "<th>Header Value</th>\n" +
                "</tr>\n");

        Enumeration<String> headerNames = request.getHeaderNames();
        while (headerNames.hasMoreElements()) {
            String headerName = headerNames.nextElement();
            out.println("<tr>\n" +
                    "<td>" + headerName + "</td>\n" +
                    "<td>" + request.getHeader(headerName) + "</td>\n" +
                    "</tr>\n");
        }
        out.println("</table>\n</body></html>");
    }

    /*
    * Since this servlet is for debugging, have it
    * handle GET and POST identically.
    * */
    @Override
    public void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        doGet(request, response);
    }
}
