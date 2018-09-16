/*
Display the staff number, name, age, and current location of all members of 
	the residence staff who are over 60 years of age today.
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
DONE BY: James Small
*/

set linesize 400
set pagesize 100
SET FEEDBACK OFF
TTITLE "Query 13"
COLUMN staff_number HEADING "Staff #" format a8
COLUMN first_name HEADING "First Name" format a15
COLUMN last_name HEADING "Last Name" format a15
COLUMN location HEADING "Location" format a15

select staff_number, first_name, last_name, 
	to_number(to_char(sysdate,'YYYY'))-to_number(to_char(19)|| to_char(date_of_birth,'YY')) "Age", location
from staff_member
where to_number(to_char(sysdate,'YYYY'))-to_number(to_char(19)|| to_char(date_of_birth,'YY')) >= 60;

SET FEEDBACK ON
TTITLE OFF
COLUMN staff_number CLEAR
COLUMN first_name CLEAR
COLUMN last_name CLEAR
COLUMN location CLEAR


