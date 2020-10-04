//
// Created by Sky Truong on 2020-03-05.
//

// This function returns total number of letters in a string

#include "decode.h"

int letter_count ( char * string ) {
    int i = 0;
    int num_letter = 0;

    for ( i = 0; i < strlen(string); i++ ) {
        if ((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z') ) {
            num_letter++;
        }
    }
    return num_letter;
}
