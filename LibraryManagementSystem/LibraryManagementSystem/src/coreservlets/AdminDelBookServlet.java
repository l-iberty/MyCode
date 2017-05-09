/**
 * 处理管理员删除图书记录的操作
 * 使用的数据库: db_lib
 * 使用的表: book
 * (管理员对记录的增删改查全部使用基表book, 而普通用户对记录
 * 的查询和读取都基于三个视图base_view,in_view和out_view)
 */
package coreservlets;

import util.*;

import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class AdminDelBookServlet extends HttpServlet {
    private final String dbName = "db_lib";
    private final String tbName = "book";

    @Override
    public void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        String id = request.getParameter("id");

        if (id != null && !id.trim().equals("")) {
            String conditions = "id=\'" + id + "\'";
            Database database = new Database("root", "2015Liberty", "localhost", dbName);
            database.delete(tbName, conditions);
            out.println("Delete operation Done!");
        } else {
            out.println("Empty id!");
        }
    }
}
