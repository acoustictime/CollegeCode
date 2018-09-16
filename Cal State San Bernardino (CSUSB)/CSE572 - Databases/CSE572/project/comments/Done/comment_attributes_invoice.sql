/*
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
Comments on Attributes for Invoice
COMMENT BY: Enrique Carbajal Jr.
*/
/*
CREATE TABLE Invoice (
Invoice_Number VARCHAR2(4) PK
	CONSTRAINT Invoice_PK PRIMARY KEY,

Payment_Method VARCHAR2(5)
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

Student_Number VARCHAR2(6) 
	CONSTRAINT Invoice_Student_Number_NN NOT NULL,

Lease_Number VARCHAR2(4) 
	CONSTRAINT Invoice_Lease_Number_NN NOT NULL,
    
	CONSTRAINT Invoice_Student_Number_FK
	FOREIGN KEY (Student_Number)
	REFERENCES Student (Student_Number) ON DELETE CASCADE,

CONSTRAINT Invoice_Lease_Number_FK
	FOREIGN KEY (Lease_Number)
	REFERENCES Lease (Lease_Number) ON DELETE CASCADE */

comment on column Invoice.Invoice_Number
is 'Primary key identifying the invoice -- Format: 4001';

comment on column Invoice.Payment_Method 
is 'The method of payment the student presented --Format: Credit';

comment on column Invoice.Rental_Address 
is 'The address of the rental property -- Format: 1317 5th St. San Bernardino, CA. 92408';

comment on column Invoice.Payment_Received_date 
is 'The date of when the payment was received-- Format:9/25/2012';

comment on column Invoice.Room_Number 
is 'The room number that was leased-- Format:9/25/2012';

comment on column Invoice.Payment_Due_Date
is 'The due date of the payment -- Format: 9/30/2012';

comment on column Invoice.Place_Number
is 'The place number the invoice refers to -- Format: 3';

comment on column Invoice.Student_Number
is 'Foreign Key referencing Student relation. The student number that is the owner of the invoice -- Format: 600014';

comment on column Invoice.Lease_Number
is 'Foreign key referencing Lease Number table. This is the Lease Number that this invoice belongs to -- Format:10000';


