#ifndef TRABALHO_FINAL_LOCAIS_FAV_LISTS_H
#define TRABALHO_FINAL_LOCAIS_FAV_LISTS_H


typedef struct lfnode* Lista_Locais_Favs;//linked list para guardar os locais e PDIS
typedef struct lfnode{
    char nome_lfav[100];
    Lista_Locais_Favs next;
}List_Locais_Fav_node;

Lista_Locais_Favs cria_lista_lfavs(char* lnome);
void insere_lista_lfavs (Lista_Locais_Favs lista, char* lnome);
void elimina_locfav (Lista_Locais_Favs lista, char* nome);
Lista_Locais_Favs pesquisa_lista_locfav(Lista_Locais_Favs list, char* name);
void procura_lista_locfav (Lista_Locais_Favs pdi,char* lnome, Lista_Locais_Favs *ant, Lista_Locais_Favs *atual);
void print_locfav(Lista_Locais_Favs lista);


#endif //TRABALHO_FINAL_LOCAIS_FAV_LISTS_H
