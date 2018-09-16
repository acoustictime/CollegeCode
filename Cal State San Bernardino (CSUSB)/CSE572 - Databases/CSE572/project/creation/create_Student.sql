/*
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
CREATED BY: James Small
*/

CREATE TABLE Student (
Student_Number VARCHAR2(6) /*PK*/
	CONSTRAINT Student_PK PRIMARY KEY,
First_Name VARCHAR2(30)
	CONSTRAINT Student_First_Name_NN NOT NULL,
Last_Name VARCHAR2(30)
	CONSTRAINT Student_Last_Name_NN NOT NULL,
Gender CHAR(1)
	CONSTRAINT Student_Gender_NN NOT NULL,
Date_of_Birth DATE
	CONSTRAINT Student_Date_of_Birth_NN NOT NULL,
Current_Status VARCHAR2(7)
	CONSTRAINT Student_Current_Status_NN NOT NULL,
Additional_Comments VARCHAR2(4000),
Residence_Type VARCHAR2(17),
Minor VARCHAR2(30),
Major VARCHAR2(30)
	CONSTRAINT Student_Major_NN NOT NULL,
Special_Needs VARCHAR2(4000),
	Street VARCHAR2(30)
	CONSTRAINT Student_Street_NN NOT NULL,
City VARCHAR2(30)
	CONSTRAINT Student_City_NN NOT NULL,
State CHAR(2)
	CONSTRAINT Student_State_NN NOT NULL,
Zip VARCHAR2(10)
	CONSTRAINT Student_Zip_NN NOT NULL,
Nationality VARCHAR2(30),
Class VARCHAR2(12)
	CONSTRAINT Student_Class_NN NOT NULL,
Phone_Number VARCHAR2(10),
Email_Address VARCHAR2(60),
Advisor_Number CHAR(4) /*FK*/
	CONSTRAINT Student_Advisor_Number_NN NOT NULL,
CONSTRAINT Student_Advisor_Number_FK 
	FOREIGN KEY (Advisor_Number)
	REFERENCES Advisor (Advisor_Number) ON DELETE SET NULL
)
