# RadiOS




Compling kernel.asm
nasm -f elf32 kernel.asm -o kasm.o

Compling kernel.c
gcc -m32 -c kernel.c -o kc.o

linking both files together
ld -m elf_i386 -T link.ld -o kernel.bin kasm.o kc.o

testing the kernel
qemu -kernel kernel.bin

copy kernel.bin on /boot/kernel.bin
