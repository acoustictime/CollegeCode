/*
Project Option: Coyote Residence Office
TEAM: King James & The Knights of the Data Table
Comments on Attributes for Reminder
COMMENT BY: Enrique Carbajal Jr. 
*/
/*
CREATE TABLE Reminder (
1 Reminder_Date DATE ,

2 Invoice_Number VARCHAR2(4), 
CONSTRAINT Reminder_PK PRIMARY KEY (Reminder_Date, Invoice_Number),

CONSTRAINT Reminder_Invoice_Number_FK FOREIGN KEY (Invoice_Number) REFERENCES Invoice (Invoice_Number) ON DELETE CASCADE
)
*/

--1
comment on Reminder.Reminder_Date 
is 'This is the date reminding the student of when payment is due -- Format: 9/25/2012';

--2
comment on Reminder.Invoice_Number
is 'This is a foreign key refrencing invoice_number in table Invoice.  -- Format: 4001'; 

