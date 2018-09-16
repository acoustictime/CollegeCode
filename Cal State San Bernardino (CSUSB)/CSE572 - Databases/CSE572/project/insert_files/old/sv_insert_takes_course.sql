/*
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
Data Load Method 2: Insert Using Substitution Variables
Done By: James Small
*/

INSERT INTO  staff_member(Staff_number, First_name,Last_Name,Date_Of_Birth,Gender,Street,City,State,Zip,Location,Position,Email_address)
values ('&Staff_number', '&First_name','&Last_Name','&Date_Of_Birth','&Gender','&Street','&City','&State','&Zip','&Location','&Position','&Email_address');
