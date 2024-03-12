
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
        free(root);
        return NULL;
    }
    root ->fd->fg = alloue_noeud("Dahlia");
    if(!root->fd->fg){
        fprintf(stderr, "pb avec malloc in cree_A_2");
        free(root);
        return NULL;
    }
    root->fd->fg->fd  = alloue_noeud("Camomille");
    if(!root->fd->fg->fd){
        fprintf(stderr, "pb avec malloc in cree_A_2");
        free(root);
        return NULL;
    }
    root->fd->fg->fd->fg = alloue_noeud("Iris");
    if(!root->fd->fg->fd->fg){
        fprintf(stderr, "pb avec malloc in cree_A_2");
        free(root);
        return NULL;
    }
    root->fd->fg->fd->fd = alloue_noeud("Jasmin");
    if(!root->fd->fg->fd->fd){
        fprintf(stderr, "pb avec malloc in cree_A_2");
        free(root);
        return NULL;
    }
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

static int  Copier_Chiffre(char *mot , Memo * p){
    int copier = 0 , val = 0;

    if(!strstr(mot, "\\n")){

        for(;*mot != '\0';mot++)
        {
            copier = (NOEUD_VIDE(*mot))? 1 : (NOEUD_EXIST(*mot))? 2 : (*mot == ' ')? 3 : (*mot == '\n')? 3 : -1;
            

            switch (copier)
            {
                case 1:
                  
                    strcat(p->code , "0");
                    strcat(p->code , "*");
                    val = 1;
                    break;

                case 2:
        
                    strcat(p->code , "1");
                    strcat(p->code , "*");
                    val = 1;
                break;

                case 3:
                break;

                default:
                    return -1;
            }
 
        }

        if(!val)
            return -1;

        return val;
    }
    
    return copier;
      

}


static int lire(char * chaine , int longeur  , Memo * p){
    char *test;
    
    if(!fgets(chaine , longeur, stdin)){
        fprintf(stderr , "il y a eu un problème\n");
        fflush(stdin);
        return 0;
    }
    if(!(test = strchr(chaine , '\n'))){
        fprintf(stderr , "la ligne que vous avez saisi est trop longue (max caractères : 200)\n");
        fflush(stdin);
        return 0;
    }
    if(!strstr(chaine , "\"") && !strstr(chaine , "\\n")){
        fprintf(stderr , "le code n'est pas dans le bon format \n");
        return 0;
    }



    return 1;

    
}

static int verification_mot(char * mot){
    if( mot[strlen(mot) - 2] != '\\' && mot[strlen(mot) - 1] != 'n')
        return 0;
    return 1;
}
static void vider_memo(char * code , int taille){
    char * fin = code + taille;
    for(; code < fin ; code++){
        *code ='\0';
    }
}

static int creation_code_adapter_arbre(Memo * p){
    char ligne[MAX_MOT] ;
    int value_copie;
    if(!lire(ligne , MAX_MOT  ,p)){
        fprintf(stderr , "il y a eu un problème\n");
        return 0;

    }
    char * mot = strtok(ligne , "\"");
    while (mot)
    {   
        if(p->taille_max <= strlen(p->code) + strlen(mot)){ 
            if(!reallouer(p)){
                free(p->code);
                return 0;
            }
        }

        value_copie = Copier_Chiffre(mot , p);
        if(value_copie == -1){
            fprintf(stderr , "le code de cette arbre est incorrecte, je pense que vous avez saisi un mauvais chiffre\n");
            vider_memo(p->code , strlen(p->code));
            return 0;
        }

        if(!value_copie && !NOEUD_EXIST(p->code[strlen(p->code) - 2]) && !verification_mot(mot)){
            fprintf(stderr , "le code de cette arbre est incorrecte, je pense que vous avez saisi un mauvais chiffre\n");
            vider_memo(p->code , strlen(p->code));
            return 0;
        }

        if(!value_copie){
            mot[strlen(mot) - 1] = '\0';
            mot[strlen(mot) - 1] = '\0';
            strcat(p->code , mot);
            strcat(p->code , "*");
        }
        
       mot = strtok(NULL , "\"");
    }
    
   
    return 1;
}

static int creation_Memo(Memo *p){
    p->code = (char *)calloc( MAX_MOT, sizeof(char));
    if(p->code){
        p->taille_max = MAX_MOT;
        return 1;

    }
    fprintf(stderr ,"il s'est produit une erreur\n");

    free(p->code);
    return 0;
}





static Arbre construire_arbre_binaire(char * mot){
    mot = strtok(NULL , "*");
    if(mot){
       
        if(NOEUD_VIDE(*mot))
            return NULL;
        
        if(NOEUD_EXIST(*mot))
            mot = strtok(NULL , "*");
    
        

        if(!mot)
            return NULL;
        Arbre a = alloue_noeud(mot);
    
        if(!a){
            liberer(&a);
            exit(EXIT_FAILURE);

        }
        a->fg = construire_arbre_binaire(mot);
        a->fd = construire_arbre_binaire(mot);
        
       return a;
   }

    return NULL;
}
int construit_arbre(Arbre *a){
    Memo p;
    
    char ligne[MAX_MOT];
   
    creation_Memo(&p);
    char arret = 'n';
    int nb_echec = 0;
    while (!creation_code_adapter_arbre(&p)){
        if(nb_echec == 5)printf("voulez-vous arrêter ?[O/N]\n");

        if(nb_echec == 5 && scanf("%c" , &arret) < 1)
            fflush(stdin);
            
        if(nb_echec == 5 &&(arret == 'o' || arret == 'O')){
            free(p.code);
            return 0;
        }
        if(nb_echec == 5 && (arret == 'n' || arret == 'N')){
            nb_echec = 0;
            fflush(stdin);
        }
        nb_echec++;
    }

    char * mot = strtok(p.code , "*");
    *a = construire_arbre_binaire(mot);  
    
    free(p.code);
    return (!(*a))? 0 : 1;

}





