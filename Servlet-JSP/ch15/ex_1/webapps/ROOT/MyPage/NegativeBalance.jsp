<!DOCTYPE html>
<html>
<head>
	<title>You Owe Us Money!</title>
</head>
<body>
<table border="5" align="center">
	<tr><th>Your Balance</th></tr>
</table>
<p>
	<jsp:useBean id="badCustomer"
				type="coreservlets.BankCustomer"
				scope="request" />
	<ul>
		<li>First Name: <jsp:getProperty name="badCustomer"
										property="firstName"/></li>
		<li>Last Name: <jsp:getProperty name="badCustomer"
										property="lastName"/></li>
		<li>ID: <jsp:getProperty name="badCustomer"
										property="id"/></li>
		<li>Balance: $<jsp:getProperty name="badCustomer"
										property="balance"/></li>
	</ul>
</p>
</body>
</html>