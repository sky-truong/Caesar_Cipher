//
// Created by Sky Truong on 2020-03-08.
//

// This function returns size of a file

#include "decode.h"

int file_size ( FILE *fp ) {
    int sz = 0;
    fseek(fp, 0L, SEEK_END);
    sz = ftell(fp);
    rewind(fp);
    return sz;
}
