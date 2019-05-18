#include "Funcoes Locais-Pdi.h"
#include <stdio.h>
#include <stdlib.h>
#include "../Linked Lists/Locais Lists.h"
#include "../Linked Lists/Registo Lists.h"
#include "../Linked Lists/PDI Lists.h"
#include <string.h>
#define txtl "locais.txt"
#define txtr "registo.txt"

void carrega_locais_e_pdis_alpha(Lista_Locais loc) {
    FILE *f;
    Lista_Locais aux;
    char s;
    char str[1000],nome[100],horario[20],descricao[500],local[100],num[100];
    int n;
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
            insere_lista_loc_alpha(loc,local,n);
            aux=pesquisa_lista_loc(loc,local);
            aux->pontos=cria_lista_pdi(" "," "," ",0);
        }
        else if(s=='-'){
            sscanf(str,"%[^;];%[^;];%[^;];%[^\n]\n",nome,horario,descricao,num);//separar por ; e ultimo \n
            n=atoi(num);
            aux=pesquisa_lista_loc(loc,local);//vai por no aux a posição do ponteiro com o nome do local para ser possivel criar la dentro a lista de pdis
            insere_lista_pdi_alpha(aux->pontos, nome, horario, descricao,n);

        }
        s=fgetc(f);
    }while(s !=EOF);
    fclose(f);
}

void carrega_locais_e_pdis_pop(Lista_Locais loc){
    FILE *f;
    Lista_Locais aux;
    char s;
    char str[1000],nome[100],horario[20],descricao[500],local[100],num[100];
    int n;
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
            insere_lista_loc_pop(loc,local,n);
            aux=pesquisa_lista_loc(loc,local);
            aux->pontos=cria_lista_pdi(" "," "," ",0);
        }
        else if(s=='-'){
            sscanf(str,"%[^;];%[^;];%[^;];%[^\n]\n",nome,horario,descricao,num);//separar por ; e ultimo \n
            n=atoi(num);
            aux=pesquisa_lista_loc(loc,local);//vai por no aux a posição do ponteiro com o nome do local para ser possivel criar la dentro a lista de pdis
            insere_lista_pdi_pop(aux->pontos, nome, horario, descricao,n);
        }
        s=fgetc(f);
    }while(s !=EOF);
    fclose(f);
}

void print_locs(Lista_Locais local,Lista_Locais locpop){
    int n;
    do {
        printf("1-Organizado por ordem alfabetica\n2-Organizado por popularidade\n3-Voltar atras\n");
        scanf("%d",&n);
        if (n == 1) {
            imprime_lista_loc(local);
            printf("Organizado por Nome,Descrição,Horario(NE significa que Nao Existe)\n");
        }
        else if(n==2){
            imprime_lista_loc(locpop);
            printf("Organizado por Nome,Descrição,Horario(NE significa que Nao Existe)\n");
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
    Lista_Locais aux=loc;
    Lista_PDI pdiaux;
    f=fopen(txtl,"w");
    while(aux->next!=NULL){
        aux=aux->next;
        fputs("<",f);
        fputs(aux->nome_local,f);
        fputs(";",f);
        fprintf(f,"%d",aux->pop);
        fputs(":\n",f);
        pdiaux=aux->pontos->next;
        if(pdiaux!=NULL ) {//pois qnd se elimina o ponto hot poe tudo a 0
            while (pdiaux!=NULL) {
                fputs("-", f);
                fputs(pdiaux->nome, f);
                fputs(";", f);
                fputs(pdiaux->horario, f);
                fputs(";", f);
                fputs(pdiaux->descricao, f);
                fputs(";", f);
                fprintf(f,"%d",pdiaux->pop);
                fputs("\n", f);
                pdiaux=pdiaux->next;
            }
        }
        fputs(">\n",f);
    }
    fclose(f);
}
