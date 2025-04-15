#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 20
#define inv -1

void inicializarLista(int quantidadeElementosNoVetor);

int buscaSequencial(int vetor[], int elemento, int tamanho);

bool inserirSemRepetir(int vetor[], int elemento, int quantidadeElementosNoVetor, int quantidadeMaxNoVetor);

void percorrer(int vetor[], int tamanho);