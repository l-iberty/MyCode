<!DOCTYPE html>
<html>
<head>
	<title>userreturn</title>
</head>
<body>
<div>Welcome to Library Management System</div>
<div>Return book:</div>
<%@ page import="util.*" %>
<%
	Database database = new Database("root","2015Liberty","localhost","db_lib");
	out.println(database.query("out_view","*",null));
%>
<form action="/userreturn_servlet">
	<table>
		<tr>
			<td>input <b>id</b> of the book you wanna return: </td>
			<td><input type="text" name="id"></td>
		</tr>
		<tr><td>
			<input type="submit" value="return it">
		</td></tr>
	</table>
</form>
</body>
</html>