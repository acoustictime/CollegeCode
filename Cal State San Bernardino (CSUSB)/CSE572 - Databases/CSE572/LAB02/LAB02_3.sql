select upper(lname), length(lname)
from jmendoza.employee
where substr(lname,1,1)='J' or substr(lname,1,1)='B' or substr(lname,1,1)='Z'
/
