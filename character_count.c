//
// Created by Sky Truong on 2020-03-05.
//

// This function counts all the characters in a string

#include "decode.h"

int character_count ( char * string ) {
    int i, count = 0;

    for ( i = 0; i < strlen(string); i++ ) {
        if (string[i] > 32 && string[i] < 127 ) { /* All characters */
            count++;
        }
    }
    return count;
}