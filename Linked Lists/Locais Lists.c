#include "Locais Lists.h"
#include "PDI Lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Lista_Locais cria_lista_locais(char* lnome,int n){//vai criar a lista com o nome lnome
    Lista_Locais aux;
    aux=(Lista_Locais)malloc(sizeof(struct lnode));
    if (aux!=NULL){
        strcpy(aux->nome_local,lnome);
        aux->pop=n;
        aux->next=NULL;
    }
    return aux;
}

void insere_lista_loc_alpha (Lista_Locais lista, char* lnome,int n) {
    Lista_Locais aux, ant,inutil;
    aux = (Lista_Locais) malloc(sizeof(List_Locais_node));
    if (aux != NULL) {
        strcpy(aux->nome_local,lnome);
        aux->pop=n;
        aux->pontos=lista->pontos;
        procura_lista_insert(lista,lnome,&ant,&inutil);
        aux->next = ant->next;
        ant->next = aux;
    }
}

void insere_lista_loc_pop (Lista_Locais lista, char* lnome,int n) {
    Lista_Locais aux, ant,inutil;
    aux = (Lista_Locais) malloc(sizeof(List_Locais_node));
    if (aux != NULL) {
        strcpy(aux->nome_local,lnome);
        aux->pop=n;
        aux->pontos=lista->pontos;
        procura_lista_insert_pop(lista,n,&ant,&inutil);
        aux->next = ant->next;
        ant->next = aux;
    }
}

void procura_lista_loc (Lista_Locais loc,char* lnome, Lista_Locais *ant, Lista_Locais *atual){
    *ant=loc;//ponteiro inicial
    *atual=loc->next;//ponteiro a apontar para o seguinte
    if(strcmp((*ant)->nome_local,lnome)==0){//caso seja logo o 1º caso
        *atual=*ant;
    }
    else {
        while ((*atual) != NULL && strcmp((*atual)->nome_local, lnome) !=0) {//enqtn atual nao for o ultimo e as strings nao forem iguais o ant toma o valor do autal e o atual do seguinte
            *ant = *atual;
            *atual = (*atual)->next;
        }
    }
}

void procura_lista_insert(Lista_Locais loc,char* nome, Lista_Locais *ant, Lista_Locais *atual){
    *ant=loc;//ponteiro inicial
    *atual=loc->next;//ponteiro a apontar para o seguinte
    if(strcmp((*ant)->nome_local,nome)>0 && (*ant)!=NULL){//caso seja logo o 1º caso
        *atual=*ant;
    }
    else {
        while ((*atual) != NULL && strcmp((*atual)->nome_local, nome)<0) {//enqtn atual nao for o ultimo e as strings nao forem iguais o ant toma o valor do autal e o atual do seguinte
            *ant = *atual;
            *atual = (*atual)->next;
        }
    }
}

void procura_lista_insert_pop(Lista_Locais loc,int  n, Lista_Locais *ant, Lista_Locais *atual){
    *ant=loc;//ponteiro inicial
    *atual=loc->next;//ponteiro a apontar para o seguinte
    if((*ant)->pop>n && (*ant)!=NULL){//caso seja logo o 1º caso
        *atual=*ant;
    }
    else {
        while ((*atual) != NULL && (*atual)->pop>n) {//enqtn atual nao for o ultimo e as strings nao forem iguais o ant toma o valor do autal e o atual do seguinte
            *ant = *atual;
            *atual = (*atual)->next;
        }
    }
}

Lista_Locais pesquisa_lista_loc(Lista_Locais list, char* name){//vai usar a procura lista para retornar o endereço da posiçao do local com o nome dado
    Lista_Locais ant;
    Lista_Locais atual;
    procura_lista_loc(list,name,&ant,&atual);
    return atual;
}

void imprime_lista_loc (Lista_Locais locais){//serve para imprimir a lista loc
    Lista_Locais aux;
    aux=locais;
    while(aux!=NULL){
        printf("%s\n",aux->nome_local);//imprime o nome do local
        imprime_lista_pdi(aux->pontos);//imprime os pdis do local
        printf("\n");
        aux=aux->next;
    }
}