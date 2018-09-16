<?php
include "connect.php";

$todelete = $_POST['name']; 
$sql = "delete from inventory where no='$todelete'";
$result = mysql_query ($sql, $connect);

echo " <meta http-equiv='refresh' content='0; url=inventorytable.php'> ";
?>

