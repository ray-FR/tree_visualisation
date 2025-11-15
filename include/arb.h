#ifndef ARB_H
#define ARB_H
#include "struct.h"

extern arb_t* allC(char* v, arb_t* fg, arb_t* fd);
extern void priC(arb_t* a);
extern void libC(arb_t** a);
extern void assC(arb_t** a, chvec_t* v, int start, int end);
#endif