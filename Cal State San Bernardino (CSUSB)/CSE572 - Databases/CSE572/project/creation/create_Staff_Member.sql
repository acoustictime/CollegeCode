/*
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
CREATED BY: James Small
*/

CREATE TABLE Staff_Member (
Staff_Number CHAR(4) /*PK*/
	CONSTRAINT Staff_Member_PK PRIMARY KEY,
First_Name VARCHAR2(30)
	CONSTRAINT Staff_Member_First_Name_NN NOT NULL,
Last_Name VARCHAR2(30)
	CONSTRAINT Staff_Member_Last_Name_NN NOT NULL,
Date_of_Birth DATE DEFAULT SYSDATE
	CONSTRAINT Staff_Member_Date_of_Birth_NN NOT NULL,
Gender CHAR(1)
	CONSTRAINT Staff_Member_Gender_NN NOT NULL
	CONSTRAINT Staff_Member_Gender_CK CHECK (Gender in ('F','f','M','m')),
Street VARCHAR2(30)
	CONSTRAINT Staff_Member_Street_NN NOT NULL,
City VARCHAR2(30)
	CONSTRAINT Staff_Member_City_NN NOT NULL,
State CHAR(2)
	CONSTRAINT Staff_Member_State_NN NOT NULL,
Zip VARCHAR2(10)
	CONSTRAINT Staff_Member_Zip_NN NOT NULL,
Location VARCHAR2(30)
	CONSTRAINT Staff_Member_Location_NN NOT NULL,
Position VARCHAR2(30)
	CONSTRAINT Staff_Member_Position_NN NOT NULL,
Email_Address VARCHAR2(60)
	CONSTRAINT Staff_Member_Email_CK CHECK (email_address like '%@%') 
)

