#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>



typedef struct chvec {
    size_t size;
    size_t max_size;
    char ** data;

} chvec_t;

typedef struct arb {
    char* name;
    int ind;
    struct arb* g;
    struct arb* d;
} arb_t;


#endif