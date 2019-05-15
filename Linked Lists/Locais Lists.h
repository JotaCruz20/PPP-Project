#ifndef TRABALHO_FINAL_LOCAIS_LISTS_H
#define TRABALHO_FINAL_LOCAIS_LISTS_H
#include "PDI Lists.h"
#include "../Linked Lists/Favs Lists.h"

typedef struct lnode* Lista_Locais;//linked list para guardar os locais e PDIS
typedef struct lnode{
    char nome_local[100];
    int pop;
    Lista_PDI pontos;
    Lista_Locais next;
}List_Locais_node;

Lista_Locais cria_lista_locais(char* lnome,int n);
void imprime_lista_loc (Lista_Locais locais);
void insere_lista_loc (Lista_Locais lista, char* lnome,int n);
void procura_lista_loc (Lista_Locais loc,char* nome, Lista_Locais *ant, Lista_Locais *atual);
Lista_Locais pesquisa_lista_loc(Lista_Locais list, char* name);
void sort_loc(Lista_Locais loc);
void sort_loc_pref(Lista_Locais loc,Lista_Favs fav);

#endif //TRABALHO_FINAL_LOCAIS_LISTS_H
