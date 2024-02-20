#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbres_binaires.h"


struct _noeud {
    char *val ;
    struct _noeud * fg , * fd ;
} ;



Noeud * alloue_noeud(char * s){
    Noeud* new_node = (Noeud *) calloc(1, sizeof(Noeud));
    if(!new_node){
        fprintf(stderr, "pb wiht malloc new_node in alloue_noeud");
        return NULL;
    }
    int len = strlen(s);
    new_node->val = (char *) malloc((len +1) * sizeof(char)); // len +1 pour inclure le null terminator('/0')
    if(!(new_node->val)){
        fprintf(stderr, "pb wiht malloc val in alloue_noeud");
        free(new_node);
        return NULL;
    }
    strcpy(new_node->val, s);
    return new_node;
}




/*Arbre construire_arbre_binaire(char * mot , const char separateur[3]){
    mot = strtok(NULL , separateur);
    if(mot){
       
        if(NOEUD_VIDE(mot))
            return NULL;
        
        if(NOEUD_EXIST(mot))
            mot = strtok(NULL , separateur);

        if(!mot)
            return NULL;
        Arbre a = alloue_Noeud(mot);
    
        if(!a){
            liberer_arbre(&a);
            exit(EXIT_FAILURE);

        }
        a->fg = construire_arbre_binaire(mot , separateur);
        a->fd = construire_arbre_binaire(mot , separateur);
        
       return a;
   }

    return NULL;
}
Arbre cree_A_1(void){
    char ligne[MAX_MOT] , *mot;
    int noeud;
    const char separateur[3] = "\n ";
    char code[] = "1 arbre\n 1 binaire\n 0 0 1 ternaire\n 0 0\0"; 
    mot = strtok(code , separateur); 
    return construire_arbre_binaire(mot , separateur);
}

Arbre cree_A_2(void){
    char ligne[MAX_MOT] , *mot;
    int noeud;
    const char separateur[3] = "\n ";
    char code[] = "1 Anémone\n 1 Camomille\n 0 0 1 Camomille\n 1 Dahlia\n 0 1 Camomille\n 1 Iris\n 0 0 1 Jasmin\n 0 0\0"; 
    mot = strtok(code , separateur); 
    return construire_arbre_binaire(mot , separateur);
}



Arbre cree_A_3(void){
    char ligne[MAX_MOT] , *mot;
    int noeud;
    const char separateur[3] = "\n ";
    char code[] = "1 IntelCorei9\n 1 AppleM3Max\n 0 1 AMDRyzen9\n 1 IntelCorei9\n 0 0 0 1 IntelCorei9\n 1 IntelCorei9\n 0 0 0\0"; 
    mot = strtok(code , separateur); 
    return construire_arbre_binaire(mot , separateur);
}

*/