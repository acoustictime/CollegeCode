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
$sql = "select * from inventory where no='$_POST[name]'";
$result = mysql_query ($sql, $connect);
$row = mysql_fetch_array($result);

?>
<body bgcolor='white'>
<b>DATABASE:Inventory</b>
 
<table border=1 height=20 align="center">
<form method=post action='update2.php'>
        <tr align=center>
                <td>No:</td>
        	<td><input type=text name=no size=20 value="<?echo $row[0]?>" ></td>
	</tr>
        <tr align=center>
                <td>Mac:</td>
       		<td><input type=text name=mac size=19 maxlength=19 value="<?echo $row[1]?>" ></td> 
	</tr>
        <tr align=center>
                <td>IP:</td>
        	<td><input type=text name=ip size=19 maxlength=18 value="<?echo $row[2]?>" ></td>
	</tr>
        <tr align=center>
                <td>Host:</td>
		<td><input type=text name=host size=19 maxlength=18 value="<?echo $row[3]?>" ></td>
	</tr>
        
	<tr align=center>
                <td>Room:</td>
        	<td><input type=text name=room size=19 maxlength=18 value="<?echo $row[4]?>" ></td>
	</tr>

	<tr align=center>
                <td>PID:</td>
        	<td><input type=text name=pid size=19 maxlength=18 value="<?echo $row[5]?>" ></td>
	</tr>

	<tr align=center>
                <td>Maker:</td>
        	<td><input type=text name=maker size=19 maxlength=18 value="<?echo $row[6]?>" ></td>
	</tr>

	<tr align=center>
                <td>Model:</td>
        	<td><input type=text name=model size=19 maxlength=18 value="<?echo $row[7]?>" ></td>
	</tr>

	<tr>
                <td colspan=2 align=center>
               <input type=submit value='   OK  ' >
               </td>
        </tr>
</form>
</table>


</body>
</html>
