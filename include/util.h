#ifndef UTIL_H
#define UTIL_H

#include "types.h"


//takes address of source and destination and no. of bytes we want to copy
//then copies them
void memory_copy(char *source, char *dest, int nbytes);

//sets specific value to the destination,
//if len = 10, value 20 gets set 10 times in the destination
//first place gets 20, second place gets 20 ... upto 10's place
void memory_set(uint8 *dest, uint8 val, uint32 len);

//integer to string 123>>"123"
void int_to_ascii(int n, char str[]);          

#endif
