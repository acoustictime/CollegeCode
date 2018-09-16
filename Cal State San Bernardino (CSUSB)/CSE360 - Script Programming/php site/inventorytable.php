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
$sql = "select * from inventory";
$sql2 = "select COLUMN_NAME from INFORMATION_SCHEMA.COLUMNS where table_NAME ='inventory' ";
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
	  <TD><font color=red><?echo $row[4];?></font></TD> 
	  <TD><font color=red><?echo $row[5];?></font></TD> 
	  <TD><font color=blue><?echo $row[6];?></font></TD>
	  <TD><font color=blue><?echo $row[7];?></font></TD>


          </TR><?
     }?>
</TABLE>


 
<table align="center"border=1>
<tr align=center>
<td>NO:</td><td>MAC:</td><td>IP:</td><td>HOST:</td><td>ROOM:</td><td>PID:</td><td>MAKER:</td><td>MODEL:</td>
</tr>
<tr align=center>
<form method=post action='insert2.php'>
        <td><input type=text name=no size=20 value=></td>
        <td><input type=text name=mac size=19 maxlength=19 value=></td>
        <td><input type=text name=ip size=19 maxlength=18 value=></td>
        <td><input type=text name=host size=19 maxlength=18 value=></td>	
        <td><input type=text name=room size=19 maxlength=18 value=></td>
        <td><input type=text name=pid size=19 maxlength=18 value=></td>
        <td><input type=text name=maker size=19 maxlength=18 value=></td>
        <td><input type=text name=model size=19 maxlength=18 value=></td>
        <td colspan=2><input type=submit value='   Insert  ' ></td>
</form>
</tr>
</table>
 
<hr noshade>
 
<table border=0 align="center">
<tr><td>
     <form method=post action='d2.php'>
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
     <form method=post action='mg2.php'>
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
<form method=post action='s2.php'>
Enter No:
<input type="text" name=no value="">
<input type='submit' value=' Search '> 
</form>
</td></tr>
</table>
 




</body>
</html>
