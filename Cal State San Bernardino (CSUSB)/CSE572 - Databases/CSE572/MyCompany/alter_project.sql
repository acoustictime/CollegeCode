ALTER TABLE Project
ADD CONSTRAINT Project_dnum_FK FOREIGN KEY(dnum)
    REFERENCES Department(dnumber)
    ON DELETE CASCADE;
