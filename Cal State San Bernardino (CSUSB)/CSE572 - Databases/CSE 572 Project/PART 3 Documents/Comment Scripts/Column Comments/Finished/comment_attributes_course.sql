/*
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
Comments on Attributes for Course
COMMENT BY: Daniel Urbach
*/
COMMENT ON COLUMN Course.Course_Number
IS 'The unique identifer for Course acting as primary key - format: CSE572';
COMMENT ON COLUMN Course.Title
IS 'The descriptive name of the Course - format: Database Systems';
COMMENT ON COLUMN Course.Room_Number
IS 'The location where the Course is conducted - format: JB359';
COMMENT ON COLUMN Course.Department
IS 'The department which the Course belongs to - format: Computer Science';
COMMENT ON COLUMN Course.Instructor_Name
IS 'Foreign key referencing Instructor_Name in the Instructor relation, name of the instructor teaching the Course - format: Josephine Mendoza';
