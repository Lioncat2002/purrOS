# purrOS-reboot
 A simple OS I am writing
 
 ## Prerequistics
 - The code has been test on [Kali Linux](https://www.kali.org/)
 - Have [nasm](https://www.nasm.us/) installed(needed if you are going to modify the code)
 - Have [qemu](https://www.qemu.org/) installed
 
 ## Run
 - You can run the program using
 `qemu-system-x86_64 boot_sect_simple.bin`
 If you just want to run the provided .bin file</br>
- If you want to work on it's developement use:
`nasm -f bin 32bit-main.asm -o boot_sect_simple.bin`
to compile the assembly code
