select e.lname, d.dname
from jmendoza.employee e, jmendoza.department d
where e.dno = d.dnumber and lname like '%a%'
/
