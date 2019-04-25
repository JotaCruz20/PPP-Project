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
    fgets(tele,9,stdin);
    fputs(tele,file);
    fputs("\n",file);
}
int login(FILE *file){
    int i,count=0,len;
    char read[100],user[50],string[50];
    char *ptr;
    printf("\nIndique o seu username: ");
    fgets(user,50,stdin);
    len=strlen(user);
    user[len-1]='\0';//tirar o \n da string para se poder comparar
    if(file==NULL){
        printf("Erro %s", strerror(errno));
    }
    fseek(file, 0, SEEK_SET );
    while(fgets(read,100,file)!=NULL){
        ptr=read;
        for(i=0;*(ptr+i)!='\0';i++){
            if(*(ptr+i)!=' '){//adiciona letra a letra ao vetor
                string[count]=*(ptr+i);
                count++;
            }
            else{
                string[count]='\0';
                if(strcmp(string,user)==0){
                    printf("1");
                    return 1;
                }
                count=0;//para começar string do 0
            }
        }
    }
    return 0;
}

int main() {
    int n,log;
    FILE *fra,*frr;
    do {
        printf("Bem Vindo. Indique se quer: 1-Login / 2-Novo registo: ");
        scanf("%d", &n);
        getchar();//Para nao dar conflito com o fgets
    }while(n!=1 && n!=2);
    fra=fopen("/home/hak/Desktop/PPP/Trabalho Final/PPP-Project/registo","a");
    frr=fopen("/home/hak/Desktop/PPP/Trabalho Final/PPP-Project/registo","r");
    if (n == 1){
        log=login(frr);
    }
    else{
        registo(fra);
    }
    while(log==0){
        printf("\nO seu user nao existe, pretende: 1-Criar um / 2-Tentar outra vez: ");
        scanf("%d", &n);
        getchar();
        if(n==1){
            registo(fra);
        }
        else{
            log=login(frr);
        }
    }
}