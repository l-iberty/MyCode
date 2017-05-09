/**
 * 处理管理员的登录验证
 * 使用的数据库: db_lib
 * 使用的表: admin
 */
package coreservlets;

import util.*;

import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class AdminloginServlet extends HttpServlet {
    private final String dbName = "db_lib";
    private final String tbName = "admin";

    @Override
    public void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        String user = request.getParameter("username");
        String passwd = request.getParameter("passwd");

        if (!isLogin(user, passwd)) {
            out.println("username or passwd error!");
        } else {
            String url = "../../../MyPage/adminpage.jsp";
            response.sendRedirect(url);
        }
    }

    private boolean isLogin(String user, String passwd) {
        Database database;
        String queryConditions;
        String query;

        database = new Database("root", "2015Liberty", "localhost", dbName);
        queryConditions = "username=" + "\'" + user + "\'" +
                " and passwd=" + "\'" + passwd + "\'";
        query = database.query(tbName, "*", queryConditions);
        return (query != null && !query.trim().equals(""));
    }
}
