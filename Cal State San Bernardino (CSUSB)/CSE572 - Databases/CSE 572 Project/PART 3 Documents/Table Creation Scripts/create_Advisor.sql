/*
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
CREATED BY: Daniel Urbach
*/

CREATE TABLE Advisor (
Advisor_Room_Number VARCHAR2(10)
	CONSTRAINT Advisor_Room_Number_NN NOT NULL,
Phone_Number VARCHAR2(10)
	CONSTRAINT Advisor_Phone_Number_NN NOT NULL,
Department VARCHAR2(30)
	CONSTRAINT Advisor_Department_NN NOT NULL,
Advisor_Number CHAR(4)		/*PK,FK*/
	CONSTRAINT Advisor_PK PRIMARY KEY,
CONSTRAINT Advisor_Advisor_Number_FK
	FOREIGN KEY (Advisor_Number)
	REFERENCES Staff_Member (Staff_Number) ON DELETE CASCADE
)
