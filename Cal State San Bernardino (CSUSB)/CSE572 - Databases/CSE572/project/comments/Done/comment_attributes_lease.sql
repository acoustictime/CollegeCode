/*
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
Comments on Attributes for Lease
COMMENT BY: Enrique Carbajal Jr. 
*/

/* CREATE TABLE Lease (
1 Lease_Number VARCHAR2(5) 
	CONSTRAINT Lease_PK PRIMARY KEY,
2 Duration CHAR(1)
	CONSTRAINT Lease_Duration_NN NOT NULL,
3 Rental_Address VARCHAR2(300)
	CONSTRAINT Lease_Rental_Address_NN NOT NULL,	
4 Move_Out_Date DATE
	CONSTRAINT Lease_Move_Out_Date_NN NOT NULL,
5 Move_In_Date DATE
	CONSTRAINT Lease_Move_In_Date_NN NOT NULL,
6 Room_Number VARCHAR2(7)
	CONSTRAINT Lease_Room_Number_NN NOT NULL,
7 Phone_Number VARCHAR2(10)
	CONSTRAINT LEASE_Phone_Number_NN NOT NULL 
) 
comment on column Invoice.Payment_Method 
is 'The method of payment the student presented --Format: Credit';
*/

comment on column Lease.Lease_Number 
is 'The unique number associated with the lease -- Format:10000' ;

comment on column Lease.Duration 
is 'The time period of the lease -- Format:1' ;

comment on column Lease.Rental_Address 
is ' The address of the rental property-- Format:4135 Sierra St. San Bernardino, CA. 92408 ';

comment on column Lease.Move_Out_Date
is 'The date the renters have to vacate the property -- Format:12/15/2012 ';

comment on column Lease.Move_In_Date
is 'The date that renters take possession -- Format:8/30/2012 ';

comment on column Lease.Room_Number 
is 'Which room is being leased -- Format: 3001 ';

comment on column Lease.Phone_Number 
is 'The phone number of the lessee-- Format: 909-303-3030 ';
