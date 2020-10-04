//
// Created by Sky Truong on 2020-03-05.
//

// This function calculates chi square values and extract good guess shift that encoded the message

#include "decode.h"

int encode_shift ( char * string ) {
    int i, shift = 0, chi_sq_shift = 0, n = 0, temp_chi_shift = 0, * text_freq = NULL;;
    double chi_sq[26], min_chi_sq = 0;
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
        //printf("Shift: %d \t Chi sq: %f\n", shift, chi_sq[shift]);
    }

    /* Comparing chi square values */
    min_chi_sq = chi_sq[SHIFT_MIN];
    for ( i = (SHIFT_MIN+1); i <= SHIFT_MAX; i++ ) {
        if (min_chi_sq > chi_sq[i] ) {
            min_chi_sq = chi_sq[i];
            temp_chi_shift = i;
        }
    }

    /* Extracting minimum chi square value if text is in English */
    if (min_chi_sq <= 0.5 ) {
        chi_sq_shift = temp_chi_shift;
    } else {
        chi_sq_shift = 0;
    }
    //printf("The min chi_sq %f with shift %d\n", min_chi_sq, chi_sq_shift );

    return chi_sq_shift;
}