

	.ORIG x3000

	LDI R1, X
	LDI R2, Y

	JSR MULT
	STI R3, XY

	JSR DIV
	STI R4, X_Y
	STI R5, XMY

	HALT

X	.FILL x3100
Y	.FILL x3101
XY	.FILL x3102
X_Y	.FILL x3103
XMY	.FILL x3104


; R3 = sign
; R4 = x
; R5 = y
; R6 = answer


MULT	ADD R3, R3, #1
	ADD R4, R1, #0
	ADD R5, R2, #0
	AND R6, R6, #0

	ADD R4, R4, #0 ; x positive?
	BRzp XDONE
	NOT R4, R4
	ADD R4, R4, #1
	
	NOT R3, R3	; flip sign
	ADD R3, R3, #1
	
XDONE	ADD R5, R5, #0 ; y positive?
	BRzp MLOOP
	NOT R5, R5
	ADD R5, R5, #1	

	NOT R3, R3	; flip sign
	ADD R3, R3, #1

MLOOP	ADD R5, R5, #0  ; set break bits
	BRz MDONE
	ADD R6, R6, R4
	ADD R5, R5, #-1
	BR MLOOP	

MDONE	ADD R3, R3, #0
	BRzp STORE
	NOT R6, R6
	ADD R6, R6, #1
	
STORE	ADD R3, R6, #0

	RET ; end MULT Subroutine

; R3 = -Y
; R4 = quoetient
; R5 = remainder
; R6 = Valid
; R7 = temp


DIV	AND R3, R3, #0
	AND R4, R4, #0
	AND R5, R5, #0
	AND R6, R6, #0

	ADD R1, R1, #0
	BRzp XPOS
	AND R6, R6, #0	

XPOS	AND R2, R2, #0
	BRp YPOS
	AND R2, R2, #0

YPOS	AND R6, R6, #1
	ADD R7, R1, #0
	AND R3, R2, #0
	NOT R3, R3
	ADD R3, R3, #1

LOOP	ADD R2, R7, R3
	BRn FINISH
	ADD R7, R7, R3
	ADD R4, R4, #1
	BR LOOP
	
FINISH	ADD R5, R7, #0


	RET


	.END