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
$sql = "select * from pass";
$sql2 = "select COLUMN_NAME from INFORMATION_SCHEMA.COLUMNS where table_NAME ='pass' ";
$result = mysql_query ($sql, $connect);
$result2 = mysql_query($sql2,$connect);
?>
<body bgcolor='white'>
<b>DATABASE:Inventory</b>
<hr noshade>
 
<TABLE cellpadding=5 cellspacing=0 BORDER=2 bgcolor="white" align="center">
      <TR>
	<?
	 while ($row2 = mysql_fetch_array($result2)) {
        ?>
          <TD><?echo $row2[0];?></TD>
          <?
    } ?>
	</TR>
<?  
	while($row = mysql_fetch_array($result)) {
        ?><TR>
          <TD><font color=red><?echo $row[0];?></font></TD>
          <TD><font color=blue><?echo $row[1];?></font></TD>
          <TD><font color=navy><?echo $row[2];?></font></TD>
          <TD><font color=navy><?echo $row[3];?></font></TD>
          </TR><?
     }?>
</TABLE>


 
<table align="center"border=1>
<tr align=center>
<td>Name:</td><td>SID:</td><td>Login ID:</td><td>Password:</td><td> </td>
</tr>
<tr align=center>
<form method=post action='insert.php'>
        <td><input type=text name=name size=20 value=></td>
        <td><input type=text name=sid size=9 maxlength=9 value=></td>
        <td><input type=text name=login size=9 maxlength=8 value=></td>
        <td><input type=password name=password size=9 maxlength=8 value=></td>
        <td colspan=2><input type=submit value='   Insert  ' ></td>
</form>
</tr>
</table>
 
<hr noshade>
 
<table border=0 align="center">
<tr><td>
     <form method=post action='d.php'>
     <select name="name" size=1>
     <option value="selected">Select Name</option>
     <?  
     $result = mysql_query ($sql, $connect);
     while($row = mysql_fetch_array($result)) {
     ?>
     <option value="<?echo $row[0];?>"><?echo $row[0];?></option>
      <?
     }?>
     </select>
     <input type='submit' value=' Delete '>
     </form>
</td>
<td width=30>  </td>
<td>
     <form method=post action='mg.php'>
     <select name="name" size=1>
     <option value="" selected>Select Name</option>
     <?  
     $result = mysql_query ($sql, $connect);
     while($row = mysql_fetch_array($result)) {
     ?>
          <option value="<?echo ("$row[0]");?>"><?echo $row[0];?></option>
     <?
     }?>
     </select>
     <input type='submit' value=' Modify '>
     </form>
</td>
<td width=30>  </td>
<td>
<form method=post action='s.php'>
Enter SID:
<input type="text" name=sid value="">
<input type='submit' value=' Search '> 
</form>
</td></tr>
</table>
 




</body>
</html>
