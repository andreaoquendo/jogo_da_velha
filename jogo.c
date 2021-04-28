#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct jogada{

    int x;
    int y;

}Jogada;

void imprimeTela(char** m){

    printf(" %c | %c | %c  \n", m[0][0], m[0][1], m[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c  \n", m[1][0], m[1][1], m[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c  \n", m[2][0], m[2][1], m[2][2]);

}

void single_player(char **m, Jogada vet[]){

    int i, flag=1;
    imprimeTela(m);
    for(i=0; i < 9 && flag ; i++){
        if(i%2==0)
            jogada_player(m, vet, &i);
        else
            jogada_pc(m, vet, &i);
        imprimeTela(m);
        flag=win(m, 3, i);
    }

    if(flag){
        printf("\nNinguem ganhou :(");
    }
    else if(i%2==0)
        printf("\Vc ganhou :D");
    else
        printf("\nO PC ganhou D: ");
}

char** alocaMatriz(int tam){

    int **m, i;
    m=(char**)malloc(tam*sizeof(char*));
    for(i=0; i < tam; i++){
        m[i]=(char*)malloc(tam*sizeof(char));
    }

    return m;
}

char* alocaVetor(){

    char *vet;

    vet=(char*)malloc(3*sizeof(char));

    return vet;
}

void preencheMatriz(int tam, char **m){

    int i, j;
    for(i=0; i < tam ; i++){
        for(j=0; j < tam; j++){
            m[i][j]=' ';
        }
    }
}

void jogada_player(char **m, Jogada vet[], int *k){

    Jogada ind, flag;

    printf("\nIt's your turn!");
    printf("\nPosition (i j): ");
    scanf("%d %d", &ind.x, &ind.y);

    while(verifica(vet, ind, k)){
        printf("\nPosicion occupied yet. Try again: ");
        printf("\nPosition (i j): ");
        scanf("%d %d", &ind.x, &ind.y);
    }

    m[ind.x][ind.y]='X';
    vet[*k].x=ind.x;
    vet[*k].y=ind.y;

    system("cls");
}

void jogada_pc(char **m, Jogada vet[], int *k){

    int flag=1;
    Jogada jog;
    printf("It´s pc's turn...\nWait for it...");


    while(flag){
        jog.x=rand()%3;
        jog.y=rand()%3;
        flag=verifica(vet, jog, k);
    }

    m[jog.x][jog.y]='O';
    vet[*k].x=jog.x;
    vet[*k].y=jog.y;
    system("cls");
}

int verifica(Jogada vet[], Jogada ind, int *k){

    int i;
    for(i=0; i < *k; i++){
        if(vet[i].x==ind.x && vet[i].y==ind.y)
            return 1;
    }

    return 0;
}

int win(char **m, int dim, int k){

    int i, j;
    char aux='O';

    if(k%2==1)
        aux='X';

    for(i=0; i < dim; i++){
        if(m[i][0]==aux && m[i][1]==aux && m[i][2]==aux)
            return 0;
    }

    for(i=0; i < dim; i++){
        if(m[0][i]==aux && m[1][i]==aux && m[2][i]==aux)
            return 0;
    }

    if(m[1][1]== aux){
        if(m[0][0]==aux && m[2][2]==aux)
            return 0;
        else if(m[0][2]==aux && m[2][0]==aux)
            return 0;
    }

    return 1;
}


