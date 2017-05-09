/**
 * 处理管理员添加图书记录的操作
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

public class AdminAddBookServlet extends HttpServlet {
    private final String dbName = "db_lib";
    private final String tbName = "book";

    @Override
    public void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        String id = request.getParameter("id");
        String name = request.getParameter("name");
        String author = request.getParameter("author");
        String catagory = request.getParameter("catagory");

        String values = "(\'" + id + "\'," +
                "\'" + name + "\'," +
                "\'" + author + "\'," +
                "\'" + catagory + "\')";

        Database database = new Database("root", "2015Liberty", "localhost", dbName);
        database.insert(tbName, "(id,name,author,catagory)", values);

        out.println("Add operation Done!");
    }
}
