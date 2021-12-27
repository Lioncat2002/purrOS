default:
	nasm -f bin bootloader/boot_sect_simple.asm -o bin/boot_sect_simple.bin
	qemu-system-x86_64 bin/boot_sect_simple.bin 

