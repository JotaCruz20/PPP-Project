#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "Funcoes/Funcoes Locais-Pdi.h"
#include "Funcoes/Funcoes Registo.h"
#include "Funcoes/Funcoes Favs.h"
#include "Linked Lists/Locais Lists.h"
#include "Linked Lists/Registo Lists.h"
#include "Linked Lists/PDI Lists.h"
#include "Funcoes/Funcoes Viagem.h"

void menu(char* user,Lista_Favs fav){
    int n;
    Lista_Locais localpha,locpop;
    localpha=cria_lista_locais(" ",0);
    locpop=cria_lista_locais(" ",0);
    carrega_locais_e_pdis_alpha(localpha);
    carrega_locais_e_pdis_pop(locpop);
    do {
        printf("\nMENU");
        printf("\nEscolha o que quer fazer:\n1-Alterar dados\n2-Listagem dos Locais e PDIs\n3-Preferencias\n4-Construir Viagem\n5-Fechar\n");
        scanf("%d", &n);
        getchar();
        if (n==1) {
            muda_fich(user);
        }
        if (n==2) {
            print_locs(localpha,locpop);
        }
        if(n==3){
            rem_add(fav,locpop,user);
        }
        if(n==4){
            fazviagem(fav,locpop,user);
        }
        if(n<1 || n>5){
            printf("Escolha uma das opções.\n");
        }
    }while(n!=5);
    write_fav(fav);
    write_locais(locpop);
}

int main() {
    Lista_Favs fav=cria_lista_favs(" ");
    int n,log,len;
    FILE *fra;
    char user[50];
    printf("Bem Vindo.");
    do {
        printf("Indique se quer: 1-Login / 2-Novo registo: ");
        scanf("%d", &n);
        getchar();
        if(n!=1 && n!=2){
            printf("Escolha uma das opções dadas.\n");
        }
    }while(n!=1 && n!=2);
    fra=fopen("registo.txt","a");
    if (n == 1){
        printf("\nIndique o seu username: ");
        fgets(user,50,stdin);
        len=strlen(user);
        user[len-1]='\0';
        log=login(user);
        if(log==0){
            do{
                printf("\nO seu user nao existe, pretende: 1-Criar um / 2-Tentar outra vez: ");
                scanf("%d", &n);
                getchar();
                if(n==1){
                    registo(fra);
                }
                else if(n==2){
                    printf("\nIndique o seu username: ");
                    fgets(user,50,stdin);
                    len=strlen(user);
                    user[len-1]='\0';
                    log=login(user);
                }
                else{
                    printf("Escolha uma das opções.\n");
                }
            }while(log==0 || n<1 || n>2);
        }
    }
    else{
        registo(fra);
    }
    carrega_lista_hot(fav);
    if(fav->next==NULL){//caso seja a 1º vez q se esteja a usar o programa o ficheiro vai estar em branco e vai dar erro.
        load_names(fav);
    }
    menu(user,fav);
}