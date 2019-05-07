#include "PDI Lists.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Lista_PDI cria_lista_pdi(char *nome, char* horario, char* descricao){
    Lista_PDI aux;
    aux=(Lista_PDI)malloc(sizeof(struct pnode));
    if (aux!=NULL){//vai criar a lista com os parametros nome,horario e descriçao
        strcpy(aux->nome,nome);
        strcpy(aux->horario,horario);
        strcpy(aux->descricao,descricao);
        aux->next=NULL;
    }
    return aux;
}

void insere_lista_pdi (Lista_PDI pdi, char* nome, char* horario, char* descricao){
    Lista_PDI aux;
    aux=pdi;
    while(aux->next!=NULL){//para encontrar o ultimo aux, para poder adicionar ao fim
        aux=aux->next;
    }
    aux->next=(Lista_PDI)malloc(sizeof(struct pnode));
    aux = aux->next;
    if (aux!=NULL){
        strcpy(aux->nome,nome);
        strcpy(aux->descricao,descricao);
        strcpy(aux->horario,horario);
        aux->next=NULL;
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
void sort_pdi(Lista_PDI pdi){
    Lista_PDI aux1,aux2,aux3,aux4,aux5;
    Lista_PDI aux=pdi;
    aux4= NULL;
    while(aux4!=aux->next){
        aux3=aux1=pdi;
        aux2=aux1->next;
        while(aux1!=aux4){
            if(strcmp(aux1->nome,aux2->nome)>0){
                if(aux1==pdi){
                    aux5=aux2->next;
                    aux2->next=aux1;
                    aux1->next=aux5;
                    pdi=aux2;
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
            else{
                aux3=aux1;
                aux1=aux1->next;
            }
            aux2=aux1->next;
            if(aux2==aux4){
                aux4=aux1;
            }
        }
    }
}
