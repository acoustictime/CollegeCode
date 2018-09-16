/*
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
Comments on Attributes for Student_Apartment
COMMENT BY: James Small
*/

COMMENT ON COLUMN student_apartment.apartment_number 
IS 'The number that uniquely identifies each apartment in the residence office - Format: 7001';

COMMENT ON COLUMN student_apartment.available_rooms 
IS 'The number of rooms available in a particular student apartment - Format: 3';

COMMENT ON COLUMN student_apartment.staff_number 
IS 'Foreign key referencing staff_number in staff_member.  This identifies the staff_member who inspects a stduent_apartment periodically - Format: 1001';

COMMENT ON COLUMN student_apartment.residence_number 
IS 'Foreign key referencing residence_number in Rented_residence.  This identifies the unique residence number among all residences managed by the residence office - Format: 2007';


