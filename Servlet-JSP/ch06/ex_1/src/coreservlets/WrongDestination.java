package coreservlets;

import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class WrongDestination extends HttpServlet {
    @Override
    public void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.sendError(404,"Fuck");
    }
}
