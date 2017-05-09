<!DOCTYPE html>
<html>
<head>
	<title>userborrow</title>
</head>
<body>
<div>Welcome to Library Management System</div>
<div>All books you can borrow:</div>
<%@ page import="util.*" %>
<%
	Database database = new Database("root","2015Liberty","localhost","db_lib");
	out.println(database.query("in_view","*",null));
%>
<form action="/userborrow_servlet">
	<table>
		<tr>
			<td>input <b>id</b> of the book you wanna borrow: </td>
			<td><input type="text" name="id"></td>
		</tr>
		<tr><td>
			<input type="submit" value="borrow it">
		</td></tr>
	</table>
</form>
</body>
</html>