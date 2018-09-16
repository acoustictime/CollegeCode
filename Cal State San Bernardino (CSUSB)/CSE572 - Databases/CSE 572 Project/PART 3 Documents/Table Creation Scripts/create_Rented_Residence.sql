/*
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
CREATED BY: Mark Takahashi
*/

CREATE TABLE Rented_Residence (
Residence_Number CHAR(4) /*PK*/
	CONSTRAINT Rented_Residence_PK PRIMARY KEY,
Address VARCHAR2(200)
	CONSTRAINT Rented_Residence_Address_NN NOT NULL 
)
