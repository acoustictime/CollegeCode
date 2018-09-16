ALTER TABLE Dept_Locations
ADD CONSTRAINT Dept_Locations_dnumber_FK FOREIGN KEY(dnumber)
    REFERENCES Department(dnumber)
    ON DELETE CASCADE;
