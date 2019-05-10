#ifndef TRABALHO_FINAL_FAVS_LISTS_H
#define TRABALHO_FINAL_FAVS_LISTS_H
#include "PDI Favs Lists.h"
#include "Locais Fav Lists.h"

typedef struct fnode* Lista_Favs;//linked list para guardar os locais e PDIS
typedef struct fnode{
    char user[50];
    char hot[100];
    Lista_Locais_Favs lfav;
    Lista_PDI_Favs pfav;
    Lista_Favs next;
}List_Favs_node;

Lista_Favs cria_lista_favs(char* user);
Lista_Favs insere_hot_favs(Lista_Favs list,char* hot,char* user);
void insere_lista_favs (Lista_Favs lista, char* user);
void procura_lista_favs (Lista_Favs loc,char* lnome, Lista_Favs *ant, Lista_Favs *atual);
Lista_Favs pesquisa_lista_favs(Lista_Favs list, char* name);
void imprime_nomes(Lista_Favs favs);
void imprime_hot(Lista_Favs fav);


#endif //TRABALHO_FINAL_FAVS_LISTS_H
