select e.lname, e.dno, d.dname
from jmendoza.employee e, jmendoza.department d
where e.dno = d.dnumber
/
