//
// Created by Sky Truong on 2020-03-05.
//

// This function can be used to encode or decode

#include "decode.h"

char encode ( char c, int shift ) {
    int upper_case, lower_case, new_shift, temp = 0;
    char new_c;
    lower_case = c - 'a'; /*determine lower case starting letter*/
    upper_case = c - 'A'; /*determine upper case starting letter*/
    if ( lower_case >= ALPHABET_MIN && lower_case < ALPHABET_MAX ) {
        if ( shift > 0 ) {
            temp = ((lower_case + shift) % 26) + 97;
        } else if ( shift < 0 ) {
            new_shift = 26 + shift;
            temp = ((lower_case + new_shift) % 26) + 97;
        } else if ( shift == 0 ) {
            temp = c;
        }
        //temp = ((lower_case + shift) % 26) + 97;
        new_c = (char) temp;
    } else if ( upper_case >= ALPHABET_MIN && upper_case < ALPHABET_MAX ) {
        if ( shift > 0 ) {
            temp = ((upper_case + shift) % 26) + 65;
        } else if ( shift < 0 ) {
            new_shift = 26 + shift;
            temp = ((upper_case + new_shift) % 26) + 65;
        } else if ( shift == 0 ) {
            temp = c;
        }
        //temp = ((upper_case + shift) % 26) + 65;
        new_c = (char) temp;
    } else {
        new_c = c;
    }
    return new_c;
}