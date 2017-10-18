<!DOCTYPE html>
<html>
<head>
	<title>SimpleBean Display with scope="page"</title>
</head>
<body>
<table border="5" align="center">
	<tr><th>SimpleBean Display with scope="page"</th></tr>
</table>
<jsp:useBean id="pageBean" class="coreservlets.SimpleBean"/> <!-- scope="page" is default setting -->
<jsp:setProperty name="pageBean" property="*"/>
<p>
	beanName:
	<jsp:getProperty name="pageBean" property="beanName"/>
</p>
</body>
</html>