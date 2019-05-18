#include "Funcoes Favs.h"
#include "../Linked Lists/Favs Lists.h"
#include "../Linked Lists/Locais Fav Lists.h"
#include "../Linked Lists/PDI Favs Lists.h"
#include "../Funcoes/Funcoes Locais-Pdi.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define txtr "registo.txt"
#define txtf "favs.txt"

void carrega_lista_hot(Lista_Favs fav){
    FILE *f;
    f=fopen(txtf,"r");
    Lista_Favs aux;
    char s;
    char str[1000],nome[100],hot[20],pdifav[500],lfav[100];
    int flagl=1,flagp=1;
    s=fgetc(f);
    if(s!=EOF){
        do{
            if(s=='\n'){//nos paragrafos o fgetc vai ler o \n por isso adicionamos este caso para ser possivel ler o caracter desejado, ou seja, o <
                s=fgetc(f);
            }
            fscanf(f,"%[^\n]\n",str); //vai ler ate encontrar \n
            if(s=='<'){
                sscanf(str,"%[^\n]",nome);
                insere_lista_favs(fav,nome);
            }
            else if(s=='>'){
                flagl=flagp=1;
            }
            else if(s=='-') {
                sscanf(str, "%[^\n]\n", hot);
                aux = pesquisa_lista_favs(fav, nome);
                aux->hot = cria_lista_hot(hot);
            }
            if(s=='*'){
                sscanf(str,"%[^\n]\n",lfav);
                aux=pesquisa_lista_favs(fav,nome);//vai por no aux a posição do ponteiro com o nome do local para ser possivel criar la dentro a lista de pdis
                if(flagl==1){//serve para ver se ja existe uma linked list para o local
                    aux->lfav=cria_lista_lfavs(lfav);
                    flagl=0;
                }
                else {
                    insere_lista_lfavs(aux->lfav,lfav);
                }
            }
            else if(s=='/') {
                sscanf(str,"%[^\n]\n",pdifav);
                aux=pesquisa_lista_favs(fav,nome);//vai por no aux a posição do ponteiro com o nome do local para ser possivel criar la dentro a lista de pdis
                if(flagp==1){//serve para ver se ja existe uma linked list para o local
                    aux->pfav=cria_lista_pdifavs(pdifav);
                    flagp=0;
                }
                else {
                    insere_lista_pdifavs(aux->pfav,pdifav);
                }
            }
            s=fgetc(f);
        }while(s !=EOF);
    }
}

void write_fav(Lista_Favs favs){
    FILE *f;
    f=fopen(txtf,"w");
    while(favs->next!=NULL){
        favs=favs->next;
        fputs("<",f);
        fputs(favs->user,f);
        fputs("\n",f);
        if(favs->hot!=NULL ) {//pois qnd se elimina o ponto hot poe tudo a 0s
            fputs("-",f);
            fputs(favs->hot->hot, f);
            fputs("\n", f);
        }
        if(favs->pfav!=NULL) {
            while (favs->pfav!= NULL) {
                fputs("/", f);
                fputs(favs->pfav->nome_pdi, f);
                fputs("\n", f);
                favs->pfav=favs->pfav->next;
            }
        }
        if(favs->lfav!=NULL) {
            while (favs->lfav != NULL) {
                fputs("*", f);
                fputs(favs->lfav->nome_lfav, f);
                fputs("\n", f);
                favs->lfav=favs->lfav->next;
            }
        }
        fputs(">\n",f);
    }
}

void load_names(Lista_Favs fav){
    FILE *f;
    int count,i,flag=1;
    char string[50],name[15];
    char* ptr;
    f=fopen(txtr,"r");
    while(fgets(string,100,f)!=NULL){
        ptr=string;
        count=0;
        flag=1;
        memset(name,0,15);
        for(i=0;*(ptr+i)!='\n';i++){
            if(*(ptr+i)!=' '){//adiciona letra a letra ao vetor
                name[count]=*(ptr+i);
                count++;
            }
            else if(*(ptr+i)==' '){
                if(flag==1){
                    insere_lista_favs(fav,name);
                }
                flag=0;
            }
        }
    }
}

void addhot(Lista_Favs fav,Lista_Locais loc,char* user,Lista_Favs pesq) {
    char ponto[50];
    int flag=1;
    int len;
    Lista_PDI aux,aux1;
    if(pesq->hot!=NULL && pesq->hot->hot[0]!='\0'){//verifica se ja nao ha nenhum ponto hot
        printf("Não pode adicionar mais nenhum ponto hot, visto que já tem 1.\n");
        flag=0;
    }
    else {
        printf("Que ponto quer adicionar?");
        fgets(ponto, 50, stdin);
        len = strlen(ponto);
        ponto[len - 1] = '\0';
        while (loc->next != NULL) {
            loc = loc->next;//Isto pois o 1º node da lista esta a branco
            aux1 = loc->pontos;//aux1 fica com a linked list dos pdis
            aux = pesquisa_lista_pdi(aux1, ponto);//vai procurar na linked list dos pdis pelo nome do pdi hot q o user deu
            if (aux != NULL) {
                insere_hot_favs(fav, ponto, user);//insere
                printf("Ponto Adicionado com sucesso.\n");
                flag=0;
            }
        }
    }
    if(flag==1){
        printf("Houve um erro ao adicionar o PDI Hot, verifique que adicionou um PDI que existe listado.\n");
    }
}//ver aqui a linked list Hot

void remhot(Lista_Favs fav,Lista_Favs pesq){
    fav=pesq;
    if(fav->hot!=NULL) {
        fav->hot = NULL;
    }
    else{
        printf("Não tem nenhum ponto hot.\n");
    }
}

void addpfav(Lista_Locais loc,Lista_Favs pesq){
    char ponto[50];
    int flag=1;
    int len;
    Lista_PDI aux,aux1,pesqaux;
    printf("Que ponto quer adicionar?");
    fgets(ponto, 50, stdin);
    len = strlen(ponto);
    ponto[len - 1] = '\0';
    while (loc->next != NULL) {
        loc = loc->next;//Isto pois o 1º node da lista esta a branco
        aux1 = loc->pontos;//aux1 fica com a linked list dos pdis
        aux = pesquisa_lista_pdi(aux1, ponto);//vai procurar na linked list dos pdis pelo nome do pdi hot q o user deu
        if (aux != NULL) {
            if(pesq->pfav==NULL){
                pesq->pfav=cria_lista_pdifavs(ponto);
            }
            else {
                insere_lista_pdifavs(pesq->pfav, ponto);//insere
            }
            printf("Ponto Adicionado com sucesso.\n");
            flag=0;
            pesqaux=pesquisa_lista_pdi(loc->pontos,ponto);
            pesqaux->pop++;
        }

    }
    if(flag==1){
        printf("Houve um erro ao adicionar o PDI Hot, verifique que adicionou um PDI que existe listado.\n");
    }
}

void rempfav(Lista_Favs fav,Lista_Favs pesq,Lista_Locais loc){
    char ponto[50];
    int len;
    Lista_PDI_Favs aux1;
    Lista_PDI pdipesq;
    Lista_Locais aux=loc;
    if(pesq->pfav!=NULL) {//se nao tiver da NULL se ja tiver segue pelo if
        print_pdifav(pesq->pfav);
        printf("Que ponto quer remover?\n");
        fgets(ponto, 50, stdin);
        len = strlen(ponto);
        ponto[len - 1] = '\0';
        aux1 = pesquisa_lista_pdifav(pesq->pfav, ponto);//vamos usar para ver se o user escreveu um local que tem nos favs
        fav=pesq;
        if (aux1 != NULL) {
            if(aux1==fav->pfav){
                fav->pfav=fav->pfav->next;
                printf("Ponto Retirado com sucesso.\n");
            }
            else {
                elimina_pdifav(fav->pfav, ponto);
                printf("Ponto Retirado com sucesso.\n");
            }
            while(aux!=NULL){//para por-mos a linked list loc no local do ponto para eliminar para podermos retirar 1 a popularidade
                if(aux->pontos!=NULL) {
                    pdipesq = pesquisa_lista_pdi(aux->pontos, ponto);
                    if (pdipesq != NULL) {
                        pdipesq->pop--;
                    }
                }
                aux=aux->next;
            }
        } else {
            printf("Esse ponto nao esta na sua lista de favoritos.\n");
        }
    } else{
        printf("Não tem ainda pdis favoritos.\n");
    }
}

void remlfav(Lista_Favs fav,Lista_Favs pesq,Lista_Locais loc){
    char ponto[50];
    int len;
    Lista_Locais_Favs aux1;
    if(pesq->lfav!=NULL) {//se nao tiver da NULL se ja tiver segue pelo if
        print_locfav(pesq->lfav);
        printf("Que ponto quer remover?\n");
        fgets(ponto, 50, stdin);
        len = strlen(ponto);
        ponto[len - 1] = '\0';
        aux1 = pesquisa_lista_locfav(pesq->lfav, ponto);//vamos usar para ver se o user escreveu um local que tem nos favs
        fav=pesq;
        if (aux1 != NULL) {
            if(aux1==fav->lfav){
                fav->lfav=fav->lfav->next;
                printf("Ponto Retirado com sucesso.\n");
            }
            else {
                elimina_locfav(fav->lfav, ponto);
                printf("Ponto Retirado com sucesso.\n");
            }
            loc=pesquisa_lista_loc(loc,ponto);
            loc->pop--;
        } else {
            printf("Esse ponto nao esta na sua lista de favoritos.\n");
        }
    } else{
        printf("Não tem ainda pdis favoritos.\n");
    }
}

void addlfav(Lista_Locais loc,Lista_Favs pesq){
    char ponto[50];
    int flag=1;
    int len,count=0;
    Lista_Locais aux;
    Lista_Locais_Favs aux1;
    aux1=pesq->lfav;
    while(aux1!=NULL) {
        count++;
        aux1=aux1->next;
    }
    if(count==3) {
        printf("Ja tem o maximo de locais preferidos possiveis.\n");
        flag=0;
    }
    else{
        printf("Que ponto quer adicionar?");
        fgets(ponto, 50, stdin);
        len = strlen(ponto);
        ponto[len - 1] = '\0';
        while (loc->next != NULL) {
            loc = loc->next;//Isto pois o 1º node da lista esta a branco
            aux = pesquisa_lista_loc(loc, ponto);//vai procurar na linked list dos locais pelo nome do pdi hot q o user deu
            if (aux != NULL && flag==1) {
                if (pesq->lfav == NULL) {
                    pesq->lfav = cria_lista_lfavs(ponto);
                }
                else {
                    insere_lista_lfavs(pesq->lfav,ponto);//insere
                }
                loc=pesquisa_lista_loc(loc,ponto);
                loc->pop++;
                printf("Local Adicionado com sucesso.\n");
                flag=0;
            }
        }
    }
    if(flag==1){
        printf("Houve um erro ao adicionar o Local, verifique que adicionou um PDI que existe listado.\n");
    }
}

void rem_add(Lista_Favs  fav,Lista_Locais loc,char* user){
    int n;
    Lista_Favs pesq;
    printf("Escolha uma das opções: \n1-Adicionar PDI Hot\n2-Adicionar PDI Favorito\n3-Adicionar Local Favorito\n4-Remover PDI Hot\n5-Remover PDI Favorito\n6-Remover Local Favorito\n7-Listagem dos seus pontos favoritos\n8-Voltar atras\n");
    scanf("%d",&n);
    getchar();
    pesq=pesquisa_lista_favs(fav,user);
    do{
        if(n==1){
            addhot(fav,loc,user,pesq);
        }
        else if(n==2){
            addpfav(loc,pesq);
        }
        else if(n==3){
            addlfav(loc,pesq);
        }
        else if(n==4){
            remhot(fav,pesq);
        }
        else if(n==5){
            rempfav(fav,pesq,loc);
        }
        else if(n==6){
            remlfav(fav,pesq,loc);
        }
        else if(n==7){
            imprime_hot(pesq->hot);
            print_locfav(pesq->lfav);
            print_pdifav(pesq->pfav);

        }
        else if(n==8){
            break;
        }
        else{
            printf("Escolha uma das opções.\n");
        }
    }while(n<1 || n>8);
}

