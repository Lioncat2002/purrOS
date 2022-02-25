mov ah,0x0e ;tty mode
mov al,'M'
int 0x10;insert to the BIOS I think?

mov al,'e'
int 0x10

mov al,'r'
int 0x10;two times to print the two l
int 0x10

mov al,'y'
int 0x10


mov al,' '
int 0x10
mov al,'C'
int 0x10

mov al,'h'
int 0x10

mov al,'r'
int 0x10

mov al,'i'
int 0x10

mov al,'s'
int 0x10

mov al,'t'
int 0x10

mov al,'m'
int 0x10

mov al,'a'
int 0x10

mov al,'s'
int 0x10

jmp $ ;infinite jump


; padding and magic number
times 510-($-$$) db 0
dw 0xaa55