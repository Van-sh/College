import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.util.*;

public class HeaderServlet extends HttpServlet {
   public void doGet(HttpServletRequest request, HttpServletResponse response)
         throws ServletException, IOException {
      response.setContentType("text/html");
      PrintWriter out = response.getWriter();

      out.println("<html><body>");
      out.println("<h2>Request Headers</h2><hr>");

      Enumeration<String> headerNames = request.getHeaderNames();

      while (headerNames.hasMoreElements()) {
         String name = headerNames.nextElement();
         String value = request.getHeader(name);
         out.println(name + " : " + value + "<br>");
      }

      out.println("</body></html>");
   }
}
