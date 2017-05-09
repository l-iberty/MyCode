<!DOCTYPE html>
<html>
<head>
	<title>admindel</title>
</head>
<body>
<div>delete book</div>
<%@ page import="util.*" %>
<%
	out.println("All books<hr/>");
	Database database = new Database("root","2015Liberty","localhost","db_lib");
	out.println(database.query("book","*",null));
%>
</body>
<form action="/admindel_servlet">
	<table>
		<tr>
			<td>input <b>id</b> of the book needed to delete: </td>
			<td><input type="text" name="id"></td>
		</tr>
		<tr><td>
			<input type="submit" value="submit your delete">
		</td></tr>
	</table>
</form>
</html>