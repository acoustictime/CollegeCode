/*
Present a report listing the names and student ids of students with the details of their lease agreements.
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
DONE BY: Mark Takahashi
*/

set linesize 400
set pagesize 100
SET FEEDBACK OFF
TTITLE "Query 2"
COLUMN first_name HEADING "First Name" format a10
COLUMN last_name HEADING "Last Name" format a10
COLUMN STUDENT_NUMBER HEADING "Student ID" format a12
COLUMN lease_number HEADING "Lease #" format a12
COLUMN duration HEADING "Duration" format a10
COLUMN rental_address HEADING "Rental Address" format a45
COLUMN move_out_date HEADING "Move Out Date" format a15
COLUMN move_in_date HEADING "Move In Date" format a15
COLUMN room_number HEADING "Room #" format a12
COLUMN phone_number HEADING "Phone #" format a12

select s.first_name, s.last_name, s.student_number, l.lease_number, l.duration,
	 l.rental_address, l.move_out_date, l.move_in_date, l.room_number, l.phone_number
from student s, lease l, rents r
where s.student_number = r.student_number AND r.lease_number = l.lease_number;

SET FEEDBACK ON
COLUMN first_name CLEAR
COLUMN last_name CLEAR
COLUMN student_number CLEAR
COLUMN lease_number CLEAR
COLUMN duration CLEAR
COLUMN rental_address CLEAR
COLUMN move_out_date CLEAR
COLUMN move_in_date ClEAR
COLUMN room_number CLEAR
COLUMN phone_number CLEAR


