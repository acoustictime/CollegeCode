/*
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
CREATED BY: Daniel Urbach
*/

CREATE TABLE Instructor (
Instructor_Name VARCHAR2(100) /*PK*/
	CONSTRAINT Instructor_PK PRIMARY KEY,
Instructor_Email VARCHAR2(60)
	CONSTRAINT Instructor_Email_NN NOT NULL,
Instructor_Phone VARCHAR2(10)
	CONSTRAINT Instructor_Phone_NN NOT NULL 
)
