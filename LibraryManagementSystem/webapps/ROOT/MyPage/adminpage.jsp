<!DOCTYPE html>
<html>
<head>
	<title>adminpage</title>
	<script type="text/javascript">
		function btnAdd_onclick() {
			window.open("adminadd.html");
		}

		function btnDelete_onclick() {
			window.open("admindel.jsp");
		}

		function btnUpdate_onclick() {
			window.open("adminupd.jsp");
		}
	</script>
</head>
<body>
<div>Welcome back, admin!</div>
<%@ page import="util.*" %>
<%
	out.println("All books<hr/>");
	Database database = new Database("root","2015Liberty","localhost","db_lib");
	out.println(database.query("book","*",null));
%>
<form>
	<input type="button" name="add" value="add" onclick="btnAdd_onclick()">
	<input type="button" name="delete" value="delete" onclick="btnDelete_onclick()">
	<input type="button" name="update" value="update" onclick="btnUpdate_onclick()">
</form>
</body>
</html>