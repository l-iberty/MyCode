/**
 * 处理管理员更新图书记录的操作
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

public class AdminUpdBookServlet extends HttpServlet {
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

        if (id != null && !id.trim().equals("")) {
            String conditions = "id=\'" + id + "\'";
            StringBuilder colNames = new StringBuilder();
            StringBuilder colValues = new StringBuilder();

            if (name != null && !name.trim().equals("")) {
                colNames.append("name,");
                colValues.append("\'" + name + "\',");
            }
            if (author != null && !author.trim().equals("")) {
                colNames.append("author,");
                colValues.append("\'" + author + "\',");
            }
            if (catagory != null && !catagory.trim().equals("")) {
                colNames.append("catagory,");
                colValues.append("\'" + catagory + "\',");
            }
            // 除去最后一个逗号
            int i = colNames.lastIndexOf(",");
            int j = colValues.lastIndexOf(",");
            colNames.replace(i, i + 1, "");
            colValues.replace(j, j + 1, "");

            Database database = new Database("root", "2015Liberty", "localhost", dbName);
            database.update(tbName, colNames.toString(), colValues.toString(), conditions);
            out.println("Update operation Done!");
        } else {
            out.println("Empty id!");
        }
    }
}
