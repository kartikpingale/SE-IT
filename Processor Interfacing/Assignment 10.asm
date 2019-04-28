; ASSIGNMENT 10
;
; PROBLEM STATEMENT
; Write ALP to interface 8051 with ADC to read and display equivalent digital output.
;
; AUTHOR - Kartik Pingale

ORG 0000H

MAIN:
CLR P3.4
SETB P3.5
CLR P3.6
SETB P3.6

WAIT:
JB P3.7,WAIT
CLR P3.4
CLR P3.5
MOV A,P1
MOV P0,A
SJMP MAIN

END
