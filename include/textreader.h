#ifndef TEXTREADER_H
#define TEXTREADER_H

#include "struct.h"



  


extern int issep(char txt);

extern chvec_t * newvec(void);

extern void addnewword (chvec_t* vec, char* buff);

extern void chevec_push_back(chvec_t* vec, char* data);

#endif