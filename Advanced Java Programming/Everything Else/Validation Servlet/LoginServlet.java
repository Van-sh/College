import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class LoginServlet extends HttpServlet {
   public void doPost(HttpServletRequest req, HttpServletResponse res)
         throws IOException {
      String user = req.getParameter("user");
      String pass = req.getParameter("pass");
      PrintWriter out = res.getWriter();
      if (user.equals("john") && pass.equals("1234")) {
         out.println("Username: john");
         out.println("<br>Password: 1234");
         out.println("<br>Login Successful");
         out.println("<br>Welcome John Doe");
      } else {
         out.println("Username: wrong");
         out.println("<br>Password: wrong");
         out.println("<br>Invalid User");
      }
   }
}