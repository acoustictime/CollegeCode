<?php
include "connect.php";
 
$sql = "insert into inventory values('$_POST[no]','$_POST[mac]','$_POST[ip]','$_POST[host]','$_POST[room]','$_POST[pid]','$_POST[maker]','$_POST[model]')";
$result = mysql_query ($sql, $connect);
 
echo " <meta http-equiv='refresh' content='0; url=inventorytable.php'> ";
?>

