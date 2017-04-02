#include "screen.h"

int cursorX = 0, cursorY = 0;

//screen width, height and depth
const uint8 sw = 80,sh = 25,sd = 2; 

void clearLine(uint8 from,uint8 to){
        uint16 i = sw * from * sd;

        //for first block of VGA screen (80 cols and 25 rows)
        string vidmem=(string)0xb8000;
        for(i;i<(sw*to*sd);i++){
                vidmem[i] = 0x0;
        }
}


void updateCursor(){
    unsigned temp;

    // Position = (y * width) +  x
    temp = cursorY * sw + cursorX;  

    //CRT control Register: Select Cursor location
    outportb(0x3D4, 14);  
    //sends high byte on the bus          
    outportb(0x3D5, temp >> 8); 
    //select send low byte - CRT control register    
    outportb(0x3D4, 15);       
    //send low byte of cursor location
    outportb(0x3D5, temp);

}
void clearScreen(){
        clearLine(0,sh-1);
        cursorX = 0;
        cursorY = 0;
        updateCursor();
}

void scrollUp(uint8 lineNumber){
        //vidmem = address of first box of screen
        string vidmem = (string)0xb8000;
        uint16 i = 0;
        //repeat loop for entire screen from first box to last box b
        clearLine(0,lineNumber-1);                           
        for (i;i<sw*(sh-1)*2;i++){
            //moves entire line by linenumber; by copying the line 
        //for 2 - move 2 line up
            vidmem[i] = vidmem[i+sw*2*lineNumber];
        }
        //delete initial copy
        clearLine(sh-1-lineNumber,sh-1);

        //if cursor moves up the screen set to (0,0)
        if((cursorY - lineNumber) < 0 ) {
            cursorY = 0;
            cursorX = 0;
        } 
        else {
            cursorY -= lineNumber;
        }
        updateCursor();
}


void newLineCheck(){
        if(cursorY >=sh-1){
            scrollUp(1);
        }
}

//prints a character :)
void printch(char ch){
    string vidmem = (string) 0xb8000;     
    switch(ch){
        case (0x08): //backspace
            if(cursorX > 0){
	            cursorX--;									
                vidmem[(cursorY * sw + cursorX)*sd]=0x00;	                              
	        }
	        break;
        case ('\r'):
                cursorX = 0;
                break;
        case ('\n'):
                cursorX = 0;
                cursorY++;
                break;
        default:
                vidmem [((cursorY * sw + cursorX))*sd] = c;
                //colour 0 -white F- black
                vidmem [((cursorY * sw + cursorX))*sd+1] = 0x0F;
                cursorX++; 
                break;
	
    }
    if(cursorX >= sw){ //end of screen width
        cursorX = 0;                                                                
        cursorY++;                                                                    
    }
    updateCursor();
    newLineCheck();
}

void print (string ch){
        uint16 i = 0;
        //since counter starts from 0
        uint8 length = strlength(ch)-1; 
        for(i;i<length;i++){
                printch(ch[i]);
        }
}
