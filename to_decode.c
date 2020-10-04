//
// Created by Sky Truong on 2020-03-05.
//

// This function gives to decode shift

#include "decode.h"

int to_decode ( int shift ) {
    int decode_shift = 0;
    if ( shift == 0 ) {
        decode_shift = 0;
    } else {
        decode_shift = 26 - shift;
    }
    return decode_shift;
}