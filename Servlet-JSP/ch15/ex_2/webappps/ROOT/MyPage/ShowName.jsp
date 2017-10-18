<!DOCTYPE html>
<html>
<head>
	<title>Thanks for Registering</title>
</head>
<body>
<jsp:useBean id="nameBean" type="coreservlets.NameBean" scope="session"/>
<h1>Thanks for Registering</h1>
<h2>First Name:<i><jsp:getProperty name="nameBean" property="firstName"/></i></h2>
<h2>Last Name:<i><jsp:getProperty name="nameBean" property="lastName"/></i></h2>
</body>
</html>