import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class CookieServlet extends HttpServlet {
   public void doGet(HttpServletRequest req, HttpServletResponse res)
         throws IOException {
      Cookie ck = new Cookie("user", "John Doe");
      res.addCookie(ck);
      PrintWriter out = res.getWriter();
      out.println("Cookie Set Successfully");
      out.println("<br>User: John Doe");
   }
}
