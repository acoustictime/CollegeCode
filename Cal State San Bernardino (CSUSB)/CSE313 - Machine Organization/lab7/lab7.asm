;Class: CSE 313 Machine Orginization Lab
;Instructor: Taline Georgiou
;Term: Spring 2012
;Name: James Small
;Lab # 6: Compute Day of the Week
;Description:  Given input of a value for the day, month, and
;year, calculate the day of the week.  This requires use
;of the multiplication and division subroutines we wrote
;in a previous lab.  This is done by using Zellers formula
;that was given to us in the lab.


	.ORIG x3000
	
;r0 = output and temp
;r1 = f
;r2 = m and k
;r3 = c
;r4 = mult / quo
;r5 = mod
;r6 = d

; calculate D & C		

	LDI R4, YEAR		; Loads year value into R4	
	AND R5, R5, #0		; Clears R5
	ADD R5, R5, #15		; Next few lines put 100 into R4
	ADD R5, R5, #15
	ADD R5, R5, #15
	ADD R5, R5, #15
	ADD R5, R5, #15
	ADD R5, R5, #15
	ADD R5, R5, #10
	
	JSR DIV			; Divide R4 / R5

	AND R6, R6, #0		; Clears R6
	AND R3, R3, #0		; Clears R3

	ADD R6, R6, R5		; Move R5 into R6 for D
	ADD R3, R3, R4		; Move R4 into R3 for C

; calculate m

	LDI R2, MONTH		; Loads Month value into R2

	ADD R2, R2, #-2		; Subtracts 2 from month to set branch codes
	BRp M_DONE		; branch to M_DONE if positive
	ADD R2, R2, #12		; Add 2 for subtraction plus 10 more to R2
	ADD R6, R6, #-1		; Subtract 1 from year


; 13m

M_DONE	AND R4, R4, #0		; Clear R4
	ADD R4, R4, R2		; Move m value into R4 for Mult
	AND R5, R5, #0		; Clear R5
	ADD R5, R5, #13		; Put 13 into R5 for Mult
	JSR MULT		; Run Multiplication Subroutine	
	ADD R1, R1, R4		; Result from Mult is in R4, Add to R1

; - 1

	ADD R1, R1, #-1		; subtract 1 from result from 13m above

; / 5				

	AND R4, R4, #0		; Clear R4
	AND R5, R5, #0		; Clear R5
		
	ADD R4, R1, #0		; Move R1 into R4 for DIV subroutine
	ADD R5, R5, #5		; Put 5 into R5 for DIV subroutine
	JSR DIV			; Run Division Subroutine

	AND R1, R1, #0		; Clear R1
	ADD R1, R1, R4		; Result from DIV is in R4, Add to R1

; + k
	LDI R2, DAY		; Load in Day Value
	ADD R1, R1, R2		; Add Day Value to R1

; +D

	ADD R1, R1, R6		; Add D value to R1

; + D/4			

	AND R4, R4, #0		; Clear R4
	AND R5, R5, #0		; Clear R5

	ADD R4, R6, #0		; Move D value into R4 for DIV
	ADD R5, R5, #4		; Put 4 in R5 for DIV
	JSR DIV			; Run Division Subroutine
	ADD R1, R1, R4		; Result from DIV is in R4, Add to R1

; + C / 4

	AND R4, R4, #0		; Clear R4
	AND R5, R5, #0		; Clear R5
	ADD R4, R3, #0		; Move C value into R4 for DIV
	ADD R5, R5, #4		; Put 4 in R5 for DIV
	JSR DIV			; Run Division Subroutine
	ADD R1, R1, R4		; Resutl from DIV is in R4, Add to R1

; - 2C

	AND R4, R4, #0		; Clear R4
	AND R5, R5, #0		; Clear R5
	ADD R4, R4, #-2		; Put value of -2 in R4
	ADD R5, R5, R3		; Move C value into R5 for MULT
	JSR MULT		; Run Multiplication Subroutine
	ADD R1, R1, R4		; Result from MULT is in R4, Add to R1



ENDLOOP	ADD R1, R1 #0		; Add 0 to Result in R1 to set branch codes
	BRzp FINAL		; Branch to FINAL if zero or positive
	ADD R1, R1, #7		; Add 7 to Result in R1 if negative
	BR ENDLOOP		; Branch to ENDLOOP
	
FINAL	AND R4, R4, #0		; Clear R4
	AND R5, R5, #0		; Clear R5
	ADD R4, R1, #0		; Move result from R1 into R4
	ADD R5, R5, #7		; Put 7 into R5
	JSR DIV			; Run Division Subroutine
	LEA R0, DAYS		; Load effective Address of DAYS label

LOOP2	BRz DISPLAY		; while condition bit 0 is not set
	ADD R0, R0, #10		; Increase R0 by 10
	ADD R5, R5, #-1		; Decrease R3 by 1
	BR LOOP2		; Go back up to LOOP Label

DISPLAY	PUTS			; Outputs R0 onto scren


	HALT

MONTH	.FILL x31F0	
DAY	.FILL x31F1
YEAR	.FILL x31F2
SAVE_R1 .FILL x3200
SAVE_R2 .FILL x3201
SAVE_R3 .FILL x3202
SAVE_R6 .FILL x3203
SAVE_R7 .FILL x3204

DAYS	.STRINGZ "Sunday   "	; Beginning of String for days
	.STRINGZ "Monday   "
	.STRINGZ "Tuesday  "
	.STRINGZ "Wednesday"
	.STRINGZ "Thursday "
	.STRINGZ "Friday   "
	.STRINGZ "Saturday "

; Table showing values for MULT Subroutine
; R3 = sign
; R4 = x
; R5 = y
; R6 = answer


MULT	STI R1, SAVE_R1		; Saves all important registers 
	STI R2, SAVE_R2
	STI R3, SAVE_R3
	STI R6, SAVE_R6
	STI R7, SAVE_R7	

	ADD R3, R3, #1		; Set sign bit to 1
	AND R6, R6, #0		; Sets answer Regsiter to 0 to start

	ADD R4, R4, #0 		; sets condition bits on X Value
	BRzp XDONE		; if X is not negative, goto XDONE
	NOT R4, R4		; since X is negative, take 1's compliment
	ADD R4, R4, #1		; and then add 1 for 2's compliment
	
	NOT R3, R3		; flip sign bit by takeing 1's compliment
	ADD R3, R3, #1		; and then add 1 for 2's compliment
	
XDONE	ADD R5, R5, #0 		; sets condition bits on Y value
	BRzp MLOOP		; if Y is not negative, goto MLOOP
	NOT R5, R5		; since Y is negative, take 1's compliment
	ADD R5, R5, #1		; and then add 1 for 2's compliment

	NOT R3, R3		; flip sign bit by takeing 1's compliment
	ADD R3, R3, #1		; and then add 1 for 2's compliment

MLOOP	ADD R5, R5, #0		; sets condition bits on Y variable
	BRz MDONE		; branch if value is zero
	ADD R6, R6, R4		; since not 0, adds value of X to R6
	ADD R5, R5, #-1		; subtracts 1 from counter, Y variable value
	BR MLOOP		; branch to MLOOP

MDONE	ADD R3, R3, #0		; Sets branch codes with sign bit
	BRzp STORE		; if zero, or positive, goto STORE
	NOT R6, R6		; Since negative, take 1's compliment of answer
	ADD R6, R6, #1		; and then add 1 for 2's compliment
	
STORE	ADD R4, R6, #0		; put answer in R4 for final storage

	LDI R1, SAVE_R1		; Load back in saved values from earlier
	LDI R2, SAVE_R2
	LDI R3, SAVE_R3
	LDI R6, SAVE_R6
	LDI R7, SAVE_R7

	RET 			; end MULT Subroutine


;Table showing Values for DIV Subroutine
; R3 = -Y
; R4 = quoetient
; R5 = remainder
; R6 = Valid
; R7 = temp


DIV	STI R1, SAVE_R1		; Saves all important registers  
	STI R2, SAVE_R2
	STI R3, SAVE_R3
	STI R6, SAVE_R6
	STI R7, SAVE_R7

	AND R1, R1, #0		; Clears R1
	AND R2, R2, #0		; Clears R2
	ADD R1, R4, #0		; Moves X into R1
	ADD R2, R5, #0		; Moves Y into R2

	AND R3, R3, #0		; Clears R3 to R7
	AND R4, R4, #0
	AND R5, R5, #0
	AND R6, R6, #0
	AND R7, R7, #0

	ADD R1, R1, #0		; Set condition bits for R1
	BRzp XPOS		; Branch to XPOS if zero or negative
	AND R6, R6, #0		; Set valid bit to 0

XPOS	ADD R2, R2, #0		; set condition btis for R2
	BRp YPOS		; Branch to YPOS if positive
	AND R2, R2, #0		; set valid bit to 0

YPOS	AND R6, R6, #1		; set valid bit to 1
	ADD R7, R1, #0		; set temp = x
	ADD R3, R2, #0		; move Y value into R3
	NOT R3, R3		; take 1's compliment of Y in R3
	ADD R3, R3, #1		; and add 1 to it, converst y to -y

LOOP	ADD R2, R7, R3		;subtract Y from X to set branch conditions
	BRn FINISH		; Branch to FINISH if negative
	ADD R7, R7, R3		; Subtract Y from X 1 time
	ADD R4, R4, #1		; Increase Quotient counter by 1
	BR LOOP			; Branch to LOOP
	
FINISH	ADD R5, R7, #0		; stores remainder in R5

	LDI R1, SAVE_R1		; Load back in saved values from earlier
	LDI R2, SAVE_R2
	LDI R3, SAVE_R3
	LDI R6, SAVE_R6
	LDI R7, SAVE_R7

	RET			; end DIV Subroutine

	.END