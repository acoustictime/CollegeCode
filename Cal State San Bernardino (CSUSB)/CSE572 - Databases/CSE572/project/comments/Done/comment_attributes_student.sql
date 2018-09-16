/*
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
Comments on Attributes for Student
COMMENT BY: James Small
*/

COMMENT ON COLUMN student.student_number 
IS 'The number that uniquely identifies each student at the university - Format: 600001';

COMMENT ON COLUMN student.first_name
IS 'The first name of the student - Format: John';

COMMENT ON COLUMN student.last_name
IS 'The last name of the student - Format: Smith';

COMMENT ON COLUMN student.gender
IS 'The gender of the student - Format: M';

COMMENT ON COLUMN student.date_of_birth
IS 'The date of birth for the student - Format: 05-JAN-85';

COMMENT ON COLUMN student.current_status
IS 'Shows whether a student is currently renting or on the waitlist - Format: Renting';

COMMENT ON COLUMN student.additional_comments
IS 'Any additional information pertaining to the student not mentioned elsewhere - Format: Text';

COMMENT ON COLUMN student.residence_type
IS 'Shows the type of residence the student is currently renting - Format: Student Apartment';

COMMENT ON COLUMN student.minor
IS 'The students minor if applicable - Format: Philosphy';

COMMENT ON COLUMN student.major
IS 'The students major at the university- Format: Philosphy';

COMMENT ON COLUMN student.special_needs
IS 'Information in this field lets us know whether there is any special accomodations needed for the student - Format: Blind';

COMMENT ON COLUMN student.street
IS 'The street the student lives on - Format: 123 Four St';

COMMENT ON COLUMN student.city
IS 'The city the student lives in - Format: Riverside';

COMMENT ON COLUMN student.state
IS 'The state the student lives in - Format: CA';

COMMENT ON COLUMN student.zip
IS 'The zip code the student lives in - Format: 92504';

COMMENT ON COLUMN student.nationality
IS 'The nation of origin or naturalization of student - Format: German';

COMMENT ON COLUMN student.class
IS 'The standing of student in terms of academic progress - Format: Junior';

COMMENT ON COLUMN student.phone_number
IS 'The phone number of the student, if applicable - Format: 909-844-8887';

COMMENT ON COLUMN student.email_address
IS 'The email address of the student- Format: agonz@gmail.com';

COMMENT ON COLUMN student.advisor_number
IS 'Foreign key referencing advisor_number in advisor.  Shows which advisor is responsible for advising this particular student - Format: 1001';




