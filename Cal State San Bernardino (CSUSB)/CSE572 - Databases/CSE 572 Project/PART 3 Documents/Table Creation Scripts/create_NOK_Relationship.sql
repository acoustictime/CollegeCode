/*
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
CREATED BY: James Small
*/

CREATE TABLE NOK_Relationship (
Student_Number VARCHAR2(6) /*PK*/
	CONSTRAINT nok_relationship_studentno_FK REFERENCES Student(Student_number) ON DELETE CASCADE, 
NOK_Name VARCHAR2(100) 
	CONSTRAINT nok_relationship_name_FK REFERENCES Next_of_Kin(NOK_Name) ON DELETE CASCADE, /*PK*/
NOK_Relationship VARCHAR2(30)
	CONSTRAINT NOK_NOK_Relationship_NN NOT NULL,
CONSTRAINT nok_relationship_PK PRIMARY KEY (student_number,nok_name)
)


