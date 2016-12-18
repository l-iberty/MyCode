package coreservlets;

import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.net.*;

/**
 * Servlet that takes a search string and a search engine name,
 * sending the query to that search engine. Illustrates
 * manipulating the response status code. It send a 302 response
 * code(via sendRedirect) if given a known search engine, and
 * send a 404 response code(via sendError) otherwise.
 */

public class SearchEngines extends HttpServlet {
    @Override
    public void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        String searchString = request.getParameter("searchString");
        if ((searchString == null) || (searchString.length() == 0)) {
            reportProblem(response, "Missing search string");
            return;
        }
        searchString = URLEncoder.encode(searchString, "UTF-8");

        String searchEngineName = request.getParameter("searchEngine");
        if ((searchEngineName == null) || (searchEngineName.length() == 0)) {
            reportProblem(response, "Missing engine name");
            return;
        }

        String searchURL = SearchUtilities.makeURL(searchEngineName, searchString);
        if (searchURL != null) {
            response.sendRedirect(searchURL);
        } else {
            reportProblem(response, "Unrecognized search engine");
        }
    }

    private void reportProblem(HttpServletResponse response, String msg)
            throws IOException {
        response.sendError(response.SC_NOT_FOUND, msg);
    }
}
