<!DOCTYPE html>
<html>
<head>
	<title>String to Upper Case</title>
</head>
<body>
<jsp:useBean id="upperCaseBean" type="coreservlets.UpperCaseBean" scope="application"/>
<h2>original input:<i><jsp:getProperty name="upperCaseBean" property="origString"/></i></h2>
<h2>to upper case:<i><jsp:getProperty name="upperCaseBean" property="upperString"/></i></h2>
</body>
</html>