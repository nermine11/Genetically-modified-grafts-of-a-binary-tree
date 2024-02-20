#ifndef ARBRES_BINAIRES_H
#define ARBRES_BINAIRES_H

#define  MAX_MOT 100
#define NOEUD_EXIST(tokens) (tokens && (strcmp(tokens , "1") == 0)? 1: 0 )
#define NOEUD_VIDE(tokens) (tokens && (strcmp(tokens , "0") == 0)? 1: 0 )

typedef struct _noeud Noeud, *Arbre;

Noeud * alloue_noeud(char * s);
void liberer(Arbre * A);
Arbre cree_A_1(void);
Arbre cree_A_2(void);
Arbre cree_A_3(void);

int construit_arbre( Arbre * a );

#endif
