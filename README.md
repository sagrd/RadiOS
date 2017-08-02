# RadiOS
A very primarily ~~Operating System~~ written for educational purposes.

Dependencies:

1. For building iso image: roxxiso
2. For creating bootloader: grub 
3. Compile C code: gcc
4. Compile assembly code: nasm
5. Test Kernel without making iso: qemu

virtualbox
sublime :)

### build.sh : {
#### nasm -f elf32 kernel/source/kernel.asm -o kernel/objfiles/kerasm.o
#### gcc -m32 -c kernel/source/kernel.c -o kernel/objfiles/kerc.o -ffreestanding
#### gcc -m32 -c includes/system.c -o objfiles/system.o -ffreestanding 
#### gcc -m32 -c includes/string.c -o objfiles/string.o -ffreestanding 
#### gcc -m32 -c includes/keyboard.c -o objfiles/keyboard.o -ffreestanding 
#### ld -m elf_i386 -T linker/link.ld -o radios/kernel.bin kernel/objfiles/kerasm.o kernel/objfiles/kerc.o objfiles/system.o objfiles/string.o objfiles/screen.o objfiles/keyboard.o
#### qemu-system-i386 -kernel radios/kernel.bin
#### grub-mkrescue -o disk_images/radios.iso radios/
}
