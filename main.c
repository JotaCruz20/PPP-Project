#include <stdio.h>
#include <string.h>
#include <errno.h>

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


int main() {
    int n,log;
    FILE *fra,*frr;
    do {
        printf("Bem Vindo. Indique se quer: 1-Login / 2-Novo registo: ");
        scanf("%d", &n);
        getchar();//Para nao dar conflito com o fgets
    }while(n!=1 && n!=2);
    fra=fopen("registo.txt","a");
    frr=fopen("registo.txt","r");
    if (n == 1){
        log=login(frr);
    }
    else{
        registo(fra,frr);
    }
    while(log==0){
        printf("\nO seu user nao existe, pretende: 1-Criar um / 2-Tentar outra vez: ");
        scanf("%d", &n);
        getchar();
        if(n==1){
            registo(fra,frr);
        }
        else{
            log=login(frr);
        }
    }
    printf("MENU");
    printf("\nEscolha o que quer fazer:\n1-Alterar dados\n2-Listagem dos Locais e PDIs\n3-Preferencias\n4-Construir Viagem.");
}