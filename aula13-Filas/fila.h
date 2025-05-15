#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define maxsize 10

typedef struct {
  int item[maxsize];
  int ini;
  int fim;
  int cont;
} Fila;

void iniciar(Fila *f);
int isVazia(Fila *f);
int inserir(Fila *f, int x);
int remover(Fila *f);
bool isCheia(Fila *f);
