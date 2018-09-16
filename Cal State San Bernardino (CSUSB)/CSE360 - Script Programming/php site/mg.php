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
$sql = "select * from pass where name='$_POST[name]'";
$result = mysql_query ($sql, $connect);
$row = mysql_fetch_array($result);

?>
<body bgcolor='white'>
<b>DATABASE:Inventory</b>
 
<table border=1 height=20 align="center">
<form method=post action='update.php'>
        <tr align=center>
                <td>Name:</td>
                <td><input type=text name=name2 size=30 value="<?echo $row[0]?>"></td>
        </tr>
        <tr align=center>
                <td>SID:</td>
                <td><input type=text name=sid size=10 value=<?echo $row[1]?> ></td>
        </tr>
        <tr align=center>
                <td>Login ID:</td>
                <td><input type=text name=login size=10 value=<?echo $row[2]?> ></td>
        </tr>
        <tr align=center>
                <td>Password:</td>
                <td>
               <input type=text name=password size=10  value=<?echo $row[3]?> >
               </td>
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
