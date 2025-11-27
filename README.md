# Programme pour lire un fichier puis pour générer son arbre binaire équilibre correspondant

### Structure du répertoire
```
tree_visualisation/
    include/
        arb.h 
        graph.h
        struct.h
        textreader.h
    src/
        arb.c
        graph.c
        main.c
        textreader.c
    build/
        fichier .o correspondant au *.c
    ./graph
    Makefile
```

### Fonctionnemnt avec example
- Avoir Graphviz installer sur le système ([lien ici](https://graphviz.org/download/))
```make && cat horloge_short.txt | ./graph >> g.dot && dot -Tpdf g.dot -o g.pdf```

### Struct(s) utilisé 
```c
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
```
### Explications fonctions
```
    arb.c
        -> Code C pour générer un arbre à partie des données d'un vecteur
        (NOTE: code inspiré par celui de M. De Félice dans son cours d'algo-struct)

        arb_t* allC(char* v, int ind, arb_t* fg, arb_t* fd)
            - Alloue les cellules
        void priC(arb_t* a)
            - Print de manière préfixe un arbre
        void libC(arb_t** a)
            - Libère les cellules
        void assC(arb_t **a, chvec_t *v, int start, int end)
            - Fonction permettant la création d'un arbre binaire étiqueté

    textreader.c
        -> Code C pour lire le contenu d'un fichier "pipé" à l'éxecutable

        int issep(char c)
            - Renvoie 1 si "c" est un caractère considéré comme séparateur 
        
        void chevec_push_back(chvec_t* vec, char* data)
            (NOTE: code modifié et issu de vous)
            - Fonction permettant l'allocation de mémoire en plus si le nombre d'élément size dépasse max_size, sinon ajoute le char* data au vecteur
        
        chvec_t * newvec(void)
            -> Création nouveau vecteur

        void addnewword(chvec_t* vec, char* buff)
            -> Fonction permettant l'ajout des mots issus d'un char* 
                - Lance une boucle while qui ne se termine que si le caractère indexé est une fin de ligne ou un EOF
                - Quand on est pas sur un séparateur, on sauvegarde l'indice de ou on se trouve, puis on itère tant qu'on est pas sur un séparateur
                - Lorsque on est sur un séparateur, on prend la longueur depuis l'index ou on n'était pas sur un séparateur
                    - On initialise un char* ou on assigne un strncpy qui copie la longueur du mot enregistré, puis un EOF à la fin de ce mot. On l'ajoute à vec avec chevec_push_back
                
                (NOTE: Code répété en dehors de la boucle pour le dernier mot, vu que la boucle s'arrête quand on encontre un \n/EOF)

    graph.c
        void prepareFile(chvec_t* v, arb_t* a)
            -> Fonction oû on printf les 1ères lignes redirigé au fichier graph, puis qui appelle AddGraph
        
        void addGraph(chvec_t* v, arb_t* a, int n)
            -> Fonction qui printf la racine de l'arbre a et ses enfants
```
