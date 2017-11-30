#include "../../includes/keyboard.h"
int kernel(){
        clearScreen();
        print("\n___________|___________");
        print("\n________RAD|OS_________");
        print("\n___________|___________\n");
        print("\n Enter a command");

        while(1){
            print("\nRadiOS >>");
            string ch = readStr();

            if(strEql(ch, "cmd")){
            print("\nYou are IN-COMMAND");
            }
            else if(strEql(ch, "clear")){
              clearScreen();
              // print(ch);
              print("\n___________|___________");
              print("\n________RAD|OS_________");
              print("\n___________|___________");
              print("\n Enter a command");
              print("\nRadiOS >>");
            }
            else{
              print("\n Bad Command!");
            }
          print("\n");
        }
return 0;      
}
