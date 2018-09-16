/*
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
Data Load Method 2: Insert Using Substitution Variables
Done By: Daniel Urbach
*/

INSERT INTO  course(Course_number, Title, Room_number, Department, Instructor_name)
values ('&Course_number', '&Title','&Room_number','&Department','&Instructor_name');
