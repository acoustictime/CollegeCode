<?php
include "connect.php";


$sql = "update pass set sid='$_POST[sid]',login='$_POST[login]',password='$_POST[password]' where name = '$_POST[name2]'";

$result = mysql_query ($sql, $connect);




$sql = "update pass set name='$_POST[name2]' where sid = '$_POST[sid]'";
$result = mysql_query ($sql, $connect);

echo " <meta http-equiv='refresh' content='0; url=passtable.php'> ";
