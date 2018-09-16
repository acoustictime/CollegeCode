/*
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
Data Load Method 2: Insert Using Substitution Variables
Done By: Enrique Carbajal Jr. 
*/

/*
CREATE TABLE Next_of_Kin (
NOK_Name VARCHAR2(100) /*PK*
	CONSTRAINT NOK_PK PRIMARY KEY,
NOK_Phone_Number VARCHAR2(10)
	CONSTRAINT NOK_NOK_Phone_Number_NN NOT NULL,
NOK_Street VARCHAR2(30)
	CONSTRAINT NOK_NOK_Street_NN NOT NULL,
NOK_City VARCHAR2(30)
	CONSTRAINT NOK_City_NN NOT NULL,
NOK_State CHAR(2)
	CONSTRAINT NOK_State_NN NOT NULL,
NOK_Zip VARCHAR2(10)
	CONSTRAINT NOK_NOK_Zip_NN NOT NULL 
) */



INSERT INTO Next_of_Kin ( NOK_Name, NOK_Phone_Number, NOK_Street, NOK_City, NOK_State, NOK_Zip)
values( '&NOK_Name', '&NOK_Phone_Number', '&NOK_Street', '&NOK_City', '&NOK_State', '&NOK_Zip');
