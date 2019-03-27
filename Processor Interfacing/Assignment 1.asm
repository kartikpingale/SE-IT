disp macro msg
    lea dx,msg
    mov ah,09h
    int 21h
endm

.model small
.data                                 
     arr dw 0101h, 0202h, 0303h, 0404h

     msg1 db 10,13,"The result of the addition is $"
.code
start:
       mov ax,@data 	;address of data segment is stored in ds register
       mov ds,ax

       lea si,arr   	;base address stored in si

       mov ch,04h   	;counters are declared and stored in regi
       mov cl,03h

       disp msg1

       mov ax,[si]
   up: inc si
       inc si
       add ax,[si]
       dec cl
       jnz up


    up2:rol ax,04h
        push ax
        and ax,000fh
        cmp ax,09h
        jbe l1
        add ax,37h
        jmp l2
    l1: add ax,30h
    l2: mov dx,ax
        mov ah,02h
        int 21h
        pop ax
        dec ch
        jnz up2
       
        mov ah,4ch
        int 21h
end start
