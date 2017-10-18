<!DOCTYPE html>
<html>
<head>
	<title>SimpleBean Display with scope="request"</title>
</head>
<body>
<table border="5" align="center">
	<tr><th>SimpleBean Display with scope="request"</th></tr>
</table>
<!-- 将 scope 设为 "request" 或 "page" 来试验 -->
<jsp:useBean id="pageBean" class="coreservlets.SimpleBean"
			scope="request"/>
<jsp:setProperty name="pageBean" property="*"/>
<p>
	beanName:
	<jsp:getProperty name="pageBean" property="beanName"/>
</p>
<jsp:include page="SimpleBeanDisplay-snippet.jsp" />
</body>
</html>