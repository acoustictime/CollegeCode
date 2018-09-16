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
$sql = "select * from inventory where no='$_POST[no]'";
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
                <td>No:</td>
                <td><?echo $row[0]?></td>
        </tr>
        <tr align=center>
                <td>Mac:</td>
                <td><?echo $row[1]?></td>
        </tr>
        <tr align=center>
                <td>IP:</td>
                <td><?echo $row[2]?></td>
        </tr>
        <tr align=center>
                <td>Host:</td>
                <td><?echo $row[3]?></td>
        </tr>
	<tr align=center>
                <td>Room:</td>
                <td><?echo $row[4]?></td>
        </tr>
        <tr align=center>
                <td>PID:</td>
                <td><?echo $row[5]?></td>
        </tr>
        <tr align=center>
                <td>Maker:</td>
                <td><?echo $row[6]?></td>
        </tr>
        <tr align=center>
                <td>Model:</td>
                <td><?echo $row[7]?></td>
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
