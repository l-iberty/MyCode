<!DOCTYPE html>
<html>
<head>
	<title>Using jsp:setProperty</title>
</head>
<body>
<table border="5" align="center">
	<tr><th>Using jsp:setProperty</th></tr>
</table>
<jsp:useBean id="entry" class="coreservlets.SaleEntry" />

<!-- get `itemID`(String) -->
<jsp:setProperty
	name="entry"
	property="itemID"
	param="itemID" />

<!-- get `numItems`(int) -->
<jsp:setProperty
	name="entry"
	property="numItems"
	param="numItems" />

<!-- get `discountCode`(double) -->
<jsp:setProperty
	name="entry"
	property="discountCode"
	param="discountCode" />
<br>

<!-- display data via a table -->
<table border="1">
	<tr>
		<th>Item ID</th>
		<th>Unit Price</th>
		<th>Number Ordered</th>
		<th>Total Price</th>
	</tr>
	<tr align="right">
		<td><jsp:getProperty name="entry" property="itemID"/></td>
		<td>$<jsp:getProperty name="entry" property="itemCost"/></td>
		<td><jsp:getProperty name="entry" property="numItems"/></td>
		<td>$<jsp:getProperty name="entry" property="totalCost"/></td>
	</tr>
</table>
</body>
</html>