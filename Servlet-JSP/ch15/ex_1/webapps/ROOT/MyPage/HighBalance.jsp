<!DOCTYPE html>
<html>
<head>
	<title>Your Balance</title>
</head>
<body>
<table border="5" align="center">
	<tr>Your Balance</tr>
</table>
<p>
	<br clear="all">
	<jsp:useBean id="eliteCustomer"
				type="coreservlets.BankCustomer"
				scope="request" />
	It is an honor to serve you,
	<jsp:getProperty name="eliteCustomer" property="firstName" />
	<jsp:getProperty name="eliteCustomer" property="lastName" />!
</p>
<p>
	Since you are one of our most values customers, we would like
	to offer you the opportunity to spend a mere fraction of your
	$<jsp:getProperty name="eliteCustomer" property="balance" />
	on a boat worthy of your status. Please visit our boat store for
	more information.
</p>
</body>
</html>