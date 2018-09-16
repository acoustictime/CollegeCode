/*
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
CREATED BY: James Small
*/

CREATE TABLE Student_Apartment (
Apartment_Number VARCHAR2(6) /*PK*/
	CONSTRAINT SA_PK PRIMARY KEY,
Available_Rooms NUMBER(4)
	CONSTRAINT SA_Available_Rooms_NN NOT NULL,
Staff_Number CHAR(4) /*FK*/
	CONSTRAINT SA_Staff_Number_NN NOT NULL,
Residence_Number CHAR(4) /*FK*/
	CONSTRAINT SA_Residence_Number_NN NOT NULL,
CONSTRAINT SA_Staff_Number_FK
	FOREIGN KEY (Staff_Number)
	REFERENCES Staff_Member(Staff_Number) ON DELETE SET NULL,
CONSTRAINT SA_Residence_Number_FK
	FOREIGN KEY (Residence_Number)
	REFERENCES Rented_Residence(Residence_Number) 
)
