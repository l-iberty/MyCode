<!DOCTYPE html>
<html>
<head>
	<title>snippet included by SimpleBeanDisplay-request.jsp</title>
</head>
<body>
<table border="5" align="center">
	<tr><th>snippet included by SimpleBeanDisplay-request.jsp</th></tr>
</table>
<!-- 将 scope 设为 "request" 或 "page" 来试验 -->
<jsp:useBean id="pageBean" class="coreservlets.SimpleBean"
			scope="request"/>
<p>
	beanName:
	<jsp:getProperty name="pageBean" property="beanName"/>
</p>
</body>
</html>