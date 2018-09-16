/*
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
CREATED BY: Mark Takahashi
*/

CREATE TABLE Residence_Hall (
RH_Name VARCHAR2(25) /*PK*/
	CONSTRAINT RH_PK PRIMARY KEY,
Hall_Manager VARCHAR2(100)
	CONSTRAINT RH_Manager_NN NOT NULL,
Phone_Number VARCHAR2(10)
	CONSTRAINT RH_Phone_Number_NN NOT NULL,
Residence_Number CHAR(4) /*FK*/
	CONSTRAINT RH_Residence_Number_NN NOT NULL,
CONSTRAINT RH_Residence_Number_FK
	FOREIGN KEY (Residence_Number)
	REFERENCES Rented_Residence (Residence_Number) 
)
