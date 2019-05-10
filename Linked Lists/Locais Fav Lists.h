#ifndef TRABALHO_FINAL_LOCAIS_FAV_LISTS_H
#define TRABALHO_FINAL_LOCAIS_FAV_LISTS_H


typedef struct lfnode* Lista_Locais_Favs;//linked list para guardar os locais e PDIS
typedef struct lfnode{
    char nome_lfav[100];
    Lista_Locais_Favs next;
}List_Locais_Fav_node;

Lista_Locais_Favs cria_lista_lfavs(char* lnome);
void insere_lista_lfavs (Lista_Locais_Favs lista, char* lnome);


#endif //TRABALHO_FINAL_LOCAIS_FAV_LISTS_H
