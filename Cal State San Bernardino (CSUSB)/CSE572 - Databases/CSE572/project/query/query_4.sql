/*
Display the details of the total rent paid by a given student.
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
DONE BY: Enrique Carbajal
*/

set linesize 400
set pagesize 100
SET FEEDBACK OFF
TTITLE "Query 4"
COLUMN first_name HEADING "First Name" format a15
COLUMN last_name HEADING "Last Name" format a15

select s.first_name, s.last_name, sum(r.rent) "Total Rent"
from student s, invoice i, rents rt, room r
where s.student_number = i.student_number AND i.payment_received_date < sysdate
	and s.student_number = rt.student_number and rt.room_number = r.room_number
group by s.first_name, s.last_name;

SET FEEDBACK ON
COLUMN first_name CLEAR
COLUMN last_name CLEAR
TTITLE OFF



