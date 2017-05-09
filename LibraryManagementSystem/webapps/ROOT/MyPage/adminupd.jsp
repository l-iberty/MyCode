<!DOCTYPE html>
<html>
<head>
	<title>adminupd</title>
</head>
<body>
<div>update book</div>
<%@ page import="util.*" %>
<%
	out.println("All books<hr/>");
	Database database = new Database("root","2015Liberty","localhost","db_lib");
	out.println(database.query("book","*",null));
%>
<form action="/adminupd_servlet">
	<table>
		<tr>
			<td>input <b>id</b> of the book needed to update: </td>
			<td><input type="text" name="id"></td>
		</tr>
		<tr>
			<td>if you wanna update <i>name</i>, input a new one, otherwise leave it alone: </td>
			<td><input type="text" name="name"></td>
		</tr>
		<tr>
			<td>if you wanna update <i>author</i>, input a new one, otherwise leave it alone: </td>
			<td><input type="text" name="author"></td>
		</tr>
		<tr>
			<td>if you wanna update <i>catagory</i>, input a new one, otherwise leave it alone: </td>
			<td><input type="text" name="catagory"></td>
		</tr>
		<tr><td>
			<input type="submit" value="submit your update">
		</td></tr>
	</table>
</form>
</body>
</html>