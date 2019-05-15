#ifndef TRABALHO_FINAL_PDI_LISTS_H
#define TRABALHO_FINAL_PDI_LISTS_H

typedef struct pnode* Lista_PDI;
typedef struct pnode{
    char nome[100];
    char descricao[500];
    char horario[20];
    int pop;
    Lista_PDI next;
}Lista_PDI_node;

Lista_PDI cria_lista_pdi(char* nome, char* horario, char* descricao,int n );
void insere_lista_pdi (Lista_PDI pdi,char *nome, char* horario, char* descricao,int n );
void imprime_lista_pdi (Lista_PDI pdi);
void procura_lista_pdi (Lista_PDI loc,char* lnome, Lista_PDI *ant, Lista_PDI *atual);
Lista_PDI pesquisa_lista_pdi(Lista_PDI list, char* name);
void sort_pdi(Lista_PDI pdi);
int lista_vazia_pdi(Lista_PDI loc);
Lista_PDI destroi_pdi(Lista_PDI loc);


#endif //TRABALHO_FINAL_PDI_LISTS_H
