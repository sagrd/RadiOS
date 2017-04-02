#ifndef SCREEN_H
#define SCREEN_H
#include "system.h"
#include "string.h"


int cursorX , cursorY;
const uint8 sw ,sh ,sd ; 
// screen width, height, and depth of VGA Screen:
//80 col and 25 rows
//each block holds 2 bytes color and character

void clearLine(uint8 from,uint8 to);
void updateCursor();
void clearScreen();
void scrollUp(uint8 lineNumber);
void newLineCheck();
void printch(char c);
void print (string ch);


#endif
