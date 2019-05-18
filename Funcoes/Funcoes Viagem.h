#ifndef TRABALHO_FINAL_FUNCOES_VIAGEM_H
#define TRABALHO_FINAL_FUNCOES_VIAGEM_H
#include "../Linked Lists/Favs Lists.h"
#include "../Linked Lists/Locais Lists.h"

typedef struct pvnode* Lista_PDI_Viagem;
typedef struct pvnode{
    char pdiloc[50];
    Lista_PDI_Viagem next;
}Lista_PDI_Viagem_Node;

typedef struct vnode* Lista_Viagem;
typedef struct vnode{
    char loc[100];
    Lista_PDI_Viagem pdiv;
    Lista_Viagem  next;
}Lista_Viagem_Node;

Lista_Viagem cria_lista_viagem(char* nome);
void insere_lista_viagem(Lista_Viagem viag,char* nome);
Lista_PDI_Viagem cria_pdi_viagem(char* nome);
void insere_pdi_viagem(Lista_PDI_Viagem pdiviag,char* nome);
void fazviagem(Lista_Favs fav,Lista_Locais loc,char* user);
void imprime_lista_viag (Lista_Viagem viagem);
void imprime_pdi_viag (Lista_PDI_Viagem pdiviag);
void procura_lista_pdiviag(Lista_PDI_Viagem pdiViagem,char* nome, Lista_PDI_Viagem *ant, Lista_PDI_Viagem *atual);
Lista_PDI_Viagem pesquisa_lista_pdiviag(Lista_PDI_Viagem list, char* name);
void procura_lista_viag(Lista_Viagem pdiViagem,char* nome, Lista_Viagem *ant, Lista_Viagem *atual);
Lista_Viagem pesquisa_lista_viag(Lista_Viagem list, char* name);
double calc(Lista_Viagem viagem,Lista_Favs fav,Lista_Locais loc);


#endif //TRABALHO_FINAL_FUNCOES_VIAGEM_H
