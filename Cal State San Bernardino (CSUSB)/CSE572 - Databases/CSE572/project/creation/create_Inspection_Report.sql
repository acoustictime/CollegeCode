/*
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
CREATED BY: Daniel Urbach
*/

CREATE TABLE Inspection_Report (
Inspection_Date DATE, /*PA*/
Satisfactory CHAR(20)
	CONSTRAINT IR_Satisfactory_NN NOT NULL,
Comments VARCHAR2(4000)
	CONSTRAINT IR_Comments_NN NOT NULL,
Apartment_Number VARCHAR2(6), /*PA,FK*/
CONSTRAINT Inspection_Report_PK
	PRIMARY KEY (Inspection_Date, Apartment_Number),
CONSTRAINT IR_Apartment_Number_FK
	FOREIGN KEY (Apartment_Number)
	REFERENCES Student_Apartment (Apartment_Number) ON DELETE CASCADE 
)
