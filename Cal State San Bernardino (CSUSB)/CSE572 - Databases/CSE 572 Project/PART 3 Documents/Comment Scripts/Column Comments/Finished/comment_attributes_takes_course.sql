/*
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
Comments on Attributes for Takes_Course
COMMENT BY: James Small
*/

COMMENT ON COLUMN takes_course.student_number 
IS 'Foreign key referencing student_number in Student relation.  Used as part of the composite primary key to represent a course a student is taking - Format: 6001';

COMMENT ON COLUMN takes_course.course_number 
IS 'Foreign key referencing course_number in Course relation.  Used as part of the composite primary key to represent a course a student is taking - Format: CSE572';
