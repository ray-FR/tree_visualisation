#include "../include/textreader.h"

int issep(char c) {
    unsigned char uc = (unsigned char)c;
    return isspace(uc) || c == '!' || c == '?' || c == '.' ||
           c == '-' || c == ',' || c == ';' || c == ':' || c == '"' || c == '(' || c == ')' || c == '('
           || c == '{' || c == '}' || c == '[';
}
void chevec_push_back(chvec_t* vec, char* data){
    if(vec->size == vec->max_size) {
        void * ptr;
        vec->max_size = vec->max_size * 2;
        ptr = realloc(vec->data, vec->max_size * sizeof **(vec->data));
        if(ptr == NULL) {
        free(vec->data);
        free(vec);
        assert(ptr);
        } else
        vec->data = ptr;
    }
    
    vec->data[vec->size] = data;
    ++(vec->size);
}


chvec_t * newvec(void) {
  chvec_t * vec = malloc(1 * sizeof *vec);
  assert(vec);
  vec->size = 0;
  vec->max_size = 1024;
  vec->data = malloc(vec->max_size * sizeof **(vec->data));
  assert(vec->data);
  return vec;
}

void addnewword(chvec_t* vec, char* buff){
    int len;
    int i = 0;
    char* mot;
    int isinmot = 0;
    int start;
    while(buff[i] != '\n'){
        if(buff[i] == '\0') break;
        if (!issep(buff[i])){
            //printf("%c", buff[i]);
            if (!isinmot){
            start = i;
            isinmot = 1;}
        }
        else {
            if (isinmot){
                len = i - start;
                
                mot = malloc((len+1) * sizeof *mot);
                assert(mot);
                strncpy(mot, &buff[start], len);
                mot[len] = '\0';
                chevec_push_back(vec, mot);
                isinmot = 0;
                
                
            }

        }
        i++;
    }

    if (isinmot) {
        int len = i - start;
        char* mot = malloc(len + 1);
        assert(mot);
        strncpy(mot, &buff[start], len);
        mot[len] = '\0';
        chevec_push_back(vec, mot);
    }
    return;
}






