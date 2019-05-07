#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "Funcoes/Funcoes Locais-Pdi.h"
#include "Funcoes/Funcoes Registo.h"
#include "Linked Lists/Locais Lists.h"
#include "Linked Lists/Registo Lists.h"
#include "Linked Lists/PDI Lists.h"

int main() {
    int n,log,len;
    FILE *fra;
    char user[50];
    do {
        printf("Bem Vindo. Indique se quer: 1-Login / 2-Novo registo: ");
        scanf("%d", &n);
        getchar();
    }while(n!=1 && n!=2);
    fra=fopen("registo.txt","a");
    if (n == 1){
        printf("\nIndique o seu username: ");
        fgets(user,50,stdin);
        len=strlen(user);
        user[len-1]='\0';
        log=login(user);
        while(log==0){
            printf("\nO seu user nao existe, pretende: 1-Criar um / 2-Tentar outra vez: ");
            scanf("%d", &n);
            getchar();
            if(n==1){
                registo(fra);
            }
            else{
                printf("\nIndique o seu username: ");
                fgets(user,50,stdin);
                len=strlen(user);
                user[len-1]='\0';
                log=login(user);
            }
        }
    }
    else{
        registo(fra);
    }
    do {
        printf("MENU");
        printf("\nEscolha o que quer fazer:\n1-Alterar dados\n2-Listagem dos Locais e PDIs\n3-Preferencias\n4-Construir Viagem.\n5-Fechar\n");
        scanf("%d", &n);
        getchar();
        if (n==1) {
            muda_fich(user);
        }
        if (n==2) {
            imprime_locais_e_pdis();
            printf("Organizado por Nome,Descrição,Horario(NE significa que Nao Existe");
        }
    }while(n!=5);
}