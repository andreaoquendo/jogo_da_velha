#include <stdio.h>
#include <stdlib.h>

typedef struct jogada{

    int x;
    int y;

}Jogada;

void single_player(char **m, Jogada vet[]);
char** alocaMatriz(int tam);
void preencheMatriz(int tam, char **m);
void jogada_player(char **m, Jogada vet[], int *k);
int verifica(Jogada vet[], Jogada ind, int *k);
int win(char **m, int dim, int k);

