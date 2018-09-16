select ssn, lname
from jmendoza.employee
where salary > (select avg(salary)
		from jmendoza.employee)
order by salary
