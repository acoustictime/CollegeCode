ALTER TABLE Department
ADD CONSTRAINT Department_mgrssn_FK FOREIGN KEY(mgrssn)
    REFERENCES Employee(SSN);
