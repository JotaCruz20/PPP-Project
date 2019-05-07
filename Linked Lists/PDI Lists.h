#ifndef TRABALHO_FINAL_PDI_LISTS_H
#define TRABALHO_FINAL_PDI_LISTS_H

typedef struct pnode* Lista_PDI;
typedef struct pnode{
    char nome[100];
    char descricao[500];
    char horario[20];
    Lista_PDI next;
}Lista_PDI_node;

Lista_PDI cria_lista_pdi(char* nome, char* horario, char* descricao );
void insere_lista_pdi (Lista_PDI pdi,char *nome, char* horario, char* descricao );
void imprime_lista_pdi (Lista_PDI pdi);
void sort_pdi(Lista_PDI pdi);

#endif //TRABALHO_FINAL_PDI_LISTS_H
