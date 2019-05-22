#ifndef TRABALHO_FINAL_REGISTO_LISTS_H
#define TRABALHO_FINAL_REGISTO_LISTS_H

typedef struct data{
    int dia;
    int mes;
    int ano;
}data;

typedef struct rnode* Lista_Registo;//linked list pata guardar o Registo dos users
typedef struct rnode{
    char nome[50];
    char cidade[50];
    data date;
    char telemovel[9];
    Lista_Registo next;
}List_Registo_node;

Lista_Registo cria_lista_registo(char* nome,int dia,int mes,int ano,char* morada,char* telemovel);
void insere_lista_reg (Lista_Registo reg,char* nome,int dia,int mes,int ano,char* morada,char* telemovel);
void procura_lista_reg (Lista_Registo reg,char* user, Lista_Registo *ant, Lista_Registo *atual);
Lista_Registo pesquisa_lista_reg(Lista_Registo reg, char* user);


#endif //TRABALHO_FINAL_REGISTO_LISTS_H
