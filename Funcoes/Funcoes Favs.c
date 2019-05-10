#include "Funcoes Favs.h"
#include "../Linked Lists/Favs Lists.h"
#include "../Linked Lists/Locais Fav Lists.h"
#include "../Linked Lists/PDI Favs Lists.h"
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
            else if(s=='-'){
                sscanf(str,"%[^\n]\n",hot);
                aux=pesquisa_lista_favs(fav,nome);
                strcpy(aux->hot,hot);
                memset(hot,0,20);
                }
            else if(s=='*'){
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
                    insere_lista_pdifavs(aux->pfav,lfav);
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
        fputs("-",f);
        fputs(favs->hot,f);
        fputs("\n",f);
        if(favs->pfav!=NULL) {
            while (favs->pfav->next != NULL) {
                fputs("*", f);
                fputs(favs->pfav->nome_pdi, f);
                fputs("\n", f);
            }
        }
        if(favs->lfav!=NULL) {
            while (favs->lfav->next != NULL) {
                fputs("/", f);
                fputs(favs->lfav->nome_lfav, f);
                fputs("\n", f);
            }
        }
        fputs(">",f);
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

void addhot(Lista_Favs fav,Lista_Locais loc,char* user){
    char ponto[50];
    int flag=1;
    int len;
    Lista_PDI aux,aux1;
    Lista_Favs pesquisa;
    pesquisa=pesquisa_lista_favs(fav,user);
    if(pesquisa->hot[0]!='\0'){//verifica se ja nao ha nenhum ponto hot
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
                break;
            }
        }
    }
    if(flag==1){
        printf("Houve um erro ao adicionar o PDI Hot, verifique que adicionou um PDI que existe listado.\n");
    }
    imprime_hot(fav);

}

void remhot(Lista_Favs fav,char* user){
    fav=pesquisa_lista_favs(fav,user);
    memset(fav->hot,0,50);
    imprime_hot(fav);
}

void addpfav(Lista_Favs fav,Lista_Locais loc,char*user){
    char ponto[50];
    int flag=1;
    int len;
    Lista_PDI aux,aux1;
    Lista_Favs pesquisa;
    printf("Que ponto quer adicionar?");
    fgets(ponto, 50, stdin);
    len = strlen(ponto);
    ponto[len - 1] = '\0';
    while (loc->next != NULL) {
        loc = loc->next;//Isto pois o 1º node da lista esta a branco
        aux1 = loc->pontos;//aux1 fica com a linked list dos pdis
        aux = pesquisa_lista_pdi(aux1, ponto);//vai procurar na linked list dos pdis pelo nome do pdi hot q o user deu
        if (aux != NULL) {
            insere_lista_pdifavs(fav->pfav, ponto);
            printf("Ponto Adicionado com sucesso.\n");
            break;
            }
    }
}

void rem_add(Lista_Favs  fav,Lista_Locais loc,char* user){
    int n;
    printf("Escolha uma das opções: \n1-Adicionar PDI Hot\n2-Adicionar PDI Favorito\n3-Adicionar Local Favorito\n4-Remover PDI Hot\n5-Remover PDI Favorito\n6-Remover Local Favorito\n");
    scanf("%d",&n);
    getchar();
    do{
        if(n==1){
            addhot(fav,loc,user);
        }
        if(n==2){
            addpfav(fav,loc,user);
        }
        else if(n==4){
            remhot(fav,user);
        }

    }while(n<1 || n>5);
}