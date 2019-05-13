#include "Locais Lists.h"
#include "PDI Lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Lista_Locais cria_lista_locais(char* lnome){//vai criar a lista com o nome lnome
    Lista_Locais aux;
    aux=(Lista_Locais)malloc(sizeof(struct lnode));
    if (aux!=NULL){
        strcpy(aux->nome_local,lnome);
        aux->next=NULL;
    }
    return aux;
}

void insere_lista_loc (Lista_Locais lista, char* lnome) {
    Lista_Locais aux=lista;
    while(aux->next!=NULL){//para encontrar o ultimo aux, para poder adicionar ao fim
        aux=aux->next;
    }
    aux->next = (Lista_Locais) malloc(sizeof(struct lnode));
    aux=aux->next;
    if (aux!=NULL){
        strcpy(aux->nome_local,lnome);
        aux->next=NULL;
    }
}

void procura_lista_loc (Lista_Locais loc,char* lnome, Lista_Locais *ant, Lista_Locais *atual){
    *ant=loc;//ponteiro inicial
    *atual=loc->next;//ponteiro a apontar para o seguinte
    while((*atual)!=NULL && strcmp((*atual)->nome_local,lnome)!=0 && strcmp((*ant)->nome_local,lnome)!=0){//enqtn atual nao for o ultimo e as strings nao forem iguais o ant toma o valor do autal e o atual do seguinte
        *ant=*atual;
        *atual=(*atual)->next;
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
void sort_loc(Lista_Locais loc){
    Lista_Locais aux1,aux2,aux3,aux4,aux5;//1-node atual,2-node seguinte,3-node anterior,4-usado para encontrar o fim,5-node temporario
    Lista_Locais aux=loc;//aux principal para usar a lista loc
    aux4= NULL;
    while(aux4!=aux->next){
        aux3=aux1=loc;
        aux2=aux1->next;//poe o aux2 a apontar para o node seguinte
        while(aux1!=aux4){
            if(strcmp(aux1->nome_local,aux2->nome_local)>0){//compara as strings do node atual e do seguinte
                if(aux1==loc){//ou seja se aux1 estiver no header da linked list
                    aux5=aux2->next;//fica com a informaçao de next do aux2
                    aux2->next=aux1;//troca aux2 para aux1
                    aux1->next=aux5;//troca aux1 para aux2
                    loc=aux2;//
                    aux3=aux2;
                }
                else{
                    aux5=aux2->next;
                    aux2->next=aux1;
                    aux1->next=aux5;
                    aux3->next=aux2;
                    aux3=aux2;
                }
            }
            else{//se aux1 nao for maior avança para o node seguinte
                aux3=aux1;//passamos a localizacao do aux3 para aux1
                aux1=aux1->next;//avançamos aux1 para node seguinte
            }
            aux2=aux1->next;
            if(aux2==aux4){
                aux4=aux1;
            }
        }
    }
}

void sort_loc_pref(Lista_Locais loc,Lista_Favs favs){
    int count,max;
    Lista_Locais pesq;

}//acabar isto asap

