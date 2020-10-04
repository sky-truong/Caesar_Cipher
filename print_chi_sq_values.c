//
// Created by Sky Truong on 2020-03-05.
//

// This function prints all calculated chi square values

#include "decode.h"

void print_chi_sq_values ( char * string ) {
    int i, shift = 0, n = 0, * text_freq = NULL;;
    double chi_sq[26];
    char c = 'a';
    double ef[26] = EF;
    n = letter_count(string);
    text_freq = frequency_table_func(string);

    /* Setting chi square values to zeros */
    for ( shift = SHIFT_MIN; shift <= SHIFT_MAX; shift++ ) {
        chi_sq[shift] = 0;
    }

    /* Calculate chi square values */
    for ( shift = SHIFT_MIN; shift <= SHIFT_MAX; shift++ ) {
        for ( i = ALPHABET_MIN; i < ALPHABET_MAX; i++ ) {
            chi_sq[shift] += power (n * ef[offset(c)] - text_freq[offset(encode(c, shift))], 2 ) / (n * n * ef[offset(c)]);
            c++;
        }
        c = 'a';
        printf("Shift: %d \t Chi squared values: %lf\n", shift, chi_sq[shift]);
    }
}
