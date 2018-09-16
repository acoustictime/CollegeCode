<?php
include "connect.php";
 
$sql = "insert into pass values('$_POST[name]','$_POST[sid]','$_POST[login]','$_POST[password]')";
$result = mysql_query ($sql, $connect);
 
echo " <meta http-equiv='refresh' content='0; url=passtable.php'> ";
?>

