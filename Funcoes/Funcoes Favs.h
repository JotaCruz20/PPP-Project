#ifndef TRABALHO_FINAL_FUNCOES_FAVS_H
#define TRABALHO_FINAL_FUNCOES_FAVS_H
#include "../Linked Lists/Favs Lists.h"
#include "../Linked Lists/Locais Lists.h"


void rem_add(Lista_Favs fav,Lista_Locais loc,char* user);
void load_names(Lista_Favs fav);
void addhot(Lista_Favs lista,Lista_Locais loc,char* user);
void remhot(Lista_Favs fav,char* user);
void carrega_lista_hot(Lista_Favs fav);
void write_fav(Lista_Favs Favs);
void addpfav(Lista_Favs fav,Lista_Locais loc,char* user);
void rempfav(Lista_Favs fav,Lista_Locais loc,char*user);
void addlfav(Lista_Favs fav,Lista_Locais loc,char* user);

#endif //TRABALHO_FINAL_FUNCOES_FAVS_H
