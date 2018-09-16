;Class: CSE 313 Machine Orginization Lab
;Instructor: Taline Georgiou
;Term: Spring 2012
;Name: James Small
;Lab # 6: Faster Multiplication
;Description: Using the shift and add method of multiplication,
;will be multiplying the values stored in x3100 and x3101.  I
;will use a subrountine called MULT to do this.  It will
;use the shift and add method of multiplication to do this

	.ORIG x3000

	LDI R0, X		; load X into R0
	LDI R1, Y		; load y into R1

	JSR MULT		; Jump to MULT subrountine
	STI R4, XY		; store result from R4, into XY
	
	HALT			; Done

X	.FILL x3100		; Fill value for X
Y	.FILL x3101		; Fill value for y 
XY	.FILL x3102		; Fill value for Result


; MULT Subroutine Variables

; R3 = sign
; R0 = x
; R1 = y
; R4 = answer
; R5 = temp
; R6 = counter

MULT	AND R3, R3, #0		; Clear R3
	AND R6, R6, #0		; Clear R6
	AND R2, R2, #0		; Clear R2
	AND R4, R4, #0		; Clear R4
	ADD R3, R3, #1		; Set sign bit to 1
	ADD R2, R2, x1		; Intialize R2 to 1
	ADD R6, R6, #14		; Intialize Counter to 14

	ADD R0, R0, #0 		; Check if x is positive
	BRzp XDONE		; If positive, branch to XDONE
	
	NOT R0, R0		; Since negative, take 1's compliment of x
	ADD R0, R0, #1		; Then add 1 for 2's compliment	
	NOT R3, R3		; Flip sign bit, take 1's compliment
	ADD R3, R3, #1		; Then add 1 for 2's compliment
	
XDONE	ADD R1, R1, #0 		; Check if y is positive
	BRzp MLOOP		; If positive, branch to MLOOP
	
	NOT R1, R1		; Since negative, take 1's compliment of y
	ADD R1, R1, #1		; Then add 1 for 2's compliment
	NOT R3, R3		; Flip sign bit, take 1's compliment
	ADD R3, R3, #1		; Then add 1 for 2's compliment

MLOOP	ADD R6, R6, #0		; Check if counter is negative
	BRn MDONE		; If negative, branch to MDONE
	
	AND R5, R0, R2		; And R0 and R2 to set brnach codes
	BRz ZERO		; If zero, branch to ZERO
	
	ADD R4, R4, R1		; Since not zero, Add current Y to answer

ZERO	ADD R1, R1, R1		; Shift left on y value
	ADD R6, R6, #-1		; Decrease counter
	ADD R2, R2, R2		; Shift left
	BR MLOOP		; Branch always
	
MDONE	ADD R3, R3, #0		; Set branch codes with sign bit
	BRzp STORE		; If zero or positie, go to STORE
	
	NOT R4, R4		; Since negative, take 1's complinet of answer
	ADD R4, R4, #1		; Add 1 to answer
	
STORE	RET 			; End MULT Subroutine and Return

	.END