package coreservlets;

import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

/**
 * Read `firstName` and `lastName` from request parameters ans forwards
 * to JSP page to display them. Use session-based bean sharing to
 * remember previous values.
 */

public class RegistrationServlet extends HttpServlet {
    @Override
    public void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        HttpSession session = request.getSession();
        NameBean nameBean =
                (NameBean) session.getAttribute("nameBean");
        // nameBean 必然为 null, 除非先访问 JSP 页面
        if (nameBean == null) {
            nameBean = new NameBean();
            session.setAttribute("nameBean", nameBean);
        }

        String firstName = request.getParameter("firstName");
        if (firstName != null && !firstName.trim().equals("")) {
            nameBean.setFirstName(firstName);
        }
        String lastName = request.getParameter("lastName");
        if (lastName != null && !lastName.trim().equals("")) {
            nameBean.setLastName(lastName);
        }

        String address = "/MyPage/ShowName.jsp";
        RequestDispatcher dispatcher = request.getRequestDispatcher(address);
        dispatcher.forward(request, response);
    }
}
