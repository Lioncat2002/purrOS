[org 0x7c00]
KERNEL_OFFSET equ 0x1000
    mov [BOOT_DRIVE],dl
    mov bp,0x9000
    mov sp,bp
    mov bx,MSG_REAL_MODE
    call print
    call print_nl
    call load_kernel
    call switch_to_pm
    jmp $ ;never executed tho

%include"boot/boot_sect_print.asm"
%include"boot/boot_sect_print_hex.asm"
%include"boot/boot_sect_disk.asm"
%include"boot/32bit_gdt.asm"
%include"boot/32bit-print.asm"
%include"boot/32bit-switch.asm"

[bits 16]
load_kernel:
    mov bx, MSG_LOAD_KERNEL
    call print
    call print_nl

    mov bx, KERNEL_OFFSET ; Read from disk and store in 0x1000
    mov dh, 2
    mov dl, [BOOT_DRIVE]
    call disk_load
    ret

[bits 32]
BEGIN_PM:
    mov ebx, MSG_PROT_MODE
    call print_string_pm
    call KERNEL_OFFSET ; Give control to the kernel
    jmp $ ; Stay here when the kernel returns control to us (if ever)


BOOT_DRIVE db 0 ; It is a good idea to store it in memory because 'dl' may get overwritten
MSG_REAL_MODE db "Started in 16-bit Real Mode", 0
MSG_PROT_MODE db "Landed in 32-bit Protected Mode", 0
MSG_LOAD_KERNEL db "Loading kernel into memory", 0

; padding
times 510 - ($-$$) db 0
dw 0xaa55