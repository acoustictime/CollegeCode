<?php
session_start();
if($_SESSION['username'] != 'go') {
header("location:login.html");
}
?>

<html>
<body>


<?php

include "connect.php";
$sql = "select * from pass where sid='$_POST[sid]'";
$result = mysql_query ($sql, $connect);
$row = mysql_fetch_array($result);
?>
<body bgcolor='white'>
<b>DATABASE:Inventory</b>
<? 
if ($row) {
?>
<table border=1 height=20 align="center">
        <tr align=center>
                <td>Name:</td>
                <td><?echo $row[0]?></td>
        </tr>
        <tr align=center>
                <td>SID:</td>
                <td><?echo $row[1]?></td>
        </tr>
        <tr align=center>
                <td>Login ID:</td>
                <td><?echo $row[2]?></td>
        </tr>
        <tr align=center>
                <td>Password:</td>
                <td><?echo $row[3]?></td>
        </tr>
</table>
<?
} 

else {
?>
	<a text-align=center>Record not found</a>
<?
}
?>

</body>
</html>
