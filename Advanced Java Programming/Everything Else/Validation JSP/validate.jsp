<%
String name = request.getParameter("name");
String age = request.getParameter("age");
if(name == null || name.equals("") || age == null || age.equals("")){
%>
Name:
<br>
Age:
<br>
Error: All fields are required
<%
} else {
%>
Name: <%=name%>
<br>
Age: <%=age%>
<br>
Form Validation Successful
<%
}
%>