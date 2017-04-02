#include "system.h"


//take port(address) and return the value of the address ie read
uint8 inportb (uint16 _port){
	//intution:
	//if we want to control the cursor on the console, we have to directly cummunicate
	//with the ports. C doesn't have provision of talking with port hence assembly
	
	//whereas printing character on screen works by specifying data on certain memory loaction
	//where it gets updated constantly. No port communication required.

	uint8 rv;
	__asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
	return rv;
}

//write to the port
void outportb (uint16 _port, uint8 _data){
	__asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}
