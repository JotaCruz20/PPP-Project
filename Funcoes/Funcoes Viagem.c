#include "Funcoes Viagem.h"
#include "../Linked Lists/Locais Lists.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>

Lista_Viagem cria_lista_viagem(char* nome){
    Lista_Viagem aux;
    aux=(Lista_Viagem)malloc(sizeof(struct vnode));
    if (aux!=NULL){//vai criar a lista com os parametros nome,horario e descriçao
        strcpy(aux->loc,nome);
        aux->next=NULL;
    }
    return aux;
}

void insere_lista_viagem(Lista_Viagem viag,char* nome){
    Lista_Viagem aux;
    aux=viag;
    while(aux->next!=NULL){//para encontrar o ultimo aux, para poder adicionar ao fim
        aux=aux->next;
    }
    aux->next=(Lista_Viagem)malloc(sizeof(struct vnode));
    aux = aux->next;
    if (aux!=NULL){
        strcpy(aux->loc,nome);
        aux->next=NULL;
    }
}

Lista_PDI_Viagem cria_pdi_viagem(char* nome){
    Lista_PDI_Viagem aux;
    aux=(Lista_PDI_Viagem)malloc(sizeof(struct pvnode));
    if (aux!=NULL){//vai criar a lista com os parametros nome,horario e descriçao
        strcpy(aux->pdiloc,nome);
        aux->next=NULL;
    }
    return aux;
}

void insere_pdi_viagem(Lista_PDI_Viagem pdiviag,char* nome){
    Lista_PDI_Viagem aux;
    aux=pdiviag;
    while(aux->next!=NULL){//para encontrar o ultimo aux, para poder adicionar ao fim
        aux=aux->next;
    }
    aux->next=(Lista_PDI_Viagem)malloc(sizeof(struct pvnode));
    aux = aux->next;
    if (aux!=NULL){
        strcpy(aux->pdiloc,nome);
        aux->next=NULL;
    }
}

void imprime_pdi_viag (Lista_PDI_Viagem pdiviag){
    Lista_PDI_Viagem aux=pdiviag;
    aux=aux->next;
    while(aux!=NULL){
        printf("%s\n",aux->pdiloc);
        aux=aux->next;
    }
}


void imprime_lista_viag (Lista_Viagem viagem){//serve para imprimir a lista loc
    Lista_Viagem aux=viagem;
    while(aux!=NULL){
        printf("%s\n",aux->loc);//imprime o nome do local
        imprime_pdi_viag(aux->pdiv);//imprime os pdis do local
        printf("\n");
        aux=aux->next;
    }
}

void procura_lista_pdiviag(Lista_PDI_Viagem pdiViagem,char* nome, Lista_PDI_Viagem *ant, Lista_PDI_Viagem *atual){
    *ant=pdiViagem;//ponteiro inicial
    *atual=pdiViagem->next;//ponteiro a apontar para o seguinte
    if(strcmp((*ant)->pdiloc,nome)==0 ){
        *atual=*ant;
    }
    while((*atual)!=NULL && strcmp((*atual)->pdiloc,nome)!=0){//enqtn atual nao for o ultimo e as strings nao forem iguais o ant toma o valor do autal e o atual do seguinte
        *ant=*atual;
        *atual=(*atual)->next;
    }
}

Lista_PDI_Viagem pesquisa_lista_pdiviag(Lista_PDI_Viagem list, char* name){
    Lista_PDI_Viagem ant;
    Lista_PDI_Viagem atual;
    procura_lista_pdiviag(list, name, &ant, &atual);
    return atual;
}

void procura_lista_viag(Lista_Viagem viagem,char* nome, Lista_Viagem *ant, Lista_Viagem *atual){
    *ant=viagem;//ponteiro inicial
    *atual=viagem->next;//ponteiro a apontar para o seguinte
    if(strcmp((*ant)->loc,nome)==0 ){
        *atual=*ant;
    }
    while((*atual)!=NULL && strcmp((*atual)->loc,nome)!=0){//enqtn atual nao for o ultimo e as strings nao forem iguais o ant toma o valor do autal e o atual do seguinte
        *ant=*atual;
        *atual=(*atual)->next;
    }
}

Lista_Viagem pesquisa_lista_viag(Lista_Viagem list, char* name){
    Lista_Viagem ant;
    Lista_Viagem atual;
    procura_lista_viag(list, name, &ant, &atual);
    return atual;
}

double calc(Lista_Viagem viagem,Lista_Favs fav,Lista_Locais loc){
    double countloc=0,counthot=0,countfav=0,countfavtot=0,countuser=0,media;
    Lista_Favs auxfav=fav->next;
    Lista_Locais_Favs auxlfav;
    Lista_Hot auxhot;
    Lista_Locais auxloc;
    Lista_PDI auxp;
    Lista_Viagem pesloc,auxviag,procura=viagem;
    Lista_PDI_Viagem pesq,auxpdi;
    while(auxfav!=NULL){//count para o numero de useres
        countuser++;
        auxfav=auxfav->next;
    }
    auxfav=fav;
    while(auxfav!=NULL) {//count para o nº de useres com pelo menos 1 ponto fav na viagem
        auxlfav=auxfav->lfav;
        while(auxlfav!=NULL) {
            pesloc = pesquisa_lista_viag(procura, auxlfav->nome_lfav);
            if(pesloc!=NULL){
                countloc++;
                break;
            }
            auxlfav=auxlfav->next;
        }
        auxfav = auxfav->next;
    }
    auxfav=fav;
    while(auxfav!=NULL) {//count dos pontos hot
        auxviag = viagem;
        auxhot = auxfav->hot;
        if (auxhot != NULL) {
            while (auxviag != NULL) {
                pesq = pesquisa_lista_pdiviag(auxviag->pdiv, auxhot->hot);
                if (pesq != NULL) {
                    counthot++;
                }
                auxviag = auxviag->next;
            }
        }
        auxfav = auxfav->next;
    }
    auxloc=loc;
    while (auxloc!=NULL){
        auxp=auxloc->pontos;
        while(auxp!=NULL){
            auxviag=viagem;
            while(auxviag!=NULL){
                auxpdi=auxviag->pdiv;
                    pesq=pesquisa_lista_pdiviag(auxpdi,auxp->nome);
                    if(pesq!=NULL){
                        countfav=countfav+auxp->pop;
                }
                auxviag=auxviag->next;
            }
            countfavtot=countfavtot+auxp->pop;
            auxp=auxp->next;
        }
        auxloc=auxloc->next;
    }
    countloc=countloc/countuser;
    counthot=counthot/countuser;
    countfav=countfav/countfavtot;
    media=((countloc+counthot+countfav)/3)*100;
    return media;
}

void fazviagem(Lista_Favs fav,Lista_Locais loc,char* user){
    int count=0,i,flag=1,countpdi;
    char s=EOF;
    double pop;
    Lista_Locais_Favs auxcount,auxpesq;//auxcount usado para counter, auxpesq usado para pesquisa
    Lista_Locais pesq,auxloc=loc;//pesq vai sser usado para a pesquisa do local,auxloc vai ser usado para ficar com a linked list loc
    Lista_Viagem viag,auxadd;//linked list viagem,e onde se vai adicionar os pontos
    Lista_PDI_Viagem auxnull;//vai servir para ver se esta null ou nao
    Lista_Favs pesquser;//pesquser vai por a lista favs no user certo
    Lista_PDI_Favs auxpdi;//auxpdi vai ficar com os pdis favoritos,
    Lista_PDI auxhot,auxpdipesq,auxp,pdipesq;//auxhot serve para ver se existe o ponto hot,auxfav serve para ver se existe os pontos favs
    pesquser=pesquisa_lista_favs(fav,user);//procurar a lista favorita do user
    if(pesquser!=NULL) {
        auxcount = pesquser->lfav;
        while (auxcount != NULL) {//serve para ver e o user ja tem os 3 locais favs
            count++;
            auxcount = auxcount->next;
        }
    }
    if(count==3){
        auxpesq=pesquser->lfav;//pesquisa dos locais
        auxpdi=pesquser->pfav;
        for(i=0;i<3;i++){//serve para fazer para os 3 locais favs
            countpdi=0;
            pesq=pesquisa_lista_loc(loc,auxpesq->nome_lfav);//encontra o local fav
            if(flag==1) {
                viag = cria_lista_viagem(auxpesq->nome_lfav);//cria a linked list viagem caso ainda nao tenha sido criada
                viag->pdiv=cria_pdi_viagem(" ");
                flag=0;
            }
            else{
                insere_lista_viagem(viag,auxpesq->nome_lfav);//insere na linked list viagem caso ja tenha sido criada
                auxadd=pesquisa_lista_viag(viag,auxpesq->nome_lfav);
                auxadd->pdiv=cria_pdi_viagem(" ");
            }
            if(pesquser->hot!=NULL) {
                auxhot = pesquisa_lista_pdi(pesq->pontos,pesquser->hot->hot);//vai ver se o ponot hot do user existe nesse local
            }
            else{
                auxhot=NULL;
            }
            auxadd=pesquisa_lista_viag(viag,auxpesq->nome_lfav);
            if(auxhot!=NULL){//caso exista adiciona ao pdi da viagem
                insere_pdi_viagem(auxadd->pdiv,auxhot->nome);
                countpdi++;
            }
            while(auxloc!=NULL) {
                auxp=auxloc->pontos;
                while(auxp!=NULL) {
                    while (auxpdi != NULL && countpdi != 3) {//vai servir para os pdis favs
                        pdipesq = pesquisa_lista_pdi(auxp, auxpdi->nome_pdi);
                        if (pdipesq != NULL) {
                            insere_pdi_viagem(auxadd->pdiv, auxpdi->nome_pdi);
                            countpdi++;
                        }
                        auxpdi = auxpdi->next;
                    }
                    auxp=auxp->next;
                }
                auxloc=auxloc->next;
            }
            if(countpdi<3){//caso ainda nao estejam 3 pontos na viagem pomos por odem de popoularidade
                auxpdipesq=pesq->pontos;
                while(countpdi<3){
                    auxpdipesq=auxpdipesq->next;
                    auxnull=pesquisa_lista_pdiviag(auxadd->pdiv,auxpdipesq->nome);
                    if(auxnull==NULL) {
                        insere_pdi_viagem(auxadd->pdiv, auxpdipesq->nome);
                        countpdi++;
                    }
                }
            }
            auxpesq=auxpesq->next;
        }
        imprime_lista_viag(viag);
        pop=calc(viag,fav,loc);
        printf("A taxa de popularidade da sua viagem é %lf%%.\n",pop);
        do{
            printf("Quando pretender voltar para o menu inicial clicque em qualquer botão.\n");
            s=getchar();
            getchar();
        }while(s==EOF);
    }
    else{
        printf("Selecione 3 locais favoritos.");
    }
}