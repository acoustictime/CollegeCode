/*
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
Comments on Attributes for Next_of_Kin
COMMENT BY: Enrique Carbajal Jr.
*/

/*
CREATE TABLE Next_of_Kin (
1 NOK_Name VARCHAR2(100) 
	CONSTRAINT NOK_PK PRIMARY KEY,
2 NOK_Phone_Number VARCHAR2(10)
	CONSTRAINT NOK_NOK_Phone_Number_NN NOT NULL,
3 NOK_Street VARCHAR2(30)
	CONSTRAINT NOK_NOK_Street_NN NOT NULL,
4 NOK_City VARCHAR2(30)
	CONSTRAINT NOK_City_NN NOT NULL,
5 NOK_State CHAR(2)
	CONSTRAINT NOK_State_NN NOT NULL,
6 NOK_Zip VARCHAR2(10)
	CONSTRAINT NOK_NOK_Zip_NN NOT NULL 
)
*/
--1
comment on columnn Next_of_Kin.NOK_Name
is 'This is the next of kins name--Format: Enrique Carbajal Jr. '; 
--2
comment on columnn Next_of_Kin.NOK_Phone_Number  
is 'This is the NOKs phone number --Format: 995-846-7778'; 
--3
comment on columnn Next_of_Kin.NOK_Street 
is 'This is the NOKs street address --Format: 987 Alpha St'; 
--4
comment on columnn Next_of_Kin.NOK_City 
is 'This is the NOKs current resident city --Format: Riverside'; 
--5
comment on columnn Next_of_Kin.NOK_State 
is 'This is the NOKs current resident State --Format: CA'; 
--6
comment on columnn Next_of_Kin.NOK_Zip 
is 'This is the NOKs current resident zip code --Format: 92504 '; 
