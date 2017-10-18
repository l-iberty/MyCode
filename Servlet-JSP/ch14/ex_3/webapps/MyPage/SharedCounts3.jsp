<!DOCTYPE html>
<html>
<head>
	<title>Shared Access Count: Page 3</title>
</head>
<body>
<table border="5" align="center">
	<tr><th>Shared Access Count: Page 3</th></tr>
</table>
<p>
<jsp:useBean id="counter"
			class="coreservlets.AccessCountBean"
			scope="application">
	<jsp:setProperty name="counter" property="firstPage" value="SharedCounts3.jsp"/>
</jsp:useBean>
Of SharedCounts3.jsp (this page),
<a href="SharedCounts1.jsp">SharedCounts1.jsp</a>, and
<a href="SharedCounts2.jsp">SharedCounts2.jsp</a>,
<jsp:getProperty name="counter" property="firstPage"/>
was the first accessed.
<p>
<p>
Collectively, the three pages has been accessed 
<jsp:getProperty name="counter" property="accessCount"/>
times.
</p>
<jsp:setProperty name="counter" property="accessCountIncrement" value="1"/>
</body>
</html>