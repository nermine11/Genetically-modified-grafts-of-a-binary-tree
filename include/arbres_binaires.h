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
#define VALEUR_ABSOLUE(val)((val < 0)? -1 * val : val)

typedef struct _noeud {
    char *val ;
    struct _noeud * fg , * fd ;
}Noeud, *Arbre;

typedef struct{
    char *code;
    int taille_max;
}Memo;


Noeud * alloue_noeud(char * s);
/*qui réserve l’espace mémoire nécessaire à un nœud et renverra l’addresse mémoire où sera stocké le nœud ou NULL en cas d’echec*/
void liberer(Arbre * A);
/*qui libére tout l’espace mémoire utilisé pour stocker l’arbre *A.*/
Arbre cree_A_1(void);
/*création de l'arbre A_1 en mémoire renvoie l'arbre ou NULL en cas d'échec*/
Arbre cree_A_2(void);
/*création de l'arbre A_2 en mémoire renvoie l'arbre ou NULL en cas d'échec*/

Arbre cree_A_3(void);
/*création de l'arbre A_3 en mémoire renvoie l'arbre ou NULL en cas d'échec*/


int construit_arbre(Arbre *a);
/*saisi du code à partir d'une phrase renvoie 1 si l'arbre a été crée sinon 0*/

#endif
