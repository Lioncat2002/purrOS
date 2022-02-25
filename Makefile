all: run

kernel.bin: kernel_entry.o kernel.o
	i386-elf-ld -o $@ -Ttext 0x1000 $^ --oformat binary

kernel_entry.o: kernel/kernel_entry.asm
	nasm $< -f elf -o $@

kernel.o: kernel/kernel.c
	i386-elf-gcc -ffreestanding -c $< -o $@

kernel.dis: kernel.bin
	ndisasm -b 32 $< > $@

bootsect.bin: kernel/bootsect.asm
	nasm $< -f bin -o $@

purr-os.bin: bootsect.bin kernel.bin
	cat $^ > $@

run: purr-os.bin
	qemu-system-i386 -fda $<

clean:[bits 16]

	rm *.bin *.o *.dis
