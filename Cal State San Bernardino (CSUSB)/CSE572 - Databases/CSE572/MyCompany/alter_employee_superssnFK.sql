ALTER TABLE Employee
ADD CONSTRAINT Employee_Superssn_FK 
    FOREIGN KEY(superssn)
    REFERENCES Employee(SSN)
    ON DELETE SET NULL;
