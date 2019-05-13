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
void print_pdifav(Lista_PDI_Favs lista){
    Lista_PDI_Favs aux=lista;
    while(aux!=NULL){
        printf("%s\n",aux->nome_pdi);
        aux=aux->next;
    }
    printf("Estes são os seus pontos favoritos\n");
}
void procura_lista_pdifav (Lista_PDI_Favs pdi,char* lnome, Lista_PDI_Favs *ant, Lista_PDI_Favs *atual){
    int flag=1;
    *ant=pdi;//ponteiro inicial
    *atual=pdi->next;//ponteiro a apontar para o seguinte
    while((*atual)!=NULL && strcmp((*atual)->nome_pdi,lnome)!=0 && strcmp((*ant)->nome_pdi,lnome)!=0){//enqtn atual nao for o ultimo e as strings nao forem iguais o ant toma o valor do autal e o atual do seguinte
        *ant=*atual;
        *atual=(*atual)->next;
        flag=0;
    }
    if(flag==1){//isto pq nao estava a mandar o node certo qnd se pedia o 1º PDI
        *atual=*ant;
    }
}

Lista_PDI_Favs pesquisa_lista_pdifav(Lista_PDI_Favs list, char* name){//vai usar a procura lista para retornar o endereço da posiçao do local com o nome dado
    Lista_PDI_Favs ant;
    Lista_PDI_Favs atual;
    procura_lista_pdifav(list,name,&ant,&atual);
    return atual;
}
