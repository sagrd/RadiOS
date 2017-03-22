#include "util.h"

void memory_copy(char *source, char *dest, int nbytes) {
    int i;
    for (i = 0; i < nbytes; i++) {
        // dest[i] = source[i]
        *(dest + i) = *(source + i);             
    }
}

void memory_set(uint8 *dest, uint8 val, uint32 len) {
    uint8 *temp = (uint8 *)dest;
    for ( ; len != 0; len--){
        *temp++ = val;
    } 
}

void int_to_ascii(int n, char str[]) {          
    int i, sign;
    if ((sign = n) < 0) {
        n = -n;
    }

    i = 0;
    do {
        str[i++] = n % 10 + '0';   //for 45 => 5 + 48(= char '0') = 53  (= char of 5)
    } while ((n /= 10) > 0);

    if (sign < 0){ 
        str[i++] = '-';
    }
    str[i] = '\0'; //null character

}
