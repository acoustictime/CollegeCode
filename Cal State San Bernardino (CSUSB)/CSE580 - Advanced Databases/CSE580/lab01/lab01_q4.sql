select e.lname, e.dno, e.gender
from jmendoza.employee e, jmendoza.department d, jmendoza.dept_locations l
where e.dno = d.dnumber and d.dnumber = l.dnumber and l.dlocation = 'Bellaire'
