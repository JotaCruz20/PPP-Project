#include "PDI Lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Lista_PDI cria_lista_pdi(char *nome, char* horario, char* descricao,int n){
    Lista_PDI aux;
    aux=(Lista_PDI)malloc(sizeof(struct pnode));
    if (aux!=NULL){//vai criar a lista com os parametros nome,horario e descriçao
        strcpy(aux->nome,nome);
        strcpy(aux->horario,horario);
        strcpy(aux->descricao,descricao);
        aux->pop=n;
        aux->next=NULL;
    }
    return aux;
}

void insere_lista_pdi_alpha (Lista_PDI pdi, char* nome, char* horario, char* descricao,int n){
    Lista_PDI aux, ant,inutil;
    aux = (Lista_PDI) malloc(sizeof(struct pnode));
    if (aux != NULL) {
        strcpy(aux->nome,nome);
        strcpy(aux->horario,horario);
        strcpy(aux->descricao,descricao);
        aux->pop=n;
        procura_lista_pdi_alpha(pdi,nome,&ant,&inutil);
        aux->next = ant->next;
        ant->next = aux;
    }
}

void insere_lista_pdi_pop (Lista_PDI pdi,char *nome, char* horario, char* descricao,int n ) {
    Lista_PDI aux, ant,inutil;
    aux = (Lista_PDI) malloc(sizeof(struct pnode));
    if (aux != NULL) {
        strcpy(aux->nome,nome);
        strcpy(aux->horario,horario);
        strcpy(aux->descricao,descricao);
        aux->pop=n;
        procura_lista_pdi_pop(pdi,n,&ant,&inutil);
        aux->next = ant->next;
        ant->next = aux;
    }
}

void imprime_lista_pdi (Lista_PDI pdi){
    Lista_PDI aux;
    aux=pdi;
    while(aux!=NULL){
        printf("%s %s %s\n", aux->nome,aux->descricao,aux->horario);
        aux=aux->next;
    }
}

void procura_lista_pdi_alpha(Lista_PDI pdi,char* lnome, Lista_PDI *ant, Lista_PDI *atual){
    *ant=pdi;//ponteiro inicial
    *atual=pdi->next;//ponteiro a apontar para o seguinte
    if(strcmp((*ant)->nome,lnome)>0 && (*ant)!=NULL){//caso seja logo o 1º caso
        *atual=*ant;
    }
    else {
        while ((*atual) != NULL && strcmp((*atual)->nome, lnome)<0) {//enqtn atual nao for o ultimo e as strings nao forem iguais o ant toma o valor do autal e o atual do seguinte
            *ant = *atual;
            *atual = (*atual)->next;
        }
    }
}

void procura_lista_pdi_pop (Lista_PDI pdi,int n, Lista_PDI *ant, Lista_PDI *atual){
    *ant=pdi;//ponteiro inicial
    *atual=pdi->next;//ponteiro a apontar para o seguinte
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


void procura_lista_pdi (Lista_PDI pdi,char* lnome, Lista_PDI *ant, Lista_PDI *atual){
    *ant=pdi;//ponteiro inicial
    *atual=pdi->next;//ponteiro a apontar para o seguinte
    if(strcmp((*ant)->nome,lnome)==0 ){
        *atual=*ant;
    }
    while((*atual)!=NULL && strcmp((*atual)->nome,lnome)!=0){//enqtn atual nao for o ultimo e as strings nao forem iguais o ant toma o valor do autal e o atual do seguinte
        *ant=*atual;
        *atual=(*atual)->next;
    }
}

Lista_PDI pesquisa_lista_pdi(Lista_PDI list, char* name){//vai usar a procura lista para retornar o endereço da posiçao do local com o nome dado
    Lista_PDI ant;
    Lista_PDI atual;
    procura_lista_pdi(list,name,&ant,&atual);
    return atual;
}
