#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 30

typedef int TIPOCHAVE;

typedef struct {
  TIPOCHAVE chave;
} REGISTRO;

typedef struct {
  REGISTRO V[max];
  int N;
} LISTA;

void inicializar(LISTA *l);
int tamanho(LISTA l);
void imprimir(LISTA l);
int buscar(LISTA *l, REGISTRO r);
bool inserir(LISTA *l, int pos, REGISTRO r);
bool remover(LISTA *l, TIPOCHAVE ch);