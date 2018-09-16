/*
Display the name and internal telephone number of the 
	Adviser for a particular student.
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
DONE BY: Daniel Urbach
*/

set linesize 400
set pagesize 100
SET FEEDBACK OFF
TTITLE "Query 11"
COLUMN first_name HEADING "First Name" format a15
COLUMN last_name HEADING "Last Name" format a15
COLUMN phone_number HEADING "Phone #" format a12

select m.first_name, m.last_name, a.phone_number
from student s, staff_member m, advisor a
where s.student_number = '&Student_ID' AND m.staff_number = a.advisor_number AND s.advisor_number = a.advisor_number;

SET FEEDBACK ON
TTITLE OFF
COLUMN first_name CLEAR
COLUMN last_name CLEAR
COLUMN phone_number CLEAR


