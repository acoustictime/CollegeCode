/*
Present a report listing the Manager’s name and telephone number for each hall of residence.
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
DONE BY: Mark Takahashi
*/

set linesize 400
SET FEEDBACK OFF
TTITLE "Query 1"
COLUMN hall_manager HEADING "Hall Manager"
COLUMN phone_number HEADING "Phone Number"
COLUMN hall_manager format a20
COLUMN phone_number format a15

select  Hall_Manager, Phone_Number
from Residence_Hall;

SET FEEDBACK ON
COLUMN hall_manager CLEAR
COLUMN phone_number CLEAR



