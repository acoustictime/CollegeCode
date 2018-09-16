/*
Display the details of apartment inspections where the property was 
	found to be in an unsatisfactory condition.
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
DONE BY: Enrique Carbajal
*/

set linesize 400
set pagesize 50
TTITLE "Query 6"
SET FEEDBACK OFF
COLUMN inspection_date HEADING "Inspection Date" format a17
COLUMN satisfactory HEADING "Satisfactory" format a17
COLUMN comments HEADING "Comments" format a62
COLUMN apartment_number HEADING "Apt #" format a10

select inspection_date, satisfactory, comments, apartment_number
from inspection_report
where satisfactory = 'Unsatisfactory';

TTITLE OFF
SET FEEDBACK ON
COLUMN inspection_date CLEAR
COLUMN satisfactory CLEAR
COLUMN comments CLEAR
COLUMN apartment_number CLEAR


