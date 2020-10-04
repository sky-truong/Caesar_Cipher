//
// Created by Sky Truong on 2020-03-08.
//

// This function returns the number of records

#include "decode.h"

int num_records ( int record_size ) {
    int num;
    num = record_size/ sizeof(record);
    return num;
}