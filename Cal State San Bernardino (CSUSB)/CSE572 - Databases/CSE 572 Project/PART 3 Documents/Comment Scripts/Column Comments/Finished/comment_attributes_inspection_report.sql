/*
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
Comments on Attributes for Inspection_Report
COMMENT BY: Daniel Urbach
*/
COMMENT ON COLUMN Inspection_Report.Inspection_Date
IS 'The date and time when an Inspection was conducted - format: 01-MAY-11 12:00:00';
COMMENT ON COLUMN Inspection_Report.Satisfactory
IS 'The overall status of the Inspection Report - format: Unsatisfactory';
COMMENT ON COLUMN Inspection_Report.Comments
IS 'Additional comments on the status of Student Apartment, made by the Staff Member who makes the Inspection Report - format: The students in this apartment are super cool, and they keep a clean shop. However one of the chairs at their diningroom table is broken; I questioned them about this and they claimed it was that way when they moved in.';
COMMENT ON COLUMN Inspection_Report.Apartment_Number
IS 'Foreign key referencing Apartment_Number in Student Apartment, the unique identifier for Student Apartment - format: 7001';
