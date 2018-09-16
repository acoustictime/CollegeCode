select lname, bdate
from jmendoza.employee
where dno = (select dno
	     from jmendoza.employee
 	     where lname = 'Wallace')

	     minus

             (select lname, bdate
             from jmendoza.employee
             where lname = 'Wallace')

