/**
 * 处理图书记录的查询操作
 * 使用的数据库: db_lib
 * 使用的表: base_view(视图)
 */
package coreservlets;

import util.*;

import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class SearchServlet extends HttpServlet {
    private final String dbName = "db_lib";
    private final String tbName = "base_view";

    @Override
    public void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html");
        PrintWriter out = response.getWriter();

        String id = request.getParameter("id");
        String name = request.getParameter("name");
        String author = request.getParameter("author");
        String catagory = request.getParameter("catagory");

        // 构造遵循sql语法的查询条件字符串
        StringBuilder queryConditions = new StringBuilder();
        if (id != null && !id.trim().equals("")) {
            queryConditions.append("id=" + "\'" + id + "\'");
        }
        if (name != null && !name.trim().equals("")) {
            queryConditions.append(" and name=" + "\'" + name + "\'");
        }
        if (author != null && !author.trim().equals("")) {
            queryConditions.append(" and author=" + "\'" + author + "\'");
        }
        if (catagory != null && !catagory.trim().equals("")) {
            queryConditions.append(" and catagory=" + "\'" + catagory + "\'");
        }

        // 除去第一个'and'
        int i = queryConditions.indexOf("and");
        if (i > 0) {
            queryConditions.replace(i, i + 3, "");
        }

        // 连接数据库进行查询, 并显示返回的查询结果
        if (!queryConditions.toString().trim().equals("")) {
            Database database = new Database("root", "2015Liberty", "localhost", dbName);
            String query = database.query(tbName, "*", queryConditions.toString());
            if (query == null || query.trim().equals("")) {
                out.println("No books found!");
            } else {
                out.println(query);
            }
        } else {
            // 用户未输入任何查询字段
            out.println("Empty input!");
        }
    }
}
