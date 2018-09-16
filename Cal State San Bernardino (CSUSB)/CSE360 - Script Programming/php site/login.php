<?php
include "connect.php";

$myusername=$_POST['id'];
$mypassword=$_POST['password'];

$sql = "select name from pass where login='$myusername' and password='$mypassword' ";
$result = mysql_query ($sql, $connect);
$row = mysql_fetch_array($result);
 
if($row)
{
	session_start();
	session_register();
	$_SESSION['username'] = 'go';
	header('location: main.php');
}
else {
        echo ("
        <html>
        <head><title></title>
        <meta http-equiv='refresh' content='2; url=login.html'>
        </head>
        <body bgcolor='white'>
 	Wrong Password
	$id
	$password
        </body>
        </html>
        ");
}
?>

