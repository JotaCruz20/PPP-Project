#ifndef TRABALHO_FINAL_LINKED_LISTS_H
#define TRABALHO_FINAL_LINKED_LISTS_H

typedef struct {
    char *nome;
    char *descricao;
    char *horario;
}PDI;

typedef struct {
    char *locais;
    PDI pontos;
}locais;

typedef struct lnode* Lista_Locais;//linked list para guardar os locais e PDIS
typedef struct lnode{
    locais lc;
    Lista_Locais next;
}List_Locais;

typedef struct Registo{
    char *nome;
    double telemovel;
    char *hot;
    char *favoritos;
}Registo;

typedef struct rnode* Lista_Registo;//linked list pata guardar o Registo dos users
typedef struct rnode{
    Registo aluno;
    Lista_Registo next;
}List_Registo;


List_Locais cria_lista_locais(void);
List_Registo cria_lista_registo(void);
void insere_lista_reg (List_Registo, Registo aluno);
void insere_lista_loc (List_Locais, locais sitios);
List_Registo pesquisa_lista_reg (List_Registo, Registo aluno);
List_Locais pesquisa_lista_loc (List_Registo, locais sitios);
void imprime_lista_reg (List_Registo);
void imprime_lista_loc (List_Locais);

#endif //TRABALHO_FINAL_LINKED_LISTS_H

