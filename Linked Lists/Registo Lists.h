#ifndef TRABALHO_FINAL_REGISTO_LISTS_H
#define TRABALHO_FINAL_REGISTO_LISTS_H

typedef struct rnode* Lista_Registo;//linked list pata guardar o Registo dos users
typedef struct rnode{
    char nome[50];
    char cidade[20];
    char data[12];
    char telemovel[10];
    Lista_Registo next;
}List_Registo_node;

Lista_Registo cria_lista_registo(char* nome,char* data,char* morada,char* telemovel);
void insere_lista_reg (Lista_Registo reg,char* nome,char* data,char* morada,char* telemovel);
void imprime_lista_reg (Lista_Registo reg);
void procura_lista_reg (Lista_Registo reg,char* user, Lista_Registo *ant, Lista_Registo *atual);
Lista_Registo pesquisa_lista_reg(Lista_Registo reg, char* user);

#endif //TRABALHO_FINAL_REGISTO_LISTS_H
