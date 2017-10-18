<!DOCTYPE html>
<html>
<head>
	<title>SimpleBean Display with scope="application"</title>
</head>
<body>
<table border="5" align="center">
	<tr><th>SimpleBean Display with scope="application"</th></tr>
</table>
<jsp:useBean id="pageBean" class="coreservlets.SimpleBean"
			scope="application"/>
<jsp:setProperty name="pageBean" property="*"/>
<p>
	beanName:
	<jsp:getProperty name="pageBean" property="beanName"/>
</p>
<% /* 强制结束当前会话 */ session.invalidate(); %>
</body>
</html>