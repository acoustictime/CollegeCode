CREATE VIEW Salary_Vu (Employee, Department, Salary)
as select lname, dname, salary
   from durbach.employee, durbach.department
   where dno = dnumber

