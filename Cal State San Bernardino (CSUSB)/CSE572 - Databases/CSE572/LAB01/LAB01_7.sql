select lname, dno, bdate
from jmendoza.employee
where bdate > to_date('01-JAN-60') and bdate < to_date('01-JUL-73')
order by bdate
/
