ALTER TABLE Dependent
ADD CONSTRAINT dependent_essn_FK 
    FOREIGN KEY(essn)
    REFERENCES Employee(ssn)
    ON DELETE CASCADE;
