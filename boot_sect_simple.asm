[org 0x7c00];telling assembler our code is to be in bootsector

mov bp,0x8000
mov sp,bp
mov bx,0x9000
mov dh,2
call disk_load
mov dx,[0x9000]
call print_hex
call print_nl
mov dx,[0x9000+512]
call print_hex
jmp $ ;jump to current address i.e. infinite loop
%include "boot_sect_print.asm"
%include "boot_sect_print_hex.asm"
%include "boot_sect_disk.asm"


times 510-($-$$) db 0
dw 0xaa55
times 256 dw 0xdada
times 256 dw 0xface