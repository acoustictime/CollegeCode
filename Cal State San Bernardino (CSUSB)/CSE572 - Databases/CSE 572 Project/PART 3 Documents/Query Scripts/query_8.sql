/*
Present a report listing the details of all students currently on the waiting 
	list for accommodation; that is, who were not placed.
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
DONE BY: James Small
*/

set linesize 400
set pagesize 100
TTITLE "Query 8"
SET FEEDBACK OFF
COLUMN first_name HEADING "First Name" format a15
COLUMN last_name HEADING "Last Name" format a15
COLUMN student_number HEADING "Student ID" format a12

select first_name, last_name, student_number
from student
where current_status = 'Waiting';

SET FEEDBACK ON
TTITLE OFF
COLUMN first_name CLEAR
COLUMN last_name CLEAR
COLUMN student_number CLEAR


