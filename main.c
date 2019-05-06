#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "Funcoes/Funcoes Locais-Pdi.h"
#include "Funcoes/Funcoes Registo.h"
#include "Linked Lists/Locais Lists.h"
#include "Linked Lists/Registo Lists.h"
#include "Linked Lists/PDI Lists.h"

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
    getchar();
    printf("MENU");
    printf("\nEscolha o que quer fazer:\n1-Alterar dados\n2-Listagem dos Locais e PDIs\n3-Preferencias\n4-Construir Viagem.");
    if(n==1){
        muda_fich();
    }
    if(n==2){
        imprime_locais_e_pdis();
    }
}