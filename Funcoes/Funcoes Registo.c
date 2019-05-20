#include "Funcoes Registo.h"
#include <stdio.h>
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

void muda_fich(char* user,Lista_Favs fav){
    Lista_Registo registo,aux;
    Lista_Favs pesq;
    FILE *f;
    int leng,log;
    char change[50];
    registo=cria_lista_registo(" "," "," "," ");
    registo=ler_fich_registo(registo);
    aux=pesquisa_lista_reg(registo,user);
    pesq=pesquisa_lista_favs(fav,user);
    do {
        printf("Indique: username-\n");//Nome
        fgets(change, 50, stdin);
        leng = strlen(change);
        change[leng - 1] = '\0';//Tirar o paragrafo
        log=logtester(change);//Para confirmar que nao existe um user com o mesmo username
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
    registo=registo->next;//para nao escrever o espaço em branco
    f=fopen(txtr,"w");
    do{
        fputs(registo->nome,f);
        fputs(";",f);
        fputs(registo->cidade,f);
        fputs(";",f);
        fputs(registo->data,f);
        fputs(";",f);
        fputs(registo->telemovel,f);
        fputs(" \n",f);
        registo=registo->next;
    }while(registo!=NULL);
}

int logtester(char name[50]){//serve para ver se o nome dado existe no file
    FILE *file;
    file=fopen("registo.txt","r");
    char read[100],string[50];
    char *ptr;
    int i,count=0;
    if(file==NULL){
        printf("Erro %s", strerror(errno));
    }
    while(fgets(read,100,file)!=NULL){
        ptr=read;
        count=0;
        memset(string,0,50);
        for(i=0;*(ptr+i)!='\n';i++){
            if(*(ptr+i)!=';'){//adiciona letra a letra ao vetor
                string[count]=*(ptr+i);
                count++;
            }
            else if(*(ptr+i)==';'){
                string[count]='\0';
                count=0;//para começar string do 0
                if(strcmp(string,name)==0){
                    return 1;
                }
                memset(string,0,50);//limpa a string
            }
        }
    }return 0;
}

void registo(FILE *file1){//funcao para o registo
    int len,log;
    char reg[50];
    if(file1==NULL){
        printf("Erro %s", strerror(errno));
    }
    do {
        printf("Indique: username-\n");//Nome
        fgets(reg, 50, stdin);
        len = strlen(reg);
        reg[len - 1] = '\0';//Tirar o paragrafo
        log=logtester(reg);//Para confirmar que nao existe um user com o mesmo username
        if(log!=0){
            printf("\nO username ja esta em uso, use outro.\n");
        }
    }while(log!=0);
    fputs(reg, file1);//Inserir no ficheiro
    fputs(";", file1);//Adicionar espaço
    memset(reg,0,50);
    do {
        printf("Indique: cidade(No maximo 50 chars)-\n");//Cidade
        fgets(reg, 50, stdin);
        len = strlen(reg);
        reg[len - 1] = '\0';
    }while(len>50);
    fputs(reg, file1);
    fputs(";", file1);
    memset(reg,0,50);
    do {
        printf("Indique: data de nascimento(No Maximo 12 chars)-\n");//Data nascimento
        fgets(reg, 50, stdin);
        len = strlen(reg);
        reg[len - 1] = '\0';
    }while(len>12) ;
    fputs(reg,file1);
    fputs(";", file1);
    do {
        printf("Indique: Nº Telemovel(No maximo 9 chars)-\n");//Cidade
        fgets(reg, 50, stdin);
        len = strlen(reg);
        reg[len-1] = '\0';
    }while(len>10);
    fputs(reg, file1);
    fputs("\n", file1);
}

int login(char* user){//funcao para o login
    int logf;
    logf=logtester(user);
    if(logf==1){
        return 1;
    }
    else{
        return 0;
    }
}