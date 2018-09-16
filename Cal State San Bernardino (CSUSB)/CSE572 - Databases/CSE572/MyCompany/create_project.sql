CREATE TABLE Project
   (pname     varchar2(15)   CONSTRAINT Project_pname_NN NOT NULL
         constraint Project_pname_UK UNIQUE,
    pnumber   number   CONSTRAINT Project_pnumber_PK PRIMARY KEY,
    plocation varchar2(15),
    dnum      number   CONSTRAINT Project_dnum_NN NOT NULL
);
