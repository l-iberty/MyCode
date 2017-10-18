package coreservlets;

import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

/**
 * Servlet that generate a random number, stores it in a bean,
 * and forwards to JSP page to display it.
 */

public class RandomNumberServlet extends HttpServlet {
    @Override
    public void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        NumberBean numberBean = new NumberBean();
        numberBean.setNum(Math.random());

        request.setAttribute("randomBean", numberBean);

        String address = "/MyPage/Random.jsp";
        RequestDispatcher dispatcher = request.getRequestDispatcher(address);
        dispatcher.forward(request, response);
    }
}
