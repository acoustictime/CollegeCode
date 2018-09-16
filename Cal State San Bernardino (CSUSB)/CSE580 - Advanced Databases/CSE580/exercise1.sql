select e.fname, e.lname, e.salary, e.address
from jmendoza.employee e
where e.salary > (select avg(ee.salary)
		  from jmendoza.employee ee
		  where ee.dno = e.dno)



