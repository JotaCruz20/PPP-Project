#include "Funcoes Registo.h"
#include <stdio.h>
#include <errno.h>
#include "../Linked Lists/Locais Lists.h"
#include "../Linked Lists/Registo Lists.h"
#include "../Linked Lists/PDI Lists.h"
#include <string.h>
#define txtl "locais.txt"
#define txtr "registo.txt"

Lista_Registo ler_fich_registo(Lista_Registo reg){
    FILE *f;
    char nome[50],cidade[20],data[12],telemovel[11],string[100];
    f=fopen(txtr,"r");
    while(fscanf(f,"%[^\n]\n",string)!=EOF){
        sscanf(string,"%[^ ] %[^ ] %[^ ] %[^\n]\n",nome,cidade,data,telemovel);
        insere_lista_reg(reg,nome,cidade,data,telemovel);
    }
    fclose(f);
    return reg;
}

void muda_fich(){
    Lista_Registo registo,aux;
    FILE *f;
    int n,leng;
    char user[50],change[50];
    registo=cria_lista_registo(" "," "," "," ");
    registo=ler_fich_registo(registo);
    f=fopen(txtr,"w");
    printf("Pretende fazer mudanças as informações?\n1-Sim\n2-Nao\n");
    scanf("%d",&n);
    getchar();
    if(n==1){
        do{
            printf("Indique o seu username: ");
            fgets(user,50,stdin);
            leng=strlen(user);
            user[leng-1]='\0';
            aux=pesquisa_lista_reg(registo,user);
            if(aux==NULL){
                printf("O seu username nao existe\n");
            }
        }while(aux==NULL);
        printf("Indique o novo username: \n");
        fgets(change,50,stdin);
        leng=strlen(change);
        change[leng-1]='\0';
        strcpy(aux->nome,change);
        printf("Indique a nova data: \n");
        fgets(change,12,stdin);
        leng=strlen(change);
        change[leng-1]='\0';
        strcpy(aux->data,change);
        printf("Indique a nova cidade: \n");
        fgets(change,20,stdin);
        leng=strlen(change);
        change[leng-1]='\0';
        strcpy(aux->cidade,change);
        printf("Indique o novo numero de telemovel: \n");
        fgets(change,11,stdin);
        leng=strlen(change);
        change[leng-1]='\0';
        strcpy(aux->telemovel,change);

    }
    registo=registo->next;//para nao escrever o espaço em branco
    do{
        fputs(registo->nome,f);
        fputs(" ",f);
        fputs(registo->cidade,f);
        fputs(" ",f);
        fputs(registo->data,f);
        fputs(" ",f);
        fputs(registo->telemovel,f);
        fputs("\n",f);
        registo=registo->next;
    }while(registo!=NULL);
    fclose(f);
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
        for(i=0;*(ptr+i)!='\0';i++){
            if(*(ptr+i)!=' '){//adiciona letra a letra ao vetor
                string[count]=*(ptr+i);
                count++;
            }
            else{
                string[count]='\0';
                if(strcmp(string,name)==0){
                    return 1;
                }
                count=0;//para começar string do 0
            }
        }
    }
    fclose(file);
    return 0;
}

void registo(FILE *file1, FILE *file2){//funcao para o registo
    int len,log;
    char name[50],cid[20],data[12],tele[10];
    if(file1==NULL){
        printf("Erro %s", strerror(errno));
    }
    do {
        printf("Indique: username-\n");//Nome
        fgets(name, 50, stdin);
        len = strlen(name);
        name[len - 1] = '\0';//Tirar o paragrafo
        log=logtester(name);//Para confirmar que nao existe um user com o mesmo username
        if(log!=0){
            printf("\nO username ja esta em uso, use outro.\n");
        }
    }while(log!=0);
    fputs(name, file1);//Inserir no ficheiro
    fputs(" ", file1);//Adicionar espaço
    printf("Indique: cidade-\n");//Cidade
    fgets(cid, 20, stdin);
    len = strlen(cid);
    cid[len - 1] = '\0';
    fputs(cid, file1);
    fputs(" ", file1);
    printf("Indique: data de nascimento-\n");//Data nascimento
    fgets(data, 12, stdin);
    len = strlen(data);
    data[len - 1] = '\0';
    fputs(data, file1);
    fputs(" ", file1);
    printf("Indique: nº telemovel-\n");//Nº telemovel
    fgets(tele, 10, stdin);
    fputs(tele, file1);
    fputs("\n", file1);
}
int login(FILE *file){//funcao para o login
    int len,logf;
    char user[50];
    printf("\nIndique o seu username: ");
    fgets(user,50,stdin);
    len=strlen(user);
    user[len-1]='\0';//tirar o \n da string para se poder comparar
    logf=logtester(user);
    if(logf==1){
        return 1;
    }
    else{
        return 0;
    }
}

