package coreservlets;

import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

/**
 * Servlet that get a string from parameter and
 * transform it into upper case and display it.
 */

public class UpperCaseServlet extends HttpServlet {
    @Override
    public void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        String str = request.getParameter("origString");
        ServletContext context = getServletContext();
        UpperCaseBean upperCaseBean =
                (UpperCaseBean) context.getAttribute("upperCaseBean");
        synchronized (this) {
            if (upperCaseBean == null) {
                upperCaseBean = new UpperCaseBean();
                context.setAttribute("upperCaseBean", upperCaseBean);
            }
            if (str != null && !str.trim().equals("")) {
                upperCaseBean.setOrigString(str);
            }
        }

        String address = "/MyPage/UpperCase.jsp";
        RequestDispatcher dispatcher = request.getRequestDispatcher(address);
        dispatcher.forward(request, response);
    }
}
