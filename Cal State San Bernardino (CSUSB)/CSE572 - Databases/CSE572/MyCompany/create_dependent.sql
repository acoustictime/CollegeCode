CREATE TABLE Dependent
   (essn     char(9), 
    dependent_name     varchar2(15) CONSTRAINT 
          Dependent_dependent_name_NN NOT NULL,
    gender     char,
    bdate     date,
    relationship varchar2(8),
    CONSTRAINT Dependent_Essn_DepName_PK 
        PRIMARY KEY(essn, dependent_name)
);
