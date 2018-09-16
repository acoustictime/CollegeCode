/*
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
CREATED BY: Mark Takahashi
*/

CREATE TABLE Rents (
Place_Number VARCHAR2(4)
	CONSTRAINT Rents_Place_Number_NN NOT NULL,
Student_Number VARCHAR2(6), /*PA,FK*/
Room_Number VARCHAR2(4), /*PA,FK*/
Lease_Number VARCHAR2(4), /*PA,FK*/
CONSTRAINT Rents_PK 
	PRIMARY KEY (Student_Number, Room_Number, Lease_Number),
CONSTRAINT Rents_Student_Number_FK
	FOREIGN KEY (Student_Number)
	REFERENCES Student (Student_Number) ON DELETE CASCADE,
CONSTRAINT Rents_Room_Number_FK
	FOREIGN KEY (Room_Number)
	REFERENCES Room (Room_Number) ON DELETE CASCADE,
CONSTRAINT Rents_Lease_Number_FK
	FOREIGN KEY (Lease_Number)
	REFERENCES Lease (Lease_Number) ON DELETE CASCADE 
)
