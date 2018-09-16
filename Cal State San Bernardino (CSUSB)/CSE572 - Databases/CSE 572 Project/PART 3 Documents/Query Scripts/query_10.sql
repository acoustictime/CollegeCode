/*
Present a report of the names and ids for all students who have 
	not supplied details of their next-of-kin.
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
DONE BY: Daniel Urbach
*/

set linesize 400
set pagesize 100
SET FEEDBACK OFF
TTITLE "Query 10"
COLUMN first_name HEADING "First Name" format a15
COLUMN last_name HEADING "Last Name" format a15
COLUMN student_number HEADING "Student ID" format a12

select s.first_name, s.last_name, s.student_number
from student s
where not exists (select *
		  from nok_relationship r
		  where s.student_number = r.student_number);

SET FEEDBACK ON
TTITLE OFF
COLUMN first_name CLEAR
COLUMN last_name CLEAR
COLUMN student_number CLEAR


