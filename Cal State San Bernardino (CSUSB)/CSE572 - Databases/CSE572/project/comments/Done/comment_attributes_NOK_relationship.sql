/*
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
TABLE COMMENT BY: Daniel Urbach
*/
COMMENT ON column NOK_Relationship.Student_Number
IS 'Foreign key referencing Student Number in Student relation, part of the primary key - format: 123456';
COMMENT ON column NOK_Relationship.NOK_Name
IS 'Foreign key referencing NOK Name in Next of Kin relation, part of the primary key - format: Jimmy Dean';
COMMENT ON column NOK_Relationship.NOK_Relationship
IS 'The relationship between a student and the next of kin - format: Brother';
