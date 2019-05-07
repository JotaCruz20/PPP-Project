#include "Funcoes Locais-Pdi.h"
#include <stdio.h>
#include "../Linked Lists/Locais Lists.h"
#include "../Linked Lists/Registo Lists.h"
#include "../Linked Lists/PDI Lists.h"
#include <string.h>
#define txtl "locais.txt"
#define txtr "registo.txt"

void imprime_locais_e_pdis() {
    FILE *f;
    Lista_Locais aux;
    char s;
    char str[1000],nome[100],horario[20],descricao[500],local[100];
    int flag=1;
    f=fopen(txtl,"r");
    Lista_Locais loc=cria_lista_locais(" ");//cria uma lista de locais sem nada
    s=fgetc(f);
    do{
        if(s=='\n'){//nos paragrafos o fgetc vai ler o \n por isso adicionamos este caso para ser possivel ler o caracter desejado, ou seja, o <
            s=fgetc(f);
        }
        fscanf(f,"%[^\n]\n",str); //vai ler ate encontrar \n
        if(s=='<'){
            sscanf(str,"%[^:]",local);
            insere_lista_loc(loc,local);
        }
        else if(s=='>'){
            flag=1;

        }
        else if(s=='-'){
            sscanf(str,"%[^;];%[^;];%[^\n]\n",nome,horario,descricao);//separar por ; e ultimo \n
            aux=pesquisa_lista_loc(loc,local);//vai por no aux a posição do ponteiro com o nome do local para ser possivel criar la dentro a lista de pdis
            if(flag==1){//serve para ver se ja existe uma linked list para o local
                aux->pontos=cria_lista_pdi(nome,horario,descricao);
                flag=0;
            }
            else {
                insere_lista_pdi(aux->pontos, nome, horario, descricao);
            }
        }
        s=fgetc(f);
    }while(s !=EOF);
    sort_loc(loc);
    imprime_lista_loc(loc);
    fclose(f);
}