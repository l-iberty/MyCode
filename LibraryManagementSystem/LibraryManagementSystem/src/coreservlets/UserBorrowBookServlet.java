/**
 * 处理普通用户的借书操作
 * 使用的数据库: db_lib
 * 使用的表: base_view(视图),in_view(视图)
 */
package coreservlets;

import util.*;

import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class UserBorrowBookServlet extends HttpServlet {
    private final String dbName = "db_lib";

    @Override
    public void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        String id = request.getParameter("id");

        if (id != null && !id.trim().equals("")) {
            String conditions = "id=\'" + id + "\'";
            Database database = new Database("root", "2015Liberty", "localhost", dbName);
            // 在所有可借(state='in')图书中检索
            String query = database.query("in_view", "*", conditions);
            if (query != null && !query.trim().equals("")) {
                // 检索成功, 将base_view视图中的对应图书的state字段修改为'out'
                database.update("base_view", "state", "\'out\'", conditions);
                out.println(query +
                        "You have successfully borrow this book!");
            } else {
                // 没有图书可借
                out.println("No book found!");
            }
        }
    }
}
