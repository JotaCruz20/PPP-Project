#include <stdio.h>
#include <string.h>
#include <errno.h>

void registo(FILE *file){
    int len;
    char name[50],cid[20],data[12],tele[9];
    if(file==NULL){
        printf("Erro %s", strerror(errno));
    }
    printf("Indique: username-\n");//Nome
    fgets(name,50,stdin);
    len=strlen(name);
    name[len-1]='\0';//Tirar o paragrafo
    fputs(name,file);//Inserir no ficheiro
    fputs(" ",file);//Adicionar espaço
    printf("Indique: cidade-\n");//Cidade
    fgets(cid,20,stdin);
    len=strlen(cid);
    cid[len-1]='\0';
    fputs(cid,file);
    fputs(" ",file);
    printf("Indique: data de nascimento-\n");//Data nascimento
    fgets(data,12,stdin);
    len=strlen(data);
    data[len-1]='\0';
    fputs(data,file);
    fputs(" ",file);
    printf("Indique: nº telemovel-\n");//Nº telemovel
    fgets(tele,9,stdin);//Não tiramos pq so queremos a
    fputs(tele,file);
}
void login(FILE *file){
    char read[100],user[50];
    printf("Indique o seu username.");
    fgets(user,50,stdin);
    if(file==NULL){
        printf("Erro %s", strerror(errno));
    }
    while(fgets(read,100,file)!=NULL){
        fscanf(file,"%s", user);

        //if(!strcmp(string, student))==0//if match found
    }
}

int main() {
    int n;
    FILE *fra,*frr;
    do {
        printf("Bem Vindo. Indique se quer: 1-Login / 2-Novo registo: ");
        scanf("%d", &n);
        getchar();//Para nao dar conflito com o fgets
    }while(n!=1 && n!=2);
    fra=fopen("/home/hak/Desktop/PPP/Trabalho Final/registo","a");
    frr=fopen("/home/hak/Desktop/PPP/Trabalho Final/registo","r");
    if (n == 1){
        login(frr);
    }
    else{
        registo(fra);
    }
}