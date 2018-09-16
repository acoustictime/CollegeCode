select e.fname, e.lname, e.salary, e.address
from jmendoza.employee e, (select avg(ee.salary) avg_salary , ee.dno
		  from jmendoza.employee ee
		  group by ee.dno) d
where e.dno = d.dno AND e.salary > d.avg_salary
