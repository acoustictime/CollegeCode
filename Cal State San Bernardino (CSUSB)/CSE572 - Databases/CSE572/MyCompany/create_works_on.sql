CREATE TABLE Works_On
  ( ESSN   char(9),   
    PNO    number,      
    HOURS   decimal(3,1)  CONSTRAINT Works_On_Hours_NN NOT NULL, 
    CONSTRAINT Works_On_ESSN_PNO_PK PRIMARY KEY(ESSN,PNO)
);
