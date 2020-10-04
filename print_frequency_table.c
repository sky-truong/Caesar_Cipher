//
// Created by Sky Truong on 2020-03-05.
//

// This function prints frequency table to stdout

#include "decode.h"

void print_frequency_table ( int * freq_array ) {
    int i = 0, alphabet = 0;
    printf("Alphabet\tCount\n");
    for ( alphabet = 'A'; alphabet < 'Z'; alphabet++ ) {
        printf("%c \t \t", alphabet);
        printf("%d\n", freq_array[i]);
        i++;
    }
}