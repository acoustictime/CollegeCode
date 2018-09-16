/*
Display the total number of students in each student category.
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
DONE BY: Daniel Urbach
*/

set linesize 400
set pagesize 100
SET FEEDBACK OFF
TTITLE "Query 9"
COLUMN class HEADING "Class" format a15

select class, count(*) "Count"
from student
group by class;

SET FEEDBACK ON
TTITLE OFF
COLUMN class CLEAR


