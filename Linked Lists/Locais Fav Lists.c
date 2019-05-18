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
void print_locfav(Lista_Locais_Favs lista){
    Lista_Locais_Favs aux=lista;
    if(aux!=NULL) {
        printf("\nEstes são os seus locais favoritos\n");
        while (aux != NULL) {
            printf("%s\n", aux->nome_lfav);
            aux = aux->next;
        }
    }
}
void procura_lista_locfav (Lista_Locais_Favs pdi,char* lnome, Lista_Locais_Favs *ant, Lista_Locais_Favs *atual){
    *ant=pdi;//ponteiro inicial
    *atual=pdi->next;//ponteiro a apontar para o seguinte
    if(strcmp((*ant)->nome_lfav ,lnome)==0){//necessario pois o 1º node nao esta em branco, logo se o ant for logo o procurado, passa o ant para o atual
        *atual=*ant;
    }
    else {
        while ((*atual) != NULL && strcmp((*atual)->nome_lfav, lnome) !=0) {//enqtn atual nao for o ultimo e as strings nao forem iguais o ant toma o valor do autal e o atual do seguinte
            *ant = *atual;
            *atual = (*atual)->next;
        }
    }
}

Lista_Locais_Favs pesquisa_lista_locfav(Lista_Locais_Favs list, char* name){//vai usar a procura lista para retornar o endereço da posiçao do local com o nome dado
    Lista_Locais_Favs ant;
    Lista_Locais_Favs atual;
    procura_lista_locfav(list,name,&ant,&atual);
    return atual;
}

void elimina_locfav (Lista_Locais_Favs lista, char* nome){
    Lista_Locais_Favs ant;
    Lista_Locais_Favs actual;
    procura_lista_locfav (lista,nome, &ant, &actual);
    if (actual != NULL) {
        ant->next = actual->next;
        free (actual);
    }
}