CREATE VIEW DEPT04_Vu (EmpNo, Employee, DeptNo)
as select ssn, lname || ', ' || fname, dno
   from durbach.employee
   where dno = 4
WITH CHECK OPTION CONSTRAINT DNO04_VU_CK

