select e.lname, e.salary
from jmendoza.employee e, jmendoza.employee d
where e.superssn = d.ssn and d.lname = 'Wallace'
