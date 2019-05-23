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
#define txtl "locais.txt"
#define txtf "favs.txt"
#define txtr "registo.txt"

void menu(char* user,Lista_Favs fav,Lista_Registo reg){
    int n;
    char s;
    Lista_Locais localpha,locpop;
    localpha=cria_lista_locais(" ",0);
    locpop=cria_lista_locais(" ",0);
    carrega_locais_e_pdis_alpha(localpha);
    carrega_locais_e_pdis_pop(locpop);
    do {
        do {
            printf("\nMENU\n");
            printf("\nEscolha o que quer fazer:\n1-Alterar dados\n2-Listagem dos Locais e PDIs\n3-Preferencias\n4-Construir Viagem\n5-Fechar\n");
            s=getchar();
            getchar();
            n = verifica_opcao(s, 5);
            if(n==0){
                printf("Escolha uma das opções.\n");
                getchar();
            }
        }while (n==0);
        if (n==1) {
           muda_fich(user,fav,reg);
        }
        else if (n==2) {
            print_locs(localpha,locpop);
        }
        else if(n==3){
            rem_add(fav,locpop,user);
        }
        else if(n==4){
            fazviagem(fav,locpop,user);
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
    FILE *l,*r,*f;
    Lista_Favs fav=cria_lista_favs(" ");
    Lista_Registo regist=cria_lista_registo(" ",0,0,0," "," "),reg;
    Lista_Registo procura;
    reg=ler_fich_registo(regist);
    procura=reg;
    int n,log,len;
    char user[50],num;
    l=fopen(txtl,"r");
    r=fopen(txtr,"r");
    f=fopen(txtf,"r");
    if(l==NULL || r==NULL || f==NULL){//serve para ver se nao ha erros nos ficheiros(se foram bem abertos)
        printf("Error de file: %d. O Programa vai encerrar!!!",errno);
    }
    else {
        printf("Bem Vindo.\n");
        do {
            printf("Indique se quer: 1-Login / 2-Novo registo: \n");
            num=getchar();
            getchar();
            n = verifica_opcao(num, 2);
            if (n != 1 && n != 2) {
                printf("Escolha uma das opções dadas.\n");
                getchar();
            }
        } while (n != 1 && n != 2);
        if (n == 1) {
            printf("\nIndique o seu username: \n");
            fgets(user, 50, stdin);
            len = strlen(user);
            user[len - 1] = '\0';
            log = login(user, procura);
            if (log == 0) {
                do {
                    printf("\nO seu user nao existe, pretende: 1-Criar um / 2-Tentar outra vez: \n");
                    num = getchar();
                    getchar();
                    n = verifica_opcao(num, 2);
                    memset(user,0,50);
                    if (n == 1) {
                        registo(reg, user);
                    } else if (n == 2) {
                        printf("\nIndique o seu username: \n");
                        fgets(user, 50, stdin);
                        len = strlen(user);
                        user[len - 1] = '\0';
                        procura=reg;
                        log = login(user, procura);
                    } else {
                        printf("\nEscolha uma das opções.\n");
                    }
                } while (log == 0 && n!=1 && n!=2);
            }
        } else {
            registo(regist, user);
        }
        carrega_lista_hot(fav);
        if (fav->next ==NULL) {//caso seja a 1º vez q se esteja a usar o programa o ficheiro vai estar em branco e vai dar erro.
            load_names(fav);
        }
        menu(user, fav, reg);
    }
    fclose(f);
    fclose(l);
    fclose(r);
}