#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbres_binaires.h"


struct _noeud {
    char *val ;
    struct _noeud * fg , * fd ;
};

typedef struct{
    char *code;
    int taille_max;
}Memo;



Noeud * alloue_noeud(char * s){
    Noeud* new_node = (Noeud *) calloc(1, sizeof(Noeud));
    if(!new_node){
        fprintf(stderr, "pb wiht malloc new_node in alloue_noeud");
        return NULL;
    }
    int len = strlen(s);
    new_node->val = (char *) malloc((len +1) * sizeof(char)); // len +1 pour inclure le null terminator('/0')
    if(!(new_node->val)){
        fprintf(stderr, "pb with malloc val in alloue_noeud");
        free(new_node);
        return NULL;
    }
    strcpy(new_node->val, s);
    return new_node;
}

void liberer(Arbre * A){
    if(*a){
        liberer(&((*a)->fg));
        liberer(&((*a)->fd));
        free(*a);
        (*a) = NULL;
    }
}

int creation_Memo(Memo *p){
    p->code = (char *)calloc( MAX_MOT, sizeof(char));
    if(p->code){
        p->taille_max = MAX_MOT;
        return 1;

    }
    fprintf(stderr ,"il s'est produit une erreur\n");

    free(p->code);
    return 0;
}

int  Copier_Chiffre(char *mot , Memo * p , int i){
    int copier = 0;
        for(;*mot != '\0';mot++)
        {
           
            if(NOEUD_VIDE(*mot)){
                strcat(p->code , "0");
                strcat(p->code , "-");
                copier = 1;
            }
            if(NOEUD_EXIST(*mot)){
                strcat(p->code , "1");
                strcat(p->code , "-");
                
                copier = 1;

            }
                
            

        }
    return copier;
      

}


int creation_code_adapter_arbre(Memo * p , char code_atester[MAX_MOT][MAX_MOT]){
    char ligne[MAX_MOT] , mot_tmp[MAX_MOT];
    int i = 0;
    fgets(ligne , MAX_MOT , stdin);
  
    char * mot = strtok(ligne , "\"");
    while (mot)
    {   

        if(!TEST_MOT(mot , code_atester[i])){
            printf("le mot %s n'est pas present dans le code souhaité %d %s\n", mot , i , code_atester[i]);
            free(p->code);
            return 0;
        }

            if(!Copier_Chiffre(mot , p , i)){
                mot[strlen(mot) - 1] = '\0';
                mot[strlen(mot) - 1] = '\0';
                strcat(p->code , mot);
                strcat(p->code , "-");
                
        } 
        
       
        i++;
       mot = strtok(NULL , "\"");
    }
    
    return 1;
}






Arbre construire_arbre_binaire(char * mot){
    mot = strtok(NULL , "-");
    if(mot){
       
        if(NOEUD_VIDE(*mot))
            return NULL;
        
        if(NOEUD_EXIST(*mot))
            mot = strtok(NULL , "-");

        if(!mot)
            return NULL;
        Arbre a = alloue_Noeud(mot);
    
        if(!a){
            liberer_arbre(&a);
            exit(EXIT_FAILURE);

        }
        a->fg = construire_arbre_binaire(mot);
        a->fd = construire_arbre_binaire(mot);
        
       return a;
   }

    return NULL;
}

Arbre cree_A_1(void){
    Memo p;
    char ligne[MAX_MOT] , *mot;
    char code_atester[MAX_MOT][MAX_MOT] = {"1 ","arbre\\n"," 1 ","binaire\\n", " 0 0 1 " ,"ternaire\\n", " 0 0\n"}; 
    creation_Memo(&p);
    if(creation_code_adapter_arbre(&p , code_atester)){
        char * mot = strtok(p.code , "-");
        return construire_arbre_binaire(mot);
    }


}
Arbre cree_A_2(void){
    Memo p;
    char ligne[MAX_MOT] , *mot;
    int noeud;
    char code_atester[MAX_MOT][MAX_MOT] = {"1 " , "Anémone\\n" ," 1 " ,"Camomille\\n", " 0 0 1 ", "Camomille\\n", " 1 ", "Dahlia\\n", " 0 1 ", "Camomille\\n", " 1 " ,"Iris\\n" ," 0 0 1 " ,"Jasmin\\n", " 0 0\n"};
    creation_Memo(&p);
    if(creation_code_adapter_arbre(&p , code_atester)){
        char * mot = strtok(p.code , "-");
        return construire_arbre_binaire(mot);
    }
}

Arbre cree_A_3(void){
    Memo p;
    char ligne[MAX_MOT] , *mot;
    int noeud;
    char code_atester[MAX_MOT][MAX_MOT] = {"1 ", "Intel Core i9\\n", " 1 " , "Apple M3 Max\\n", " 0 1 ", "AMD Ryzen 9\\n", " 1 " , "Intel Core i9\\n", " 0 0 0 1 ", "Intel Core i9\\n", " 1 ", "Intel Core i9\\n", " 0 0 0\n"}; 
    creation_Memo(&p);
    if(creation_code_adapter_arbre(&p , code_atester)){
        char * mot = strtok(p.code , "-");
        return construire_arbre_binaire(mot);
    }
}


