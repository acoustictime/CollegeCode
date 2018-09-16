/*
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
CREATED BY: Mark Takahashi
*/

CREATE TABLE Room (
Room_Number VARCHAR2(4) /*PA*/
	CONSTRAINT Room_Room_Number_UK UNIQUE,
Rent NUMBER(6,2)
	CONSTRAINT Room_Rent_NN NOT NULL,
Residence_Number CHAR(4), /*PA,FK*/
CONSTRAINT Room_PK
	PRIMARY KEY (Room_Number, Residence_Number),
CONSTRAINT Room_Residence_Number_FK
	FOREIGN KEY (Residence_Number)
	REFERENCES Rented_Residence (Residence_Number) ON DELETE CASCADE 
)
