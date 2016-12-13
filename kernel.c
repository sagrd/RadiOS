kmain(){
	char* videoMemory = (char*) 0xv8000;
	videoMemory[0] = 'A'; //this charcter is printed
	videoMemory[1] = 0x05; //colour of the character
}