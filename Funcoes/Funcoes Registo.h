#ifndef TRABALHO_FINAL_FUNCOES_REGISTO_H
#define TRABALHO_FINAL_FUNCOES_REGISTO_H
#include "../Linked Lists/Registo Lists.h"
#include "../Linked Lists/PDI Lists.h"
#include "../Linked Lists/Locais Lists.h"
#include <stdio.h>

Lista_Registo ler_fich_registo(Lista_Registo reg);
void muda_fich(char *name,Lista_Favs fav,Lista_Registo reg);
int logtester(char* name,Lista_Registo reg);
void registo(Lista_Registo reg,char* user);
int login(char* user,Lista_Registo reg);
void write_reg(Lista_Registo reg);
int lista_vazia_reg(Lista_Registo reg);
Lista_Registo destroi_reg(Lista_Registo reg);

#endif //TRABALHO_FINAL_FUNCOES_REGISTO_H
