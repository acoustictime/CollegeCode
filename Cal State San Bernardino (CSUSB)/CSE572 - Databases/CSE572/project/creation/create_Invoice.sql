/*
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
CREATED BY: Enrique Carbajal
*/

CREATE TABLE Invoice (
Invoice_Number VARCHAR2(4) /*PK*/
	CONSTRAINT Invoice_PK PRIMARY KEY,
Payment_Method VARCHAR2(6)
	CONSTRAINT Invoice_Payment_Method_NN NOT NULL,
Rental_Address VARCHAR2(300)
	CONSTRAINT Invoice_Rental_Address_NN NOT NULL,
Payment_Received_Date DATE,
Room_Number VARCHAR2(7)
	CONSTRAINT Invoice_Room_Number_NN NOT NULL,
Payment_Due_Date DATE
	CONSTRAINT Invoice_Payment_Due_Date_NN NOT NULL,
Place_Number VARCHAR2(4)
	CONSTRAINT Invoice_Place_Number_NN NOT NULL,
Student_Number VARCHAR2(6) /*FK*/
	CONSTRAINT Invoice_Student_Number_NN NOT NULL,
Lease_Number VARCHAR2(5) /*FK*/
	CONSTRAINT Invoice_Lease_Number_NN NOT NULL,
CONSTRAINT Invoice_Student_Number_FK
	FOREIGN KEY (Student_Number)
	REFERENCES Student (Student_Number) ON DELETE CASCADE,
CONSTRAINT Invoice_Lease_Number_FK
	FOREIGN KEY (Lease_Number)
	REFERENCES Lease (Lease_Number) ON DELETE CASCADE 
)
