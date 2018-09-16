CREATE TABLE Dept_Locations
  ( dnumber   number,  
    dlocation varchar2(15),
    CONSTRAINT Dept_Locations_dnu_dloc_PK 
      PRIMARY KEY(dnumber,dlocation)
);
