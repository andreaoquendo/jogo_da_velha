#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jogo.h"


int main(){

    int op, **jogo;
    Jogada vet[9];

    srand(time(NULL));
    jogo=alocaMatriz(3);
    preencheMatriz(3, jogo);

    printf("players: (1 or 2)? ");
    scanf("%d", &op);
    system("cls");

    if(op==1){
        printf("single player");
        system("cls");
        single_player(jogo, vet);
    }
    else if(op==2){
        printf("multiplayer");
    }
    else
        printf("Please, try again later.");

    free(jogo);
    return 0;
}
