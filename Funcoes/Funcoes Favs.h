#ifndef TRABALHO_FINAL_FUNCOES_FAVS_H
#define TRABALHO_FINAL_FUNCOES_FAVS_H
#include "../Linked Lists/Favs Lists.h"
#include "../Linked Lists/Locais Lists.h"


void rem_add(Lista_Favs fav,Lista_Locais loc,char* user);
void load_names(Lista_Favs fav);
void addhot(Lista_Favs lista,Lista_Locais loc,char* user,Lista_Favs pesq);
void remhot(Lista_Favs fav,Lista_Favs pesq);
void carrega_lista_hot(Lista_Favs fav);
void write_fav(Lista_Favs Favs);
void addpfav(Lista_Locais loc,Lista_Favs pesq);
void rempfav(Lista_Favs fav,Lista_Favs pesq,Lista_Locais loc);
void addlfav(Lista_Locais loc,Lista_Favs pesq);
void remlfav(Lista_Favs  fav,Lista_Favs pesq,Lista_Locais loc);

#endif //TRABALHO_FINAL_FUNCOES_FAVS_H
