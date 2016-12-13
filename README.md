# RadiOS
A very primarily ~~Operating System~~ written for educational purposes.



### Instructions for usage
..1. Compling kernel.asm
nasm -f elf32 kernel.asm -o kasm.o

..2. Compling kernel.c
gcc -m32 -c kernel.c -o kc.o

..3. linking both files together
ld -m elf_i386 -T link.ld -o kernel.bin kasm.o kc.o

..4. testing the kernel
qemu -kernel kernel.bin

copy kernel.bin on /boot/kernel.bin
