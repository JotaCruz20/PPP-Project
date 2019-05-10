#include "Favs Lists.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


Lista_Favs cria_lista_favs(char* user){
    Lista_Favs aux;
    aux=(Lista_Favs)malloc(sizeof(struct fnode));
    if (aux!=NULL){
        strcpy(aux->user,user);
        memset(aux->hot,0,50);
        aux->next=NULL;
    }
    return aux;
}
Lista_Favs insere_hot_favs(Lista_Favs list,char* hot,char* user){
    Lista_Favs aux;
    aux=pesquisa_lista_favs(list,user);//serve para adicionar o ponto hot no user certo
    strcpy(aux->hot,hot);
}

void insere_lista_favs (Lista_Favs lista, char* user){
    Lista_Favs aux=lista;
    while(aux->next!=NULL){//para encontrar o ultimo aux, para poder adicionar ao fim
        aux=aux->next;
    }
    aux->next = (Lista_Favs) malloc(sizeof(struct fnode));
    aux=aux->next;
    if (aux!=NULL){
        strcpy(aux->user,user);
        memset(aux->hot,0,50);//para inicializar a memoria do hot limpa
        aux->next=NULL;
    }
}

void procura_lista_favs (Lista_Favs loc,char* lnome, Lista_Favs *ant, Lista_Favs *atual){
    *ant=loc;//ponteiro inicial
    *atual=loc->next;//ponteiro a apontar para o seguinte
    while((*atual)!=NULL && strcmp((*atual)->user,lnome)!=0){//enqtn atual nao for o ultimo e as strings nao forem iguais o ant toma o valor do autal e o atual do seguinte
        *ant=*atual;
        *atual=(*atual)->next;
    }
}

Lista_Favs pesquisa_lista_favs(Lista_Favs list, char* name){//vai usar a procura lista para retornar o endereço da posiçao do local com o nome dado
    Lista_Favs ant;
    Lista_Favs atual;
    procura_lista_favs(list,name,&ant,&atual);
    return atual;
}

void imprime_nomes (Lista_Favs fav){
    Lista_Favs aux;
    aux=fav;
    while(aux!=NULL){
        printf("%s\n", aux->user);
        aux=aux->next;
    }
}
void imprime_hot(Lista_Favs fav){
    Lista_Favs aux;
    aux=fav;
    while(aux!=NULL){
        printf("%s %s\n",aux->user,aux->hot);
        aux=aux->next;
    }
}