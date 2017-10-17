package coreservlets;

import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

/**
 * Servlet that reads a customer's ID and displays
 * information on the account balance of the customer
 * who has that ID.
 */

public class ShowBalance extends HttpServlet {
    @Override
    public void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        BankCustomer customer =
                BankCustomer.getCustomer(request.getParameter("id"));
        String address;

        if (customer == null) {
            address = "/MyPage/UnknownCustomer.jsp";

        } else if (customer.getBalance() < 0.0) {
            address = "/MyPage/NegativeBalance.jsp";
            request.setAttribute("badCustomer", customer);
        } else if (customer.getBalance() < 10000.0) {
            address = "/MyPage/NormalBalance.jsp";
            request.setAttribute("regularCustomer", customer);
        } else {
            address = "/MyPage/HighBalance.jsp";
            request.setAttribute("eliteCustomer", customer);
        }

        RequestDispatcher dispatcher =
                request.getRequestDispatcher(address);
        dispatcher.forward(request, response);
    }
}
