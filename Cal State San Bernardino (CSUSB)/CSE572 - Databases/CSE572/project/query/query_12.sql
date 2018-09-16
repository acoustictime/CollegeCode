/*
Display the minimum, maximum, and average monthly rent for rooms in residence halls.
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
DONE BY: James Small
*/

set linesize 400
set pagesize 100
SET FEEDBACK OFF
TTITLE "Query 12"

select min(ro.rent) "Min Rent", max(ro.rent) "Max Rent", avg(ro.rent) "Avg Rent"
from room ro,rented_residence rr, residence_hall rh
where ro.residence_number = rr.residence_number AND rr.residence_number = rh.residence_number;

SET FEEDBACK ON
TTITLE OFF


