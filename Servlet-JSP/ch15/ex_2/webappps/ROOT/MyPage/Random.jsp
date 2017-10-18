<!DOCTYPE html>
<html>
<head>
	<title>Random Number</title>
</head>
<body>
<jsp:useBean id="randomBean" type="coreservlets.NumberBean" scope="request"/>
<h2>num:<i><jsp:getProperty name="randomBean" property="num"/></i></h2>
</body>
</html>