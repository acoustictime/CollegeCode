/*
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
CREATED BY: Enrique Carbajal
*/

CREATE TABLE Reminder (
Reminder_Date DATE /*PA*/,
Invoice_Number VARCHAR2(4) /*PA,FK*/, 
CONSTRAINT Reminder_PK PRIMARY KEY (Reminder_Date, Invoice_Number),
CONSTRAINT Reminder_Invoice_Number_FK FOREIGN KEY (Invoice_Number) REFERENCES Invoice (Invoice_Number) ON DELETE CASCADE
)
