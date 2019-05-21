#ifndef TRABALHO_FINAL_FAVS_LISTS_H
#define TRABALHO_FINAL_FAVS_LISTS_H
#include "PDI Favs Lists.h"
#include "Locais Fav Lists.h"

typedef struct hnode* Lista_Hot;//linked list para guardar os locais e PDIS
typedef struct hnode{
    char hot[100];
}List_Hot_node;



typedef struct fnode* Lista_Favs;//linked list para guardar os locais e PDIS
typedef struct fnode{
    char user[50];
    Lista_Hot hot;
    Lista_Locais_Favs lfav;
    Lista_PDI_Favs pfav;
    Lista_Favs next;
}List_Favs_node;

Lista_Favs cria_lista_favs(char* user);
Lista_Favs insere_hot_favs(Lista_Favs list,char* hot,char* user);
void insere_lista_favs (Lista_Favs lista, char* user);
void procura_lista_favs (Lista_Favs loc,char* lnome, Lista_Favs *ant, Lista_Favs *atual);
Lista_Favs pesquisa_lista_favs(Lista_Favs list, char* name);
void imprime_hot(Lista_Hot fav);
Lista_Hot cria_lista_hot(char* ponto);

Lista_Favs destroi_fav(Lista_Favs fav);


#endif //TRABALHO_FINAL_FAVS_LISTS_H
