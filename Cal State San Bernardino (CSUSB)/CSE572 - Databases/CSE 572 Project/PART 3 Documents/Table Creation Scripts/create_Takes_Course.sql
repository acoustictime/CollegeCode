/*
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
CREATED BY: James Small
*/

CREATE TABLE Takes_Course (
Student_Number VARCHAR2(6) /*PA,FK*/,
Course_Number VARCHAR2(7) /*PA,FK*/,
CONSTRAINT Takes_Course_PK 
	PRIMARY KEY (Student_Number, Course_Number),
CONSTRAINT Takes_Course_Student_Number_FK
	FOREIGN KEY (Student_Number)
	REFERENCES Student (Student_Number) ON DELETE CASCADE,
CONSTRAINT Takes_Course_Course_Number_FK
	FOREIGN KEY (Course_Number)
	REFERENCES Course (Course_Number) ON DELETE CASCADE 
)
