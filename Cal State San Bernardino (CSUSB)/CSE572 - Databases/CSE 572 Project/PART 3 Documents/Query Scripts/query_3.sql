/*
Display the details of lease agreements that include the summer quarter.
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
DONE BY: Mark Takahashi
*/

set linesize 400
set pagesize 100
SET FEEDBACK OFF
TTITLE "Query 3"
COLUMN lease_number HEADING "Lease #" format a12
COLUMN duration HEADING "Duration" format a10
COLUMN rental_address HEADING "Rental Address" format a45
COLUMN move_out_date HEADING "Move Out Date" format a15
COLUMN move_in_date HEADING "Move In Date" format a15
COLUMN room_number HEADING "Room #" format a7
COLUMN phone_number HEADING "Phone #" format a12

select lease_number, duration, rental_address, move_out_date, move_in_date, room_number, phone_number
from lease
where duration = '4';

SET FEEDBACK ON
COLUMN lease_number CLEAR
COLUMN duration CLEAR
COLUMN rental_address CLEAR
COLUMN move_out_date CLEAR
COLUMN move_in_date CLEAR
COLUMN room_number CLEAR
COLUMN phone_number CLEAR
TTITLE OFF


