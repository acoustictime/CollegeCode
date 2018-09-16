/*
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
CREATED BY: Daniel Urbach
*/

CREATE TABLE Course (
Course_Number VARCHAR2(7) /*PK*/
	CONSTRAINT Course_PK PRIMARY KEY,
Title VARCHAR2(30)
	CONSTRAINT Course_Title_NN NOT NULL,
Room_Number VARCHAR2(10)
	CONSTRAINT Course_Room_Number_NN NOT NULL,
Department VARCHAR2(30)
	CONSTRAINT Course_Department_NN NOT NULL,
Instructor_Name	VARCHAR2(100) /*FK*/
	CONSTRAINT Course_Instructor_Name_NN NOT NULL,
CONSTRAINT Course_Instructor_Name_FK
	FOREIGN KEY (Instructor_Name)
	REFERENCES Instructor(Instructor_Name) ON DELETE SET NULL 
)

