<%@ page import="java.sql.*" %>
<%
String name = request.getParameter("name");
int age = Integer.parseInt(request.getParameter("age"));

Class.forName("com.mysql.cj.jdbc.Driver");
Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/test","root","root");

PreparedStatement ps = con.prepareStatement("insert into student values(?,?)");
ps.setString(1,name);
ps.setInt(2,age);
ps.executeUpdate();
%>
<html>
   <body>
      Data Inserted Successfully
   </body>
</html>