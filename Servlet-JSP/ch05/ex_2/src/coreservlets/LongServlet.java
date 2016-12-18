package coreservlets;

import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class LongServlet extends HttpServlet {
    @Override
    public void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html");

        /**
         * Change the definition of "out" depending on
         * whether or not the gzip is supported.
         */
        PrintWriter out;
        if (GzipUtilities.isGzipSupported(request) &&
                !GzipUtilities.isGzipDisabled(request)) {
            out = GzipUtilities.getGzipWriter(response);
            response.setHeader("Content-Encoding", "gzip");
        } else {
            out = response.getWriter();
        }

        String title = "Long Page";
        out.println("<html>\n" +
                "<head><title>" + title + "</title></head>\n" +
                "<body>\n" +
                "<h1>" + title + "</h1>\n");
        String line = "Blah,Blah,yadda,yadda";
        for (int i = 0; i < 10000; i++) {
            out.println(line);
        }
        out.println("</body></html>");
        out.close(); // Needed for gzip, optional otherwise.
    }
}
