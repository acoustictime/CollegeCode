/*
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
CREATED BY: Enrique Carbajal
*/

CREATE TABLE Lease (
Lease_Number VARCHAR2(5) /*PK*/
	CONSTRAINT Lease_PK PRIMARY KEY,
Duration CHAR(1)
	CONSTRAINT Lease_Duration_NN NOT NULL,
Rental_Address VARCHAR2(300)
	CONSTRAINT Lease_Rental_Address_NN NOT NULL,	
Move_Out_Date DATE
	CONSTRAINT Lease_Move_Out_Date_NN NOT NULL,
Move_In_Date DATE
	CONSTRAINT Lease_Move_In_Date_NN NOT NULL,
Room_Number VARCHAR2(7)
	CONSTRAINT Lease_Room_Number_NN NOT NULL,
Phone_Number VARCHAR2(10)
	CONSTRAINT LEASE_Phone_Number_NN NOT NULL 
)
