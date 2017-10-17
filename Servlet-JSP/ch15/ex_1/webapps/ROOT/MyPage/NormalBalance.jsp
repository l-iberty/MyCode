<!DOCTYPE html>
<html>
<head>
	<title>Your Balance</title>
</head>
<body>
<table border="5" align="center">
	<tr><th>Your Balance</th></tr>
</table>
<p>
	<jsp:useBean id="regularCustomer"
				type="coreservlets.BankCustomer"
				scope="request" />
	<ul>
		<li>First Name: <jsp:getProperty name="regularCustomer"
										property="firstName"/></li>
		<li>Last Name: <jsp:getProperty name="regularCustomer"
										property="lastName"/></li>
		<li>ID: <jsp:getProperty name="regularCustomer"
										property="id"/></li>
		<li>Balance: $<jsp:getProperty name="regularCustomer"
										property="balance"/></li>
	</ul>
</p>
</body>
</html>