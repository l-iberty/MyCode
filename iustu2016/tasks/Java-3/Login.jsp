<!DOCTYPE html>
<html>
	<head>
		<title>Login Page</title>
		<link rel="stylesheet" type="text/css" href="login-page-style.css" />
		<script type="text/javascript">
			function getFocus() {
				window.document.getElementById('username').focus();
			}
		</script>
	</head>
	<body onload="getFocus()">
		<h1>User Login</h1>
		<form>
			<div>Username: <input id="username" type="text" name="username" /></div>
			<div>Password: <input type="password" name="password" /></div>
			<div><input type="submit" value="Login" /></div>
		</form>
	</body>
</html>