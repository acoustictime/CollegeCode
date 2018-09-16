CREATE TABLE Employee
   (fname     varchar2(15)   constraint Employee_fname_NN NOT NULL,
    minit     char,
    lname     varchar2(15)   constraint Employee_lname_NN NOT NULL,
    ssn       char(9)        constraint Employee_ssn_PK PRIMARY KEY,
    bdate     date,
    address   varchar2(30),
    gender    char,
    salary    decimal(10,2),
    superssn  char(9),  
    dno       number
)
