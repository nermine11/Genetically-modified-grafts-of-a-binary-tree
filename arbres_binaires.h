#ifndef ARBRES_BINAIRES_H
#define ARBRES_BINAIRES_H
#define MAX_MOT 200
#define NOEUD_VIDE(mot) (((mot == '0'))? 1: 0 )
#define NOEUD_EXIST(mot) (((mot == '1'))? 1: 0 )
#define NOEUD_VIDE_STRING(tokens) (((strcmp(tokens , "0") == 0))? 1: 0 )
#define NOEUD_EXIST_STRING(tokens) (((strcmp(tokens , "1") == 0))? 1: 0 )
#define MOT_VIDE(tokens) ((strcmp(tokens , " ") == 0)? 1: 0 )
#define TEST_MOT(saisir , codage)((strcmp(saisir , codage) == 0)? 1: 0 )

typedef struct _noeud Noeud, *Arbre;

Noeud * alloue_noeud(char * s);
void liberer(Arbre * A);
Arbre cree_A_1(void);
Arbre cree_A_2(void);
Arbre cree_A_3(void);

int construit_arbre( Arbre * a );

#endif
