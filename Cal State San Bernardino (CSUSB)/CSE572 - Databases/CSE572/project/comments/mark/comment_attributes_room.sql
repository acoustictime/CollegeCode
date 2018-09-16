/*
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
Comments on Attributes for Room
COMMENT BY: Mark Takahashi
*/

comment on column Room.Room_number
is 'The unique number associated with a Room - format: 1234';

comment on column Room.rent
is 'The ammount paid to live in the Room - format: 100.00';

comment on column Room.Residence_number
is 'Foreign key referencing Residence Number of Rented Residence - format: 1234';
