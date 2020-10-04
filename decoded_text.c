//
// Created by Sky Truong on 2020-03-05.
//

// This function decodes text with given string's size and shift

#include "decode.h"

char * decoded_text ( char * string, int size, int shift ) {
    int i;
    char * my_text;
    my_text = malloc(sizeof(char) * size);
    for ( i = 0; i < size; i++ ) {
        my_text[i] = encode(string[i], shift);
    }
    return my_text;
}