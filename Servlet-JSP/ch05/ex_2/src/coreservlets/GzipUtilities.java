package coreservlets;

import java.io.*;
import javax.servlet.http.*;
import java.util.zip.*;

public class GzipUtilities {

    /**
     * Does the client support gzip?
     */
    public static boolean isGzipSupported(HttpServletRequest request) {
        // 如果浏览器支持gzip文本压缩，它就会设置Accept-Encoding请求报头，表示它支持之
        String encodings = request.getHeader("Accept-Encoding");
        return (encodings != null) && (encodings.contains("gzip"));
    }

    /**
     * Has user disable gzip?
     */
    public static boolean isGzipDisabled(HttpServletRequest request) {
        String flag = request.getParameter("disableGzip");
        return (flag != null) && (!flag.equalsIgnoreCase("false"));
    }

    /**
     * Return gzipping PrintWriter for response.
     */
    public static PrintWriter getGzipWriter(HttpServletResponse response)
            throws IOException {
        // 使用PrintWriter封装GZIPOutputStream
        return (new PrintWriter(new GZIPOutputStream(response.getOutputStream())));
    }

}
