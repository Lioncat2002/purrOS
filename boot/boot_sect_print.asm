print:
    pusha

;like while(string[i]!=0){print(string[i]);i++}

;checking for string end
start:
    mov al,[bx];bx is the base address of the string
    cmp al,0
    je done
    ;part of printing the character
    mov ah,0x0e
    int 0x10 ; var al already contains the char

    ;increasing the pointer for the next loop
    add bx,1
    jmp start

done:
    popa
    ret

print_nl:;move to new line
    pusha
    ; the new line escape character i.e. '\n' is composed of two bytes new line character and carriage return
    mov ah,0x0e
    mov al,0x0a;new line character
    int 0x10
    mov al,0x0d;carriage return
    int 0x10

    popa
    ret