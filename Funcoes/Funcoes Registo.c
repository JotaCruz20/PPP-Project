#include "Funcoes Registo.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "../Linked Lists/Locais Lists.h"
#include "../Linked Lists/Registo Lists.h"
#include "../Linked Lists/PDI Lists.h"
#include "../Linked Lists/Favs Lists.h"
#include <string.h>
#define txtl "locais.txt"
#define txtr "registo.txt"

Lista_Registo ler_fich_registo(Lista_Registo reg){
    FILE *f;
    char nome[50],cidade[50],data[12],telemovel[11],string[100];
    f=fopen(txtr,"r");
    while(fscanf(f,"%[^\n]\n",string)!=EOF){
        sscanf(string,"%[^;];%[^;];%[^;];%[^\n]\n",nome,cidade,data,telemovel);
        insere_lista_reg(reg,nome,data,cidade,telemovel);
        memset(nome,0,50);
        memset(cidade,0,50);
        memset(data,0,12);
        memset(telemovel,0,11);
        memset(string,0,100);
    }
    return reg;
}

void muda_fich(char* user,Lista_Favs fav,Lista_Registo reg){
    Lista_Registo aux;
    Lista_Favs pesq;
    int leng,log;
    char change[50];
    aux=pesquisa_lista_reg(reg,user);
    pesq=pesquisa_lista_favs(fav,user);
    do {
        printf("Indique: username-\n");//Nome
        fgets(change, 50, stdin);
        leng = strlen(change);
        change[leng - 1] = '\0';//Tirar o paragrafo
        log=logtester(change,reg);//Para confirmar que nao existe um user com o mesmo username
        if(log!=0){
            printf("\nO username ja esta em uso, use outro.\n");
        }
    }while(log!=0);
    if(pesq!=NULL) {
        strcpy(pesq->user, change);
    }
    strcpy(aux->nome,change);
    strcpy(user,change);
    do {
        printf("Indique: data(No maximo 12 chars)-\n");//Cidade
        fgets(change, 50, stdin);
        leng = strlen(change);
        change[leng-1] = '\0';
    }while(leng>12);
    strcpy(aux->data,change);
    do {
        printf("Indique: cidade(No maximo 50 chars)-\n");//Cidade
        fgets(change, 50, stdin);
        leng=strlen(change);
        change[leng - 1] = '\0';
    }while(leng>50);
    strcpy(aux->cidade,change);
    do {
        printf("Indique: Nº Telemovel(No maximo 9 chars)-\n");//Cidade
        fgets(change, 50, stdin);
        leng = strlen(change);
        change[leng-1] = '\0';
    }while(leng>10);
    strcpy(aux->telemovel,change);
}

int logtester(char* name,Lista_Registo reg){//serve para ver se o nome dado existe no file
    Lista_Registo aux=reg;
    while (aux!=NULL) {
        if (strcmp(aux->nome, name) == 0) {
            return 1;
        }
        aux = aux->next;
    }
    return 0;
}

void registo(Lista_Registo reg,char* user){//funcao para o registo
    int len,log;
    char nome[50],cidade[50],data[12],tele[10];
    do {
        printf("Indique: username-\n");//Nome
        fgets(nome, 50, stdin);
        len = strlen(nome);
        nome[len - 1] = '\0';//Tirar o paragrafo
        log=logtester(nome,reg);//Para confirmar que nao existe um user com o mesmo username
        if(log!=0){
            printf("\nO username ja esta em uso, use outro.\n");
        }
    }while(log!=0);
    strcpy(user,nome);
    do {
        printf("Indique: cidade(No maximo 50 chars)-\n");//Cidade
        fgets(cidade,50, stdin);
        len = strlen(cidade);
        cidade[len - 1] = '\0';
    }while(len>50);
    do {
        printf("Indique: data de nascimento(No Maximo 12 chars)-\n");//Data nascimento
        fgets(data, 50, stdin);
        len = strlen(data);
        data[len - 1] = '\0';
    }while(len>12);
    do {
        printf("Indique: Nº Telemovel(No maximo 9 chars)-\n");//Cidade
        fgets(tele, 50, stdin);
        len = strlen(tele);
        tele[len-1] = '\0';
    }while(len>10);

    insere_lista_reg(reg,nome,data,cidade,tele);
}

int login(char* user,Lista_Registo reg){//funcao para o login
    int logf;
    logf=logtester(user,reg);
    if(logf==1){
        return 1;
    }
    else{
        return 0;
    }
}

void write_reg(Lista_Registo reg){
    FILE *f;
    f=fopen(txtr,"w");
    Lista_Registo registo=reg->next;
    do {
        fputs(registo->nome, f);
        fputs(";", f);
        fputs(registo->cidade, f);
        fputs(";", f);
        fputs(registo->data, f);
        fputs(";", f);
        fputs(registo->telemovel, f);
        fputs(" \n", f);
        registo = registo->next;
    }while(registo!=NULL);
}

int lista_vazia(Lista_Registo reg)
{
    return (reg->next == NULL ? 1 : 0);
}

Lista_Registo destroi_reg(Lista_Registo reg) {
    Lista_Registo temp_ptr;
    while (lista_vazia(reg) == 0) {
        temp_ptr = reg;
        reg = reg->next;
        free(temp_ptr);
    }
    free(reg);
    return NULL;
}