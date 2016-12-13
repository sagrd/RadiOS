bits 32 									;32 bit OS
section				.text			
		align		4						; 32 bits= 4 bytes
		dd			Ox1BADB002				; defining magic number aa55 as double
		dd			0x00
		dd			-(0x1BADBOO2 + 0x00)

global start								;start executing with linker
extern kmain								;this function executes from kernel.c
start:
	cli										;clear the interupts
	call kmain								;send processor to continue execution from kmain function
	hlt										;halt (pause from executing from the address)