<!DOCTYPE html>
<html>
<head>
	<title>Using JavaBean with JSP</title>
</head>
<body>
<table border="5" align="center">
	<tr><th>Using JavaBean with JSP</th></tr>
</table>
<jsp:useBean id="stringBean" class="coreservlets.StringBean" />
<ol>
	<li>Initial value (from jsp:getProperty): 
		<i><jsp:getProperty name="stringBean" property="message"/></i>
	</li>
	<li>Initial value (from JSP expression): 
		<i><%= stringBean.getMessage() %></i>
	</li>
	<li><jsp:setProperty name="stringBean" property="message" value="Hello, JSP"/>
		Value after setting property with jsp:setProperty: 
		<i><jsp:getProperty name="stringBean" property="message"/></i>
	</li>
	<li><% stringBean.setMessage("Hello, Servlet"); %>
		Value after setting property with scriptlet: 
		<i><%= stringBean.getMessage() %></i>
	</li>
</ol>
</body>
</html>