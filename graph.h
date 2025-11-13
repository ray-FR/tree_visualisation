#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include "textreader.h"


extern void prepareFile(FILE* f, chvec_t* v);
extern void addGraph(FILE* f, chvec_t* v, int ind, int nbrelem);