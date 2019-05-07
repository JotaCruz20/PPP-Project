#ifndef TRABALHO_FINAL_FUNCOES_REGISTO_H
#define TRABALHO_FINAL_FUNCOES_REGISTO_H
#include "../Linked Lists/Registo Lists.h"
#include "../Linked Lists/PDI Lists.h"
#include "../Linked Lists/Locais Lists.h"
#include <stdio.h>

Lista_Registo ler_fich_registo(Lista_Registo reg);
void muda_fich(char *name);
int logtester(char name[50]);
void registo(FILE *file1);
int login(char* user);

#endif //TRABALHO_FINAL_FUNCOES_REGISTO_H
