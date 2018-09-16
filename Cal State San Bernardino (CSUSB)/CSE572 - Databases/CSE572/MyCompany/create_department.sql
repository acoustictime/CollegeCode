CREATE TABLE Department
   (dname     varchar2(15)   constraint Department_dname_NN NOT NULL
         constraint Department_dname_UK UNIQUE,
    dnumber   number  constraint Department_dnumber_PK PRIMARY KEY,
    mgrssn       char(9)     constraint Department_mgrssn_NN NOT NULL,
    mgrstartdate  date
);
