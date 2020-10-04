//
// Created by Sky Truong on 2020-03-05.
//

// This function offsets the alphabet letters to use to chi square algorithm

#include "decode.h"

int offset ( char c ) {
    int ret = 0, lower_case, upper_case = 0;
    lower_case = c - 'a'; /*determine lower case starting string*/
    upper_case = c - 'A'; /*determine upper case starting string*/
    if (lower_case >= ALPHABET_MIN && lower_case < ALPHABET_MAX) {
        ret = lower_case; /*get lower case char*/
    } else if (upper_case >= ALPHABET_MIN && upper_case < ALPHABET_MAX) {
        ret = upper_case; /*get upper case char*/
    }
    //printf("offset value is: %d\n", ret);
    return ret;
}