//
// Created by Sky Truong on 2020-03-07.
//

// This function calculates power function

#include "decode.h"

double power ( double num, int pow ) {
    int i;
    double x = 1.0;
    for ( i = pow; i > 0; i--  ) {
        x = x * num;
    }
    return x;
}