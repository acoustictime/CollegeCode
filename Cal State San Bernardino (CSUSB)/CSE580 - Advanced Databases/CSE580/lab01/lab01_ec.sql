select ssn, lname, salary
from jmendoza.employee
where salary > (select avg(salary)
		from jmendoza.employee)

		and

		dno in (select dno
	   		      from jmendoza.employee
	                      where lower(lname) like '%n%')
