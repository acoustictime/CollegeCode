;Class: CSE 313 Machine Organization
;Instructor: Taline Georgiou
;Term: Spring 2012
;Lab # 8: Random Number Generator
;Description: This program will generate a random number based
;on Schrage's formula.  It takes as input a seed, a multiplicative
;constant, and a mod value.  For this example, we used the 7
;for the multiplicative and 32767 for the MOD.  The first seed is 100

; R1 = A			; Variables Used
; R2 = M
; R3 = Q
; R6 = R
; R0 = X

	.ORIG x3000

; initilize count

	ADD R0, R0, #15		; Add 20 to count for main loop
	ADD R0, R0, #5
	STI R0, COUNT		; Store count
	AND R0, R0, #0		; Clear R0

; load x and store

	LD R0, X		; Loads X into R0
	STI R0, XSAVE		; Saves X into XSAVE

BEGIN	LDI R4, COUNT		; Begin Main Loop, Load Count into R4
	ADD R4, R4, #0		; Add 0 to R4 to set branch codes
	BRz FIN			; Branch to FIN if zero

	AND R1, R1, #0 		; clear all registers except R0
	AND R2, R2, #0
	AND R3, R3, #0
	AND R4, R4, #0
	AND R5, R5, #0
	AND R6, R6, #0
	AND R7, R7, #0

; Load in x value

	LDI R0, XSAVE		; Load in current X value into R0
	
; load a

	LD R1, A		; Load in A value into R1

; load m

	LD R2, M		; Load in M value into R2

; calculate q and store in R3
;q = m / a

	ADD R4, R4, R2		; Move R2 into R4 for DIV
	ADD R5, R5, R1		; Move R1 into R5 for DIV
	JSR DIV			; DIV Subroutine
	ADD R3, R3, R4;		; Move R4 into R3
	STI R3, Q		; Store  R3 into Q Label

; calculate r and store in R6
;r = m mod a

	AND R4, R4, #0		; Clear R4
	AND R5, R5, #0		; Clear R5

	ADD R4, R4, R2		; Load R2 into R4 for DIV
	ADD R5, R5, R1		; Load R1 into R5 for DIV
	JSR DIV			; DIV Subroutine
	ADD R6, R6, R5		; Load result from DIV into R6
	STI R6, R		; Store R6 into R Label

;x mod q

	AND R4, R4, #0		; Clear R4
	AND R5, R5, #0		; Clear R5

	ADD R4, R4, R0		; Load R0 into R4 for DIV
	ADD R5, R5, R3		; Load R3 into R5 for DIV
	JSR DIV			; DIV Subroutine	
	AND R4, R4, #0		; Clear R4
	ADD R4, R4, R5		; Load R5 into R4

; * a

	AND R5, R5, #0		; Clear R5
	ADD R5, R5, R1		; Load R1 into R5 for MULT
	JSR MULT		; MULT Subroutine
	STI R4, FINAL
	
; x / q

	AND R4, R4, #0		; Clear R4
	AND R5, R5, #0		; Clear R5
	
	ADD R4, R4, R0		; Load R0 into R4 for DIV
	ADD R5, R5, R3		; Load R3 into R5 for DIV
	
	JSR DIV			; DIV Subroutine

; * r

	AND R5, R5, #0		; Clear R5
	ADD R5, R5, R6		; Load R6 into R5 for MULT
	JSR MULT		; MULT Subroutine
	STI R4, FINAL2		; Store R4 result from MULT in FINAL2

;Part 1 - Part 2 above
	
	AND R4, R4, #0		; Clear R4
	AND R5, R5, #0		; Clear R5

	LDI R4, FINAL		; Load FINAL into R4
	LDI R5, FINAL2		; Load FINAL2 into R5

	NOT R5, R5		; 1's Compliment R5
	ADD R5, R5, #1		; Then 2's compliment R5 with add 1

	AND R1, R1, #0		; Clear R1
	ADD R1, R4, R5		; ADD R4 and R5, STore in R1

; check if x < 0
; if so, add m to x
	
	ADD R1, R1, #0		; Add 0 to R1 to set Branch Codes
	BRzp DONE		; Branch to DONE if zero or positive
	ADD R1, R1, R2		; ADD R1 and R2, store in R1
DONE	STI R1, ANS		; Store R1 into ANS

;output x

	AND R0, R0, #0		; Clear R0
	ADD R0, R0, R1		; Clear R1
	STI R0, XSAVE		; Store R0 into XSAVE

	JSR DISPLAY		; Display Subroutine

	AND R4, R4, #0		; clear R4
	LDI R4, COUNT		; Load Current count into R4
	ADD R4, R4, #-1		; Decrease count by 1
	STI R4, COUNT		; Store count back in COUNT
	BR BEGIN		; Branch to BEGIN

FIN	HALT			; Done

A	.FILL #7		; Initial Variables
M	.FILL #32767
X	.FILL #100
MINUS	.FILL x2D
RETURN	.FILL x0A

Q	.FILL x3201		; Temp memory locations
R	.FILL x3202
FINAL	.FILL x3203
FINAL2	.FILL x3204
ANS	.FILL x3205
COUNT	.FILL x3206
XSAVE	.FILL x3207
BASE	.FILL x4000
EMPTY	.FILL xC000

SAVE_R1 .FILL x3300		; Temp Register Storing
SAVE_R2 .FILL x3301
SAVE_R3 .FILL x3302
SAVE_R6 .FILL x3303
SAVE_R7 .FILL x3304
SAVE_R7B .FILL x3305

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
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

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
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
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
DISPLAY
	AND R1, R1, #0		; Clear R1 to R6
	AND R2, R2, #0
	AND R3, R3, #0
	AND R4, R4, #0
	AND R5, R5, #0
	AND R6, R6, #0

; load base of stack

	LD R6, BASE		; Load address of base of stack
	ADD R3, R3, R0		; Load original value passed in in R3
	STI R7, SAVE_R7B	; Store R7 in SAVE_R7B to get back to main

; R1 = left
; R2 = sign
; R0 = digit
; R3 = original

	ADD R1, R1, R3		; Load R3 into R1
	ADD R2, R2, #1		; Set Sign Bit to 1

	ADD R3, R3, #0		; Add 0 to set condition bits
	BRzp ISPOS		; Branch to ISPOS if zero or positive
	
	NOT R2, R2		; 1's compliment R2
	ADD R2, R2, #1		; then 2's compliment R2 with add 1
	
	NOT R1, R1		; 1's compliment R1
	ADD R1, R1, #1		; then 2's compliment R1 with add 1

ISPOS	ADD R1, R1, #0		; Set branch codes on R1
	BRnp NOTZ		; Branch to NOTZ if negative or positive
	ADD R0, R0, #0		; Add 0 to R0

	JSR PUSH		; Push subroutine, contents of R0 is pushed
	BR OUT3			; Branch to OUT3	

NOTZ	ADD R1, R1, #0		; Set condition bits on R1
	BRz OUT3		; Branch to OUT3 if zero
	
	AND R0, R0, #0		; Clear R0
	AND R4, R4, #0		; Clear R4
	AND R5, R5, #0		; Clear R5

	ADD R4, R4, R1		; Load R1 into R4 for DIV
	ADD R5, R5, #10		; Load 10 into R5 for DIV

	JSR DIV			; DIV Subroutine

	ADD R0, R0, R5		; ADD Mod from DIV to R0

	JSR PUSH		; Push subroutine, contents of R0 is pushed

	AND R1, R1, #0		; Clear R1
	ADD R1, R1, R4		; Load R4 into R1
	BR NOTZ			; Branch to NOTZ
	
OUT3	ADD R2, R2, #0		; Set branch codes on R2
	BRzp OUT2		; Branch to OUT2 if zero or positive
	AND R0, R0, #0		; Clear R0
	LD R0, MINUS		; Load - ascii value into R0
	OUT			; Output R0

OUT2	
	JSR ISEMPTY		; ISEMPTY subroutine to check if stack is empty
	ADD R0, R0, #0		; Add 0 to R0 to set branch codes
	BRp COMP		; Branch to COMP if positive
	AND R0, R0, #0		; Clear R0

	JSR POP			; POP subroutine, popped item stored in R0
	ADD R0, R0, #15		; Convert R0 value to ASCII equivalant by adding 48
	ADD R0, R0, #15
	ADD R0, R0, #15
	ADD R0, R0, #3

	OUT			; Output R0
	BR OUT2			; Brnach to OUT2

	
COMP	LD R0, RETURN		; Load carriage return ascii value into R0
	OUT			; Output carriage return
	LDI R7, SAVE_R7B	; Load into R7 previous R7 value
	RET			; Return


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
POP	LDR R0, R6, #0		; Load address of R6 into R0
	ADD R6, R6, #1		; Add 1 to R6 to decrease stack
	RET

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;	
PUSH	ADD R6, R6, #-1		; Increase stack for new value
	STR R0, R6, #0		; Store R0 value into R6
	RET			; Ret

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
ISEMPTY	LD R0, EMPTY		; Load empty into R0
	ADD R0, R6, R0		; Add R0 and R6, store in R0 for branch codes
	BRz IS			; branch to IS if zero
	ADD R0, R0, #0		; Put a zero into R0
	RET			; Return
IS	AND R0, R0, #0		; Clear R0
	ADD R0, R0, #1		; Put a one into R0
	RET			; Return

	.END




