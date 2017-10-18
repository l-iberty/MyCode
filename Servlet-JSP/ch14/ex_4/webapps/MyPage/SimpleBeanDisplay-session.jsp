<!DOCTYPE html>
<html>
<head>
	<title>SimpleBean Display with scope="session"</title>
</head>
<body>
<table border="5" align="center">
	<tr><th>SimpleBean Display with scope="session"</th></tr>
</table>
<jsp:useBean id="pageBean" class="coreservlets.SimpleBean"
			scope="session"/>
<jsp:setProperty name="pageBean" property="*"/>
<p>
	beanName:
	<jsp:getProperty name="pageBean" property="beanName"/>
</p>
<% /* 强制结束当前会话 session.invalidate(); */ %>
</body>
</html>