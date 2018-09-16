/*
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
Comments on Attributes for Residence_Hall
COMMENT BY: Mark Takahashi
*/

comment on column Residence_Hall.RH_Name
is 'The Name of the Residence Hall - format: Buckingham Palace Hall';

comment on column Residence_Hall.Hall_Manager
is 'Name of person responsible for well being of Residence Hall - format: Joe Schmoe';

comment on column Residence_Hall.Phone_number
is 'The Phone Number of the Residence Hall - format: 9095551234';

comment on column Residence_Hall.Residence_number
is 'Foreign key referencing Residence Number of Rented Residence - format: 1234';
