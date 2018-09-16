/*
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
Data Load Method 1: Normal Insert - Insert SQL Command
Done By: Enrique Carbajal Jr.
*/

/*
CREATE TABLE Invoice (
Invoice_Number VARCHAR2(4) /*PK*
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
Student_Number VARCHAR2(6) /*FK*
	CONSTRAINT Invoice_Student_Number_NN NOT NULL,
Lease_Number VARCHAR2(4) /*FK*
	CONSTRAINT Invoice_Lease_Number_NN NOT NULL,
CONSTRAINT Invoice_Student_Number_FK
	FOREIGN KEY (Student_Number)
	REFERENCES Student (Student_Number) ON DELETE CASCADE,
CONSTRAINT Invoice_Lease_Number_FK
	FOREIGN KEY (Lease_Number)
	REFERENCES Lease (Lease_Number) ON DELETE CASCADE 
)
*/


INSERT INTO Invoice (Invoice_Number, Payment_Method, Rental_Address, Payment_Received_Date, Room_Number, Payment_Due_Date, Place_Number, Student_Number,
Lease_Number) 
values ( '4001', 'Credit', '1317 5th St. San Bernardino, CA. 92408', '25-SEP-12', '3003', '30-SEP-12',	'3', '600001', '10002');

INSERT INTO Invoice (Invoice_Number, Payment_Method, Rental_Address, Payment_Received_Date, Room_Number, Payment_Due_Date, Place_Number, Student_Number,
Lease_Number) 
values ( '4002', 'Debit', '1621 Euerka St. San Bernardino, CA. 92407', '25-SEP-12', '3002', '30-SEP-12', '2', '600002', '10001');

INSERT INTO Invoice (Invoice_Number, Payment_Method, Rental_Address, Payment_Received_Date, Room_Number, Payment_Due_Date, Place_Number, Student_Number,
Lease_Number) 
values ( '4003','Cash',	'14 University Ave, San Bernardino, CA. 92407',	'14-SEP-12','3004','30-SEP-12',	'4',	'600003','10003');

INSERT INTO Invoice (Invoice_Number, Payment_Method, Rental_Address, Payment_Received_Date, Room_Number, Payment_Due_Date, Place_Number, Student_Number,
Lease_Number) 
values ( '4004','Credit','74 Euerka St. San Bernardino, Ca. 92408','26-SEP-12','3005','30-SEP-12','5','600004','10004');

INSERT INTO Invoice (Invoice_Number, Payment_Method, Rental_Address, Payment_Received_Date, Room_Number, Payment_Due_Date, Place_Number, Student_Number,
Lease_Number) 
values ( '4005','Cash','14 Market Ave. San Bernardino, CA. 92408','24-SEP-12','3007','30-SEP-12','7','600005','10006');

INSERT INTO Invoice (Invoice_Number, Payment_Method, Rental_Address, Payment_Received_Date, Room_Number, Payment_Due_Date, Place_Number, Student_Number,
Lease_Number) 
values ( '4006','Credit','123 4th St. San Bernardino, CA. 92407','03-OCT-12','3006','30-SEP-12','6','600007','10005');

INSERT INTO Invoice (Invoice_Number, Payment_Method, Rental_Address, Payment_Received_Date, Room_Number, Payment_Due_Date, Place_Number, Student_Number,
Lease_Number) 
values ( '4007','Check','280 Drake Dr. San Bernardino, CA. 92408','29-SEP-12','3009','30-SEP-12','9','600006','10008');

INSERT INTO Invoice (Invoice_Number, Payment_Method, Rental_Address, Payment_Received_Date, Room_Number, Payment_Due_Date, Place_Number, Student_Number,
Lease_Number) 
values ('4008','Credit','654 Lincoln Ave. San Bernardino, Ca. 92408','27-SEP-12','3010','30-SEP-12','10','600008','10009');

INSERT INTO Invoice (Invoice_Number, Payment_Method, Rental_Address, Payment_Received_Date, Room_Number, Payment_Due_Date, Place_Number, Student_Number,
Lease_Number) 
values ('4009','Check','35 Kinsey Ave. San Bernardino, CA. 92407','29-SEP-12','3008','30-SEP-12','8','600009','10007');

INSERT INTO Invoice (Invoice_Number, Payment_Method, Rental_Address, Payment_Received_Date, Room_Number, Payment_Due_Date, Place_Number, Student_Number,
Lease_Number) 
values ('4010','Check','719 Waterman Ave. San Bernardino, CA. 92408','28-SEP-12','3011','30-SEP-12','11','600010','10010');

INSERT INTO Invoice (Invoice_Number, Payment_Method, Rental_Address, Payment_Received_Date, Room_Number, Payment_Due_Date, Place_Number, Student_Number,
Lease_Number) 
values ('4011','Check','35 Kinsey Ave. San Bernardino, CA. 92407','14-JAN-13','3008','30-JAN-13','8','600009','10007');

INSERT INTO Invoice (Invoice_Number, Payment_Method, Rental_Address, Payment_Received_Date, Room_Number, Payment_Due_Date, Place_Number, Student_Number,
Lease_Number) 
values ('4012','Credit','4564 Waver Ave. San Bernardino, Ca. 92408','24-SEP-12','3012','30-SEP-12','12','600011','10011');

INSERT INTO Invoice (Invoice_Number, Payment_Method, Rental_Address, Payment_Received_Date, Room_Number, Payment_Due_Date, Place_Number, Student_Number,
Lease_Number) 
values ('4013','Check','719 Waterman Ave. San Bernardino, CA. 92408','13-JAN-13','3011','30-JAN-13','11','600010','10010');

INSERT INTO Invoice (Invoice_Number, Payment_Method, Rental_Address, Payment_Received_Date, Room_Number, Payment_Due_Date, Place_Number, Student_Number,
Lease_Number) 
values ('4014','Check','4135 Sierra St. San Bernardino, CA. 92408','27-SEP-12','3001','30-SEP-12','1','600014',	'10000');

INSERT INTO Invoice (Invoice_Number, Payment_Method, Rental_Address, Payment_Received_Date, Room_Number, Payment_Due_Date, Place_Number, Student_Number,
Lease_Number) 
values ('4015','Debit','1621 Euerka St. San Bernardino, CA. 92407','10-FEB-13','3002','30-JAN-13','2','600002','10001');

INSERT INTO Invoice (Invoice_Number, Payment_Method, Rental_Address, Payment_Received_Date, Room_Number, Payment_Due_Date, Place_Number, Student_Number,
Lease_Number) 
values ('4016','Credit','1317 5th St. San Bernardino, CA. 92408','27-JAN-13','3003','30-JAN-13','3','600001','10002');

INSERT INTO Invoice (Invoice_Number, Payment_Method, Rental_Address, Payment_Received_Date, Room_Number, Payment_Due_Date, Place_Number, Student_Number,
Lease_Number) 
values ('4017','Cash','14 University Ave, San Bernardino, CA. 92407','27-JAN-13','3004','30-JAN-13','4','600003','10003');

INSERT INTO Invoice (Invoice_Number, Payment_Method, Rental_Address, Payment_Received_Date, Room_Number, Payment_Due_Date, Place_Number, Student_Number,
Lease_Number) 
values ('4018','Cash','14 Market Ave. San Bernardino, CA. 92408','27-JAN-13','3007','30-JAN-13','7','600005','10006');	

/*							
Invoice Number	Payment Method	Rental Address	Payment Received Date	Room Number	Payment Due Date	Place Number	Student Number	Lease Number
4001	Credit	1317 5th St. San Bernardino, CA. 92408	9/25/2012	3003	9/30/2012	3	600001	10002
4002	Debit	1621 Euerka St. San Bernardino, CA. 92407	9/25/2012	3002	9/30/2012	2	600002	10001
4003	Cash	14 University Ave, San Bernardino, CA. 92407	9/14/2012	3004	9/30/2012	4	600003	10003
4004	Credit	74 Euerka St. San Bernardino, Ca. 92408	9/26/2012	3005	9/30/2012	5	600004	10004
4005	Cash	14 Market Ave. San Bernardino, CA. 92408	9/24/2012	3007	9/30/2012	7	600005	10006
4006	Credit	123 4th St. San Bernardino, CA. 92407	10/3/2012	3006	9/30/2012	6	600007	10005
4007	Check	280 Drake Dr. San Bernardino, CA. 92408	9/29/2012	3009	9/30/2012	9	600006	10008
4008	Credit	654 Lincoln Ave. San Bernardino, Ca. 92408	9/27/2012	3010	9/30/2012	10	600008	10009
4009	Check	35 Kinsey Ave. San Bernardino, CA. 92407	9/29/2012	3008	9/30/2012	8	600009	10007
4010	Check	719 Waterman Ave. San Bernardino, CA. 92408	9/28/2012	3011	9/30/2012	11	600010	10010
4011	Check	35 Kinsey Ave. San Bernardino, CA. 92407	1/14/2013	3008	1/30/2013	8	600009	10007
4012	Credit	4564 Waver Ave. San Bernardino, Ca. 92408	9/24/2012	3012	9/30/2012	12	600011	10011
4013	Check	719 Waterman Ave. San Bernardino, CA. 92408	1/13/2013	3011	1/30/2013	11	600010	10010
4014	Check	4135 Sierra St. San Bernardino, CA. 92408	9/27/2012	3001	9/30/2012	1	600014	10000
4015	Debit	1621 Euerka St. San Bernardino, CA. 92407	2/10/2013	3002	1/30/2013	2	600002	10001
4016	Credit	1317 5th St. San Bernardino, CA. 92408	1/27/2013	3003	1/30/2013	3	600001	10002
4017	Cash	14 University Ave, San Bernardino, CA. 92407	1/27/2013	3004	1/30/2013	4	600003	10003
4018	Cash	14 Market Ave. San Bernardino, CA. 92408	1/27/2013	3007	1/30/2013	7	600005	10006
*/
