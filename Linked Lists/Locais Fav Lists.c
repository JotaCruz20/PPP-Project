#include "Locais Fav Lists.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Lista_Locais_Favs cria_lista_lfavs(char* lnome){
    Lista_Locais_Favs aux;
    aux=(Lista_Locais_Favs)malloc(sizeof(struct lfnode));
    if (aux!=NULL){
        strcpy(aux->nome_lfav,lnome);
        aux->next=NULL;
    }
    return aux;
}

void insere_lista_lfavs (Lista_Locais_Favs lista, char* lnome) {
    Lista_Locais_Favs aux=lista;
    while(aux->next!=NULL){//para encontrar o ultimo aux, para poder adicionar ao fim
        aux=aux->next;
    }
    aux->next = (Lista_Locais_Favs) malloc(sizeof(struct lfnode));
    aux=aux->next;
    if (aux!=NULL){
        strcpy(aux->nome_lfav,lnome);
        aux->next=NULL;
    }
}