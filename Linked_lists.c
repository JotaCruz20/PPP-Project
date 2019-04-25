#include "Linked_lists.h"
#include <stdlib.h>
List cria_lista(void){
    List aux;
    aux = (List)malloc(sizeof(Registo));
    if (aux!=NULL){
        aux ->next=NULL;
    }
    return aux;
}

List destroi_lista(List lista){
    List temp_ptr;
    while (lista_vazia (lista) == 0) {
        temp_ptr = lista;
        lista= lista->next;
        free (temp_ptr);
    }
    free(lista);
    return NULL;
}
int lista_vazia(List lista){
    return (lista->next == NULL ? 1 : 0);
}

int lista_cheia (List lista){
    return 0;
}

void procura_lista (List lista, double chave, List *ant, List
*actual)
{
    *ant = lista; *actual = lista->next;
    while ((*actual) != NULL && (*actual)->info < chave)
    {
        *ant = *actual;
        *actual = (*actual)->next;
    }
    if ((*actual) != NULL && (*actual)->info != chave)
        *actual = NULL; /* Se elemento não encontrado*/
}

void elimina_lista (List lista, double it)
{
    List ant;
    List actual;
    procura_lista (lista, it, &ant, &actual);
    if (actual != NULL) {
        ant->next = actual->next;
        free (actual);
    }
}

void insere_lista (List lista, double it) {
    List no;
    List ant, inutil;
    no = (List) malloc(sizeof(List_node));
    if (no != NULL) {
        no->info = it;
        procura_lista(lista, it, &ant, &inutil);
        no->next = ant->next;
        ant->next = no;
    }
}

List pesquisa_lista(List lista, double it){
    List ant;
    List actual;
    procura_lista (lista, it, &ant, &actual);
    return (actual);
}

void imprime_lista (List lista){
    List l = lista->next;
    while (l)
    {
        printf("%lf ", l->info);
        l=l->next;
    }
}

void imprime_contrario (List lista){
    if (lista->next == NULL)
        printf ("%lf ", lista->info);
    else {
        imprime_contrario (lista->next);
        printf("%lf ", lista->info);
    }
}

void imprime_lista_inverte(List lista){
    imprime_contrario(lista->next);
}

