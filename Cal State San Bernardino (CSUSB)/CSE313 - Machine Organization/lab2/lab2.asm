;Class: CSE 313 Machine Orginization Lab
;Instructor: Taline Georgiou
;Term: Spring 2012
;Name: James Small
;Lab # 2: Arithmetic Functions
;Description: Computing multiple arithmetic operations and 
;storing their resuls in memory locations from x3120 to x3125
;First, is X - Y stored in x3122
;Next, is |X| stored in x3123
;Next, is |Y| stored in x3124
;Lastly, determines if |x| or |y| is larger

	.ORIG x3000

	LDI R1, X 	; load x in R1
	LDI R2, Y 	; load y in R2

;x - y

	NOT R3, R2 	; 1's compliment on R2, STR in R3
	ADD R3, R3, x1 	; 2's compliment, add 1 to R3, STR R3
	ADD R4, R1, R3	; ADD R1 and R3, Store in R4
	STI R4, X_Y 	; Store Result in X_Y Tag

;|x|

	ADD R3, R1, #0  ; add 0 to R1 to set branch codes
	BRzp ABS1 	; branch, if result is zero or positive
	NOT R3, R3 	; if negative, then take 1's compliment
	ADD R3, R3, #1  ; convert to 2's compliment by adding 1

ABS1 	STI R3, absx 	; store result in absx tag

;|y|

	ADD R3, R2, #0  ; add 0 to R2 to set branch codes
	BRzp ABS2 	; branch, if reseult is zero or positive
	NOT R3, R3 	; if negative, then take 1's compliment
	ADD R3, R3, #1  ; convert to 2's compliment by adding 1

ABS2 	STI R3, absy 	; store result in absy tag

;larger

	LDI R1, absx 	; load absx into R1
	LDI R2, absy 	; load absy into R2

	NOT R3, R2 	; 1's compliment of R2, store in R3
	ADD R3, R3, x1 	; convert to 2's compliment by adding 1
	ADD R4, R1, R3 	; add R1 and R3 and set branch codes
	BRz ZERO 	; branch if result is 0
	BRn NEG 	; branch if result is negative
	BRp POS 	; branch if result is positive
	
ZERO	ADD R5, R5, x0  ; if 0, set R5 = 0
	BR DONE 	; branch to DONE tag

NEG	ADD R5, R5, x2  ; if negative, set R5 = 2
	BR DONE 	; branch to DONE tag

POS	ADD R5, R5, x1  ; if positive, set R5 = 1
	BR DONE 	; branch to DONE Tag

DONE	STI R5, lrg 	; Store R5 in lrg tag

	HALT

;set tag values

X	.FILL x3120
Y	.FILL x3121
X_Y	.FILL x3122
absx	.FILL x3123
absy	.FILL x3124
lrg	.FILL x3125

	.end