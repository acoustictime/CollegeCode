/*
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
Comments on Attributes for Rents
COMMENT BY: Mark Takahashi
*/

comment on column Rents.place_number
is 'The unique identifier of each instance of a Student renting a room - format: 1234';

comment on column Rents.student_number
is 'Foreign key referencing the Student Number of Student who is renting a room - format: 123456';

comment on column Rents.room_number
is 'Foreign key referencing the Room Number of the Room being rented - format: 1234';

comment on column Rents.lease_number
is 'Foreign key referencing the Lease Number of the Lease contracting the room rental to the student - format: 12345';
