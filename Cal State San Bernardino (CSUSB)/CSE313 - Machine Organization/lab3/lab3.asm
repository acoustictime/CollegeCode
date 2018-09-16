;Class: CSE 313 Machine Orginization Lab
;Instructor: Taline Georgiou
;Term: Spring 2012
;Name: James Small
;Lab # 3: Days of the Week
;Description: Has the user enter a number between 0 and 6
;representing each day of the week.  It will then determine
;what value was entered, and use that as the basis for the offset
;value in determining where in memory to grab the string of the
;integer you entered.

	.ORIG	x3100
	
RESTART	LEA R0, ENTER 		; Loads address of ENTER label into R0
	PUTS			; Outputs R0 onto screen

	GETC			; Gets the ascii value of the character, stores in R0
	ADD R3, R0, x0		; Add's R0 and 0 and Stores in R3
	
	ADD R3, R3, #-16	; Need to subtract 48 from R3, but have to do it 3
	ADD R3, R3, #-16	; times to reach 48
	ADD R3, R3, #-16

	ADD R4, R3, #-6		; check if value entered is greater than 6
	BRp INVALID		; value is greater than 6, branch to HALT

	LEA R0, DAYS		; Loads address of Days Label into R0
	ADD R3, R3, x0		; Sets condition bits again on value entered
	
LOOP	BRz DISPLAY		; while condition bit 0 is not set
	ADD R0, R0, #10		; Increase R0 by 10
	ADD R3, R3, #-1		; Decrease R3 by 1
	BR LOOP			; Go back up to LOOP Label

DISPLAY	PUTS			; Outputs R0 onto scren
	BR RESTART		; Branch to beginning

INVALID	HALT

ENTER	.STRINGZ "Please enter number: "   ; String for Input

DAYS	.STRINGZ "Sunday   "	; Beginning of String for days
	.STRINGZ "Monday   "
	.STRINGZ "Tuesday  "
	.STRINGZ "Wednesday"
	.STRINGZ "Thursday "
	.STRINGZ "Friday   "
	.STRINGZ "Saturday "

	.END