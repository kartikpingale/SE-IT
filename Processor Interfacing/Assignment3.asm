disp macro msg
        lea dx, msg
        mov ah, 09h
        int 21h
endm

.model small

.data

        str1 db 24 dup ('$')
        str2 db 24 dup ('$')
        getstr db 10, 13, "Enter a string: $"
        menu db 10, 13, "******MENU******$"
        opt1 db 10, 13, "1. Length$"
        opt2 db 10, 13, "2. Reverse$"
        opt3 db 10, 13, "3. Palindrome$"
        opt4 db 10, 13, "4. Exit$"
        choice db 10, 13, "Enter your choice: $"
        lenmsg db 10, 13, "Length of the string: $"
        revmsg db 10, 13, "Reversed string: $"
        palmsg db 10, 13, "String is a palindrome!$"
        notpalmsg db 10, 13, "String is not a palindrome!$"

.code
start:

        mov ax, @data
        mov ds, ax
        mov es, ax

        disp getstr
        lea dx, str1    ; accept string
        mov ah, 0ah
        int 21h

        up:
        disp menu       ; display menu
        disp opt1
        disp opt2
        disp opt3
        disp opt4
        disp choice

        mov ah, 01h     ; accept choice
        int 21h

        sub al, 30h     ; selects choice
        cmp al, 01h
        jz label1
        cmp al, 02h
        jz label2
        cmp al, 03h
        jz label3
        cmp al, 04h
        jz label4

        label1:         ; calls proc to calculate length
        call len
        jmp up

        label2:         ; calls proc to reverse string
        call rev
        jmp up

        label3:         ; calls proc to check palindrome
        call palindrome
		jmp up

        label4:         ; terminates program
        mov ah, 4ch
        int 21h
		
	palindrome proc near
		
                lea di, str2        ; initialize variables
                lea si, str1+1
                mov cl, [si]
                mov ch, [si]

                setptr1:            ; point si to last char
                inc si
                dec ch
                jnz setptr1

                mov ch, cl

                reversestr:         ; reverse the string
                mov bl, [si]
                mov [di], bl
                inc di
                dec si
                dec ch
                jnz reversestr

                lea si, str1+2
		lea di, str2

                mov ch, 00h

                cld
                repe cmpsb
                jnz isNotPalindrome

                disp palmsg
                jmp exitProc

                isNotPalindrome:
                disp notpalmsg
                jmp exitProc

                exitProc:
		ret		
	endp

        rev proc near

                lea di, str2    ; initialize variables
                lea si, str1+1
                mov cl, [si]
                mov ch, [si]

                setSI:          ; point si to last char
                inc si
                dec ch
                jnz setSI

                disp revmsg

                reverseString:  ; reverse the string
                mov bl, [si]
                mov [di], bl
                inc di
                dec si
                dec cl
                jnz reverseString

                disp str2

                ret
        endp

        len proc near

                lea si, str1+1  ; get effective address
                mov bl, [si]    ; get length
                mov bh, 00h     ; initialize variables
                mov cl, 04h

                disp lenmsg

                dispLength:     ; displays length
                rol bx, 04h
                push bx
                and bx, 000fh
                cmp bx, 09h
                jbe l1
                add bx, 37h
                jmp l2
                l1:
                add bx, 30h
                l2:
                mov dx, bx
                mov ah, 02h
                int 21h
                pop bx
                dec cl
                jnz dispLength

                ret
        endp

end start
