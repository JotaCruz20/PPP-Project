#include "Funcoes Locais-Pdi.h"
#include <stdio.h>
#include <stdlib.h>
#include "../Linked Lists/Locais Lists.h"
#include "../Linked Lists/Registo Lists.h"
#include "../Linked Lists/PDI Lists.h"
#include <string.h>
#define txtl "locais.txt"
#define txtr "registo.txt"

void carrega_locais_e_pdis(Lista_Locais loc) {
    FILE *f;
    Lista_Locais aux;
    char s;
    char str[1000],nome[100],horario[20],descricao[500],local[100],num[100];
    int flag=1,n;
    f=fopen(txtl,"r");
    s=fgetc(f);
    do{
        if(s=='\n'){//nos paragrafos o fgetc vai ler o \n por isso adicionamos este caso para ser possivel ler o caracter desejado, ou seja, o <
            s=fgetc(f);
        }
        fscanf(f,"%[^\n]\n",str); //vai ler ate encontrar \n
        if(s=='<'){
            sscanf(str,"%[^;];%[^:]:",local,num);
            n=atoi(num);
            insere_lista_loc(loc,local,n);
        }
        else if(s=='>'){
            flag=1;

        }
        else if(s=='-'){
            sscanf(str,"%[^;];%[^;];%[^;];%[^\n]\n",nome,horario,descricao,num);//separar por ; e ultimo \n
            n=atoi(num);
            aux=pesquisa_lista_loc(loc,local);//vai por no aux a posição do ponteiro com o nome do local para ser possivel criar la dentro a lista de pdis
            if(flag==1){//serve para ver se ja existe uma linked list para o local
                aux->pontos=cria_lista_pdi(nome,horario,descricao,n);
                flag=0;
            }
            else {
                insere_lista_pdi(aux->pontos, nome, horario, descricao,n);
            }
        }
        s=fgetc(f);
    }while(s !=EOF);
}

void print_locs(Lista_Locais loc,Lista_Favs fav){
    int n;
    do {
        printf("1-Organizado por ordem alfabetica\n2-Organizado por popularidade\n3-Voltar atras\n");
        scanf("%d",&n);
        if (n == 1) {
            sort_loc(loc);
            imprime_lista_loc(loc);
            printf("Organizado por Nome,Descrição,Horario(NE significa que Nao Existe)\n");
        }
        else if(n==2){
            sort_loc_pref(loc,fav);
        }
        else if(n==3){
            break;
        }
        else{
            printf("Escolha uma das opções.\n");
        }
    }while(n==1 || n==2);
}

void write_locais(Lista_Locais loc){
    FILE *f;
    f=fopen(txtl,"w");
    while(loc->next!=NULL){
        loc=loc->next;
        fputs("<",f);
        fputs(loc->nome_local,f);
        fputs(";",f);
        fprintf(f,"%d",loc->pop);
        fputs(":\n",f);
        if(loc->pontos!=NULL ) {//pois qnd se elimina o ponto hot poe tudo a 0
            while (loc->pontos!=NULL) {
                fputs("-", f);
                fputs(loc->pontos->nome, f);
                fputs(";", f);
                fputs(loc->pontos->horario, f);
                fputs(";", f);
                fputs(loc->pontos->descricao, f);
                fputs(";", f);
                fprintf(f,"%d",loc->pontos->pop);
                fputs("\n", f);
                loc->pontos=loc->pontos->next;
            }
        }
        fputs(">\n",f);
    }
}
