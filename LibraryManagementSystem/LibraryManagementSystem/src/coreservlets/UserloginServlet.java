/**
 * 处理普通用户的登录验证
 * 使用的数据库: db_lib
 * 使用的表: user
 */
package coreservlets;

import util.*;

import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class UserloginServlet extends HttpServlet {
    private final String dbName = "db_lib";
    private final String tbName = "user";

    @Override
    public void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        String user = request.getParameter("username");
        String passwd = request.getParameter("passwd");

        if (!isLogin(user, passwd)) {
            // 登录失败
            out.println("username or passwd error!");
        } else {
            // 登录成功, 进行页面跳转
            String url = "../../../MyPage/userpage.html";
            response.sendRedirect(url);
        }
    }

    /**
     * 将用户输入的用户名和密码与db_lib.user表中的信息进行比对验证
     * @param user
     * @param passwd
     * @return 验证成功true, 验证失败false
     */
    private boolean isLogin(String user, String passwd) {
        Database database;
        String queryConditions;
        String query;

        database = new Database("root", "2015Liberty", "localhost", dbName);
        queryConditions = "username=" + "\'" + user + "\'" +
                " and passwd=" + "\'" + passwd + "\'";
        // 查询
        query = database.query(tbName, "*", queryConditions);
        // 检测查询结果
        return (query != null && !query.trim().equals(""));
    }
}
