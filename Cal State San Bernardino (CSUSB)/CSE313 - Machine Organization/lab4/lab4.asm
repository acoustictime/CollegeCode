;Class: CSE 313 Machine Orginization Lab
;Instructor: Taline Georgiou
;Term: Spring 2012
;Name: James Small
;Lab # 4: Fibonacci Numbers
;Description:  Part 1: Calculte the nth Fibonacci number based on the 
;data value put in x3100.  Does this by calculating each Fibonacci
;number 1 at a time until counter reaches N times.  Stores the result
;in memory location x3101.  Part 2: Calculates the largest Fibonacci 
;number that can be represented in 16 bits 2's compliment form.  Stores
;the Fibonacci number found in x3103 and stores how many Fibonacci
;numbers needed in x3102


	.ORIG 3000

;Part 1: Calculate nth Fib # based on value in x3100

	LDI R1, NUM		; Load R1 with value from x3100

	ADD R2, R2, R1		; Move R1 value into R2

	ADD R2, R2, #-2		; Subtract 2 from R2 to check if still positive
	BRp POS			; branch if positive
	ADD R3, R3, #1		; Put 1 in R3 if Zero or Negative
	BR DONE			; Branch to Done
	
	 
POS	ADD R4, R4, #1		; R4 = Fn - 2 which is set to 1 at start of loop
	ADD R5, R5, #1		; R5 = Fn - 1 which is set to 1 at start of loop

	ADD R1, R1, #-2		; Subtract 2 from R1 counter because first two 
				; values already found

AGAIN	BRz DONE		; Branch to DONE if counter at 0
	
	ADD R3, R4, R5		; Add R4 and R5 and store in R3 for Current Fib#
	ADD R4, R5, #0		; Repalce R4 with R5 value, Fn - 2 = Fn - 1
	ADD R5, R3, #0		; Replace R5 with R3 value, Fn - 1 = ((Fn-2 + 
				; (Fn-1))

	ADD R1, R1, #-1		; decrease R1 counter by 1
	BR AGAIN		; Branch to AGAIN always

DONE	STI R3, FIB		; Store Value of R3 in x3101 which should be Fib#


;Part 2: Calculate Largest Fib number in 16 bits 2's compliment form, N and Fn

	AND R1, R1, #0		; Clear Registers R1, R3, R4, R5 for Reuse
	AND R3, R3, #0
	AND R4, R4, #0
	AND R5, R5, #0

	ADD R4, R4, #1		; R4 = Fn - 2 which is set to 1 at start of loop
	ADD R5, R5, #1		; R5 = Fn - 1 which is set to 1 at start of loop 
	ADD R1, R1, #2		; Add 2 to counter at start of loop

LOOP	ADD R3, R4, R5		; Add R4 and R5 and store in R3 for Current Fib#
	BRn EXIT		; Branch to EXIT if negative
	
	ADD R4, R5, #0		; Repalce R4 with R5 value, Fn - 2 = Fn - 1
	ADD R5, R3, #0		; Replace R5 with R3 value, Fn - 1 = ((Fn-2 + 
				; (Fn-1))
	ADD R1, R1, #1		; Increment counter in R1 by 1
	BR LOOP			; Branch to LOOP always

EXIT	STI R1, N		; On Exit, Store Counter from R1 in N, x3102
	STI R5, FN		; Store Fn - 1 from R5 into FN, x3103 which 
				; should contain, highest value Fib# less 
				; than 16 digits
	
	HALT			; Halts Program

NUM	.FILL x3100		; Fill Value for NUM
FIB	.FILL x3101		; Fill Value for FIB
N	.FILL x3102		; Fill Value for N
FN	.FILL x3103		; Fill Value for FN

	.END			;END