#include "Registo Lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
Lista_Registo cria_lista_registo(char* nome,char* data,char* morada,char* telemovel) {
    Lista_Registo aux;
    aux = (Lista_Registo) malloc(sizeof(struct rnode));
    if (aux != NULL) {
        strcpy(aux->nome, nome);
        strcpy(aux->data, data);
        strcpy(aux->cidade, morada);
        strcpy(aux->telemovel, telemovel);
        aux->next = NULL;
    }
    return aux;
}
void insere_lista_reg (Lista_Registo reg,char* nome,char* data,char* morada,char* telemovel){
    Lista_Registo aux=reg;
    while(aux->next!=NULL){//para encontrar o ultimo aux, para poder adicionar ao fim
        aux=aux->next;
    }
    aux->next=(Lista_Registo)malloc(sizeof(struct rnode));
    aux=aux->next;
    if (aux!=NULL){
        strcpy(aux->nome,nome);
        strcpy(aux->data,data);
        strcpy(aux->cidade,morada);
        strcpy(aux->telemovel,telemovel);
        aux->next=NULL;
    }
}

void imprime_lista_reg (Lista_Registo reg){
    Lista_Registo aux=reg;
    while(aux!=NULL){
        printf("%s %s %s %s\n", aux->nome,aux->data,aux->cidade,aux->telemovel);
        aux=aux->next;
    }
}

void procura_lista_reg (Lista_Registo reg,char* user, Lista_Registo *ant, Lista_Registo *atual){
    *ant=reg;//ponteiro inicial
    *atual=reg->next;//ponteiro a apontar para o seguinte
    while((*atual)!=NULL && strcmp((*atual)->nome,user)!=0){//enqtn atual nao for o ultimo e as strings nao forem iguais o ant toma o valor do autal e o atual do seguinte
        *ant=*atual;
        *atual=(*atual)->next;
    }
}

Lista_Registo pesquisa_lista_reg(Lista_Registo reg, char* user){//vai usar a procura lista para retornar o endereço da posiçao do local com o nome dado
    Lista_Registo ant;
    Lista_Registo atual;
    procura_lista_reg(reg,user,&ant,&atual);
    return atual;
}
