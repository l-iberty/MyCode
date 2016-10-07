<!DOCTYPE html>
<html>
<head>
	<title>Delete Information</title>
	<link rel="stylesheet" type="text/css" href="form_style.css">
</head>
<body>
	<center>
	<h1>Delete Information</h1>
	<%
		String records = coreservlets.util.DatabaseReader.getRecords("table_1");
		out.println(records);
	%>
	<form action="/iustu_java_5_delete">
		<div>Name: <input type="text" name="name"></div>
		<div><input type="submit" value="Delete"></div>
	</form>
	</center>
</body>
</html>