//
// Created by Sky Truong on 2020-03-05.
//

// This function returns letters frequency in the alphabet

#include "decode.h"

int * frequency_table_func (char * string ) {
    int i = 0;
    int lower_case, upper_case, character = 0;
    int * alphabet = malloc(sizeof(int) * ALPHABET_MAX); /*needs to be returned*/
    /* Setting all values to 0 */
    for ( i = 0; i < ALPHABET_MAX; i++ ) {
        alphabet[i] = 0;
    }

    for ( i = 0; i < strlen(string); i++ ) {
        if ( (string[i] >= 'A' && string[i] <= 'Z') || (string[i] >= 'a' && string[i] <= 'z') ) {
            lower_case = string[i] - 'a'; /*determine lower case starting string*/
            upper_case = string[i] - 'A'; /*determine upper case starting string*/
            if (lower_case >= ALPHABET_MIN && lower_case < ALPHABET_MAX) {
                character = lower_case; /*get lower case char*/
            } else if (upper_case >= ALPHABET_MIN && upper_case < ALPHABET_MAX) {
                character = upper_case; /*get upper case char*/
            }
            alphabet[character]++;
            //printf("list: %d  *** count: %d\n", i, alphabet[character]);
        }
    }

    /*int  j = 'A';
    for ( i = 0; i < ALPHABET_MAX; i++ ) {
        printf("List %c has %d letters\n", j, alphabet[i]);
        j++;
    }*/

    return alphabet;
}