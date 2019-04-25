#include <stdio.h>

int main() {
    FILE *f,*fl;
    char p[100],lugar[50];
    f=fopen("/home/hak/Desktop/PPP/Trabalho Final/teste/locais","r");
    fl=fopen("/home/hak/Desktop/PPP/Trabalho Final/teste/teste1", "a");
    while(fgets(p,100,f)!=NULL){
        printf("%s", p);
    }
}