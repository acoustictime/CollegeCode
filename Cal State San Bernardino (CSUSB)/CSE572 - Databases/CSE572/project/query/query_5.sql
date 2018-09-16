/*
Present a report on students who have not paid their invoices by a given date.
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
DONE BY: Enrique Carbajal
*/

set linesize 400
set pagesize 100
TTITLE "Query 5"
SET FEEDBACK OFF
COLUMN first_name HEADING "First Name" format a15
COLUMN last_name HEADING "Last Name" format a15
COLUMN student_number HEADING "Student ID" format a12

select s.first_name, s.last_name, s.student_number
from student s, invoice i
where s.student_number = i.student_number AND i.payment_received_date > '&Date';

TTITLE OFF
SET FEEDBACK ON
COLUMN first_name CLEAR
COLUMN last_name CLEAR
COLUMN student_number CLEAR


