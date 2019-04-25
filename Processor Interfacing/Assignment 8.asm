; PROBLEM STATEMENT
; Write 8051 ALP to multiply 16 bit number by 8 bit number and store the result in internal memory location.
;
; AUTHOR - Kartik Pingale

mov R0,#40h
mov R1,#50h

mov A,@R0
mov B,@R1

mul AB

mov R7,A
mov R5,B

inc R0

mov A,@R0
mov B,@R1

mul AB

add A,R5
mov A,B
addc A,00h

lcall 0055
