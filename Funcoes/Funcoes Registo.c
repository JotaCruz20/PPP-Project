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

int verifica_opcao(char n,int max){
    int num;
    if(n>33 && n<57){
        num=n-48;
        if(num>=1 && num<=max){
            return num;
        }
    }
    return 0;
}

int verifica_numero(char* num,int len){
    int i;
    for(i=0;i<len-1;i++){
        if(num[i]<48 || num[i]> 58 || num[i]=='\n'){
            return 0;
        }
    }
    return 1;
}

int verifica_data(int n,char* num){
    int date;
    date=atoi(num);
    if(n==0){//serve para dia
        if(date<1 || date>31){
            return 0;
        }
    }
    else if(n==1){//serve para mes
        if(date<1 || date>12){
            return 0;
        }
    }
    return 1;
}

int verifica_especial(char* nome,int len){
    int i;
    for(i=0;i<len-1;i++){
        if((nome[i]!=' ' && nome[i]<65) || (nome[i]>90 && nome[i]<97) || nome[i]>122){
            return 0;
        }
    }
    return 1;
}

Lista_Registo ler_fich_registo(Lista_Registo reg){
    FILE *f;
    char nome[50],cidade[50],data[12],telemovel[11],string[100];
    int dia,ano,mes;
    f=fopen(txtr,"r");
    while(fscanf(f,"%[^\n]\n",string)!=EOF){
        sscanf(string,"%[^;];%[^;];%[^;];%[^\n]\n",nome,cidade,data,telemovel);
        sscanf(data, "%d/%d/%d",&dia,&mes,&ano);
        insere_lista_reg(reg,nome,dia,mes,ano,cidade,telemovel);
        memset(nome,0,50);
        memset(cidade,0,50);
        memset(data,0,12);
        memset(telemovel,0,11);
        memset(string,0,100);
    }
    return reg;
}

void muda_user(Lista_Registo reg,Lista_Favs pesq,char* user){
    char nome[50];
    int len,log,flag;
    Lista_Registo aux=pesquisa_lista_reg(reg,user);
    do {
        do {
            printf("Indique: username-\n");//Nome
            fgets(nome, 50, stdin);
            len = strlen(nome);
            nome[len - 1] = '\0';//Tirar o paragrafo
            flag=verifica_especial(nome,len);
            if(flag==0){
                printf("Erro ao modificar! Escreva um nome sem caracteres especiais.\n");
            }
        }while(flag!=1);
        log = logtester(nome, reg);//Para confirmar que nao existe um user com o mesmo username
        if (log != 0) {
            printf("\nO username ja esta em uso, use outro.\n");
        }
    }while(log!=0);
    if(pesq!=NULL) {
        strcpy(pesq->user, nome);
    }
    strcpy(aux->nome,nome);
    strcpy(user,nome);
    printf("Nome mudado com sucesso!\n");
}

void muda_data(Lista_Registo reg){
    char data[10];
    int dia,mes,ano,len,checkn,checkd;
    printf("Indique: data de nascimento\n");//Data nascimento
    do {
        printf("Indique: dia-\n");
        fgets(data,10,stdin);
        len=strlen(data);
        data[len-1]='\0';
        checkn=verifica_numero(data,len);
        checkd=verifica_data(0,data);
        if(checkn==0 || checkd==0){
            printf("Erro ao modificar! Escreva um dia entre 1 a 31.\n");
        }
    }while(checkn!=1 || checkd!=1);
    dia=atoi(data);
    reg->date.dia=dia;
    do {
        printf("Indique: mes-\n");
        fgets(data,10,stdin);
        len=strlen(data);
        data[len-1]='\0';
        checkn=verifica_numero(data,len);
        checkd=verifica_data(1,data);
        if(checkn==0 || checkd==0){
            printf("Erro ao modificar! Escreva um mes entre 1 a 12.\n");
        }
    }while(checkn!=1 || checkd!=1);
    mes=atoi(data);
    reg->date.mes=mes;
    do {
        printf("Indique: ano-\n");
        fgets(data,10,stdin);
        len=strlen(data);
        data[len-1]='\0';
        checkn=verifica_numero(data,len);
        if(checkn==0){
            printf("Erro ao modificar! Escreva um numero.\n");
        }
    }while(checkn!=1);
    ano=atoi(data);
    reg->date.ano=ano;
    printf("Data Mudada com sucesso!\n");
}

void muda_morada(Lista_Registo reg){
    int flag,len;
    char cidade[50];
    do {
        printf("Indique: cidade(No maximo 50 chars)-\n");//Cidade
        fgets(cidade,50, stdin);
        len = strlen(cidade);
        cidade[len - 1] = '\0';
        flag=verifica_especial(cidade,len);
        if(flag==0){
            printf("Erro ao modificar! Escreva sem caracteres especiais.\n");
        }
    }while(len>50 || flag==0);
   strcpy(reg->cidade,cidade);
   printf("Morada Mudada com Sucesso!\n");
}

void muda_tele(Lista_Registo reg){
    char tele[11];
    int check,len;
    do {
        printf("Indique: Nº Telemovel(9 numeros)-\n");//Cidade
        fgets(tele, 11, stdin);
        len = strlen(tele);
        tele[len-1] = '\0';
        check=verifica_numero(tele,len);
        if(check==0){
            printf("Erro ao modificar! Escreva so numeros e 9 algarismos.\n");
        }
    }while(len!=10 || check!=1);
    strcpy(reg->telemovel,tele);
    printf("Telemovel Mudado com Sucesso!\n");
}

void muda_fich(char* user,Lista_Favs fav,Lista_Registo reg) {
    Lista_Registo aux;
    Lista_Favs pesq;
    char num;
    int n;
    aux = pesquisa_lista_reg(reg, user);
    pesq = pesquisa_lista_favs(fav, user);
    do {
        do {
            printf("Indique o que pretende mudar:\n1-User\n2-Cidade\n3-Data\n4-Telemovel\n5-Sair\n ");
            num=getchar();
            getchar();
            n = verifica_opcao(num, 5);
            if(n==0){
                printf("Escolha uma das opções.\n");
                getchar();
            }
        }while(n==0);
        if (n == 1) {
            muda_user(reg, pesq, user);
        } else if (n == 2) {
            muda_morada(aux);
        } else if (n == 3) {
            muda_data(aux);
        } else if(n==4){
            muda_tele(aux);
        }else if(n==5){
            break;
        }
    }while(n<1 || n>5);
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
    int len,log,checkn,checkd,checke,dia,mes,ano;
    char nome[50],cidade[50],data[11],tele[20];
    do {
        do {
            printf("Indique: username-\n");//Nome
            fgets(nome, 50, stdin);
            len = strlen(nome);
            nome[len - 1] = '\0';//Tirar o paragrafo
            checke=verifica_especial(nome,len);
            if(checke==0){
                printf("Erro ao registar o nome! Escreva um nome sem caracteres especiais.\n");
            }
        }while(checke!=1);
        log = logtester(nome, reg);//Para confirmar que nao existe um user com o mesmo username
        if (log != 0) {
            printf("\nO username ja esta em uso, use outro.\n");
        }
    }while(log!=0);
    strcpy(user,nome);
    do {
        printf("Indique: cidade(No maximo 50 chars)-\n");//Cidade
        fgets(cidade,50, stdin);
        len = strlen(cidade);
        cidade[len - 1] = '\0';
        checke=verifica_especial(cidade,len);
        if(checke==0){
            printf("Erro ao registar a cidade! Escreva um nome sem caracteres especiais.\n");
        }
    }while(len>50 || checke==0);
    printf("Indique: data de nascimento\n");//Data nascimento
    do {
        printf("Indique: dia-\n");
        fgets(data,11,stdin);
        len=strlen(data);
        data[len-1]='\0';
        checkn=verifica_numero(data,len);
        checkd=verifica_data(0,data);
        if(checkn==0 || checkd==0){
            printf("Erro ao registar o dia! Insira um dia entre 1 a 31.\n");
        }
    }while(checkn!=1 || checkd!=1);
    dia=atoi(data);
    do {
        printf("Indique: mes-\n");
        fgets(data,11,stdin);
        len=strlen(data);
        data[len-1]='\0';
        checkn=verifica_numero(data,len);
        checkd=verifica_data(1,data);
        if(checkn==0 || checkd==0){
            printf("Erro ao registar o dia! Insira um mes entre 1 a 12.\n");
        }
    }while(checkn!=1 || checkd!=1);
    mes=atoi(data);
    do {
        printf("Indique: ano-\n");
        fgets(data,11,stdin);
        len=strlen(data);
        data[len-1]='\0';
        checkn=verifica_numero(data,len);
        if(checkn==0){
            printf("Erro ao registar o ano! Insira um numero.\n");
        }
    }while(checkn!=1);
    ano=atoi(data);
    do {
        printf("Indique: Nº Telemovel(9 numeros)-\n");//Cidade
        fgets(tele, 20, stdin);
        len = strlen(tele);
        tele[len-1] = '\0';
        checkn=verifica_numero(tele,len);
        if(checkn==0){
            printf("Erro ao registar o telemovel! Insira um numero.\n");
        }
    }while(len!=10 || checkn!=1);
    insere_lista_reg(reg,nome,dia,mes,ano,cidade,tele);
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
        fprintf(f,"%d",registo->date.dia);
        fputs("/",f);
        fprintf(f,"%d",registo->date.mes);
        fputs("/",f);
        fprintf(f,"%d",registo->date.ano);
        fputs(";", f);
        fputs(registo->telemovel, f);
        fputs(" \n", f);
        registo = registo->next;
    }while(registo!=NULL);
}

int lista_vazia_reg(Lista_Registo reg)
{
    return (reg->next == NULL ? 1 : 0);
}

Lista_Registo destroi_reg(Lista_Registo reg) {
    Lista_Registo temp_ptr;
    while (lista_vazia_reg(reg) == 0) {
        temp_ptr = reg;
        reg = reg->next;
        free(temp_ptr);
    }
    free(reg);
    return NULL;
}