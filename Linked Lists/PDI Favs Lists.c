#include "PDI Favs Lists.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Lista_PDI_Favs cria_lista_pdifavs(char* pnome){
    Lista_PDI_Favs aux;
    aux=(Lista_PDI_Favs)malloc(sizeof(struct pfnode));
    if (aux!=NULL){
        strcpy(aux->nome_pdi,pnome);
        aux->next=NULL;
    }
    return aux;
}

void insere_lista_pdifavs (Lista_PDI_Favs lista, char* lnome) {
    Lista_PDI_Favs aux=lista;
    while(aux->next!=NULL){//para encontrar o ultimo aux, para poder adicionar ao fim
        aux=aux->next;
    }
    aux->next=(Lista_PDI_Favs)malloc(sizeof(struct pfnode));
    aux = aux->next;
    if (aux!=NULL){
        strcpy(aux->nome_pdi,lnome);
        aux->next=NULL;
    }
}
void print_pdi(Lista_PDI_Favs lista){
    Lista_PDI_Favs aux=lista;
    while(aux->next!=NULL){
        printf("%s\n",aux->nome_pdi);
        aux=aux->next;
    }
    printf("Estes são os seus pontos favoritos");
}