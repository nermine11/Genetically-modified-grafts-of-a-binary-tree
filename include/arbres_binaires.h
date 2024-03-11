#ifndef ARBRES_BINAIRES_H
#define ARBRES_BINAIRES_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_MOT 200
#define NOEUD_VIDE(mot) (((mot == '0'))? 1: 0 )
#define NOEUD_EXIST(mot) (((mot == '1'))? 1: 0 )
#define MOT_VIDE(tokens) ((strcmp(tokens , " ") == 0)? 1: 0 )
#define NOEUD_STRING_VIDE(mot)  ((strcmp(mot , " NULL") == 0)? 1: 0 )
#define FORMAT(code , format) ((strstr(code , format ) )? 1 : 0)
#define MOT_IDENTIQUE(mot , tokens)((strcmp(tokens , mot) == 0)? 1: 0 )


typedef struct _noeud {
    char *val ;
    struct _noeud * fg , * fd ;
}Noeud, *Arbre;

typedef struct{
    char *code;
    int taille_max;
}Memo;


Noeud * alloue_noeud(char * s);
void liberer(Arbre * A);
Arbre cree_A_1(void);
Arbre cree_A_2(void);
Arbre cree_A_3(void);
int construit_arbre(Arbre *a);
#endif
