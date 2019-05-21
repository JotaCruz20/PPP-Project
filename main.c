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

void menu(char* user,Lista_Favs fav,Lista_Registo reg){
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
           muda_fich(user,fav,reg);
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
    write_reg(reg);
    reg=destroi_reg(reg);
    fav=destroi_fav(fav);
    localpha=destroi_loc(localpha);
    locpop=destroi_loc(locpop);
}

int main() {
    Lista_Favs fav=cria_lista_favs(" ");
    Lista_Registo regist=cria_lista_registo(" ",0,0,0," "," "),reg;
    reg=ler_fich_registo(regist);
    int n,log,len;
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
    if (n == 1){
        printf("\nIndique o seu username: ");
        fgets(user,50,stdin);
        len=strlen(user);
        user[len-1]='\0';
        log=login(user,reg);
        if(log==0){
            do{
                printf("\nO seu user nao existe, pretende: 1-Criar um / 2-Tentar outra vez: ");
                scanf("%d", &n);
                getchar();
                if(n==1){
                    registo(reg,user);
                }
                else if(n==2){
                    printf("\nIndique o seu username: ");
                    fgets(user,50,stdin);
                    len=strlen(user);
                    user[len-1]='\0';
                    log=login(user,reg);
                }
                else{
                    printf("Escolha uma das opções.\n");
                }
            }while(log==0 || n<1 || n>2);
        }
    }
    else{
        registo(regist,user);
    }
    carrega_lista_hot(fav);
    if(fav->next==NULL){//caso seja a 1º vez q se esteja a usar o programa o ficheiro vai estar em branco e vai dar erro.
        load_names(fav);
    }
    menu(user,fav,reg);
}