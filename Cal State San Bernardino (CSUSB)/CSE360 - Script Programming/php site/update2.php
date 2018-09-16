<?php
include "connect.php";


$sql = "update inventory set mac='$_POST[mac]',ip='$_POST[ip]',host='$_POST[host]', room='$_POST[room]', pid='$_POST[pid]', maker='$_POST[maker]', model='$_POST[model]'  where no = '$_POST[no]'";

$result = mysql_query ($sql, $connect);


$sql = "update inventory set no='$_POST[no]' where mac = '$_POST[mac]'";
$result = mysql_query ($sql, $connect);

echo " <meta http-equiv='refresh' content='0; url=inventorytable.php'> ";
