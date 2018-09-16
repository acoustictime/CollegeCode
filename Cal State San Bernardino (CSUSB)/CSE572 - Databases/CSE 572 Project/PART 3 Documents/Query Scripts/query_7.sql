/*
Present a report of the names and student ids of students with their 
	room number and place number in a particular hall of residence.
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
DONE BY: James Small
*/

set linesize 400
set pagesize 100
TTITLE "Query 7"
SET FEEDBACK OFF
COLUMN first_name HEADING "First Name" format a15
COLUMN last_name HEADING "Last Name" format a15
COLUMN student_number HEADING "Student ID" format a12
COLUMN room_number HEADING "Room #" format a12
COLUMN place_number HEADING "Place #" format a12

select s.first_name, s.last_name, s.student_number, r.room_number, r.place_number
from student s, rents r
where s.student_number = r.student_number AND s.residence_type = 'Residence Hall';

SET FEEDBACK ON
TTITLE OFF
COLUMN first_name CLEAR
COLUMN last_name CLEAR
COLUMN student_number CLEAR
COLUMN room_number CLEAR
COLUMN place_number CLEAR


