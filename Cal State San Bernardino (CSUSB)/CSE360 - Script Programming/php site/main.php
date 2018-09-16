<?php
session_start();
if($_SESSION['username'] != 'go') {
header("location:login.html");
exit();
}

?>

<html>
<body>
<p>Login Successfull</p>

<ul>
	<li><a href="passtable.php">Password Table</a>
	<li><a href="inventorytable.php">Inventory Table</a>
	<li><a href="logout.php">Log Out</a
</ul>




</body>
</html>
