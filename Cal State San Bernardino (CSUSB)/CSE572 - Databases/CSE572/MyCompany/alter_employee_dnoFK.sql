ALTER TABLE Employee
ADD CONSTRAINT Employee_dno_FK FOREIGN KEY(dno)
    REFERENCES Department(dnumber);
