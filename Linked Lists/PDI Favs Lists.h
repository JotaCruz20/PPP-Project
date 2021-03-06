#ifndef TRABALHO_FINAL_PDI_FAVS_LISTS_H
#define TRABALHO_FINAL_PDI_FAVS_LISTS_H

typedef struct pfnode* Lista_PDI_Favs;//linked list para guardar os locais e PDIS
typedef struct pfnode{
    char nome_pdi[100];
    Lista_PDI_Favs next;
}List_PDI_Favs_node;

Lista_PDI_Favs cria_lista_pdifavs(char* pnome);
void insere_lista_pdifavs (Lista_PDI_Favs lista, char* lnome);
void print_pdifav(Lista_PDI_Favs lista);
void procura_lista_pdifav (Lista_PDI_Favs pdi,char* lnome, Lista_PDI_Favs *ant, Lista_PDI_Favs *atual);
Lista_PDI_Favs pesquisa_lista_pdifav(Lista_PDI_Favs list, char* name);
void elimina_pdifav(Lista_PDI_Favs list,char* nome);



#endif //TRABALHO_FINAL_PDI_FAVS_LISTS_H
