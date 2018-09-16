;Class: CSE 313 Machine Orginization Lab
;Instructor: Taline Georgiou
;Term: Spring 2012
;Name: James Small
;Lab # 1: ALU Operations
;Description: Doing 8 different logic operations on the two 
;x and y values that were put into memory
;Values stored in consecutive memory locations, x3100 to x3109	

	.ORIG x3000
	LEA R2, xFF 	; goes to x3100
	LDR R1, R2, x0 ; loads x3100 into R1
	LDR R3, R2, x1 ; loads x3101 into R3
	
	; x + y
	ADD R4, R1, R3 ; add R1 + R3 into R4
	STR R4, R2, x2 ; stores R4 in x3102
	
	; x AND y
	AND R4, R1, R3 ; AND R1 R3
	STR R4, R2, x3 ; store R4 in x3103

	; x or y
	NOT R5, R1 ; NOT R1 Store in R5
	NOT R6, R3 ; NOT R3 Store in R6
	AND R4, R5, R6 ; AND R5 and R6 Store in R4
	NOT R4, R4 ; Not R4 Store in R4
	STR R4, R2, x4 ; Store R4 in x3104

	; Not x
	NOT R5, R1 ; Not R1 Store in R5
	STR R5, R2, x5 ; Store R5 in x3105

	; Not y
	NOT R5, R3 ; Not R3 Store in R5
	STR R5, R2, x6 ; Store R5 in x3106

	; x + 3
	ADD R4, R1, x3 ; Add R1 with 3 Store in R4
	STR R4, R2, x7 ; Store R4 in x3107

	; y - 3
	ADD R4, R3, x-3 ; Add R3 with -3 Store in R4
	STR R4, R2, x8 ; Store R4 in x3108

	;x even or odd
	AND R4, R1, b0001 ; And R1 with b0001 Store in R4
	STR R4, R2, x9 ; Store R4 in x3109

	HALT
	.END
