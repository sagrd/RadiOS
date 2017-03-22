#include "include/kb.h"
#include "include/isr.h"
#include "include/idt.h"
int kmain()
{	
       //interupt service routine 
       isr_install(); 
       clearScreen();
       
       print("Hi and Welcome to NIDOS operating system\nPlease enter a command");
       printch('\n');
       print("NIDOS> ");
       while (1)
       {
                string ch = readStr();
                print("\n");
                print(ch);
               	if(strEql(ch,"cmd"))
                {
                        print("\nYou are allready in cmd\n");
                }
                else if(strEql(ch,"clear"))
                {
                        clearScreen();
                        print("NIDOS> ");
                }
                
                else
                {
                        print("Bad command!");
                }      
       }
return 0;
}
