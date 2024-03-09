#include "arbres_binaires.h"




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

void liberer(Arbre * a){
    if(*a){
        liberer(&((*a)->fg));
        liberer(&((*a)->fd));
        free((*a)->val);
        free(*a);
        (*a) = NULL;
    }
}

Arbre cree_A_1(void){
   Arbre a = alloue_noeud("arbre");
   if(!a)
    return NULL;
   a->fg = alloue_noeud("binaire");
   if(!a->fg){
        liberer(&a);
        return NULL;
   }
   a->fd = alloue_noeud("ternaire");
   if(!a->fd){
        liberer(&a);
        return NULL;
   }
   return a;
}


Arbre cree_A_2(void){
    Arbre root = alloue_noeud("Anémone");
    if(!root){
        fprintf(stderr, "pb avec malloc in cree_A_2");
        return NULL;
    }
    root->fg = alloue_noeud("Camomille");
    if(!root->fg){
        fprintf(stderr, "pb avec malloc in cree_A_2");
        free(root);
        return NULL;
    }
    root->fd = alloue_noeud("Camomille");
    if(!root->fd){
        fprintf(stderr, "pb avec malloc in cree_A_2");
        liberer(&root);
        return NULL;
    }
    root ->fd->fg = alloue_noeud("Dahlia");
    if(!root->fd->fg){
        fprintf(stderr, "pb avec malloc in cree_A_2");
        liberer(&root);
        return NULL;
    }
    root->fd->fg->fd  = alloue_noeud("Camomille");
    if(!root->fd->fg->fd){
        fprintf(stderr, "pb avec malloc in cree_A_2");
        liberer(&root);
        return NULL;
    }
    root->fd->fg->fd->fg = alloue_noeud("Iris");
    if(!root->fd->fg->fd->fg){
        fprintf(stderr, "pb avec malloc in cree_A_2");
        liberer(&root);
        return NULL;
    }
    root->fd->fg->fd->fd = alloue_noeud("Jasmin");
    if(!root->fd->fg->fd->fd){
        fprintf(stderr, "pb avec malloc in cree_A_2");
        liberer(&root);
        return NULL;
    }
    return a;
}


Arbre cree_A_3(void){
    Arbre a = alloue_noeud("Intel Core i9");
    if(!a){
        liberer(&a);
        return NULL;
   }
    a->fg = alloue_noeud("Apple M3 Max");
    if(!a->fg){
        liberer(&a);
        return NULL;
   }
    a->fg->fd = alloue_noeud("AMD Ryzen 9");
    if(!a->fg->fd){
        liberer(&a);
        return NULL;
   }
    a->fg->fd->fg = alloue_noeud("Intel Core i9");
    if(!a->fg->fd->fg){
        liberer(&a);
        return NULL;
   }
    a->fd = alloue_noeud("Intel Core i9");
    if(!a->fd){
        liberer(&a);
        return NULL;
   }
    a->fd->fg = alloue_noeud("Intel Core i9");
    if(!a->fd->fg){
        liberer(&a);
        return NULL;
   }
    return a;




}
