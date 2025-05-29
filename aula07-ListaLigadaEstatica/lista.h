#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 50
#define inv -1

typedef int TIPOCHAVE;

typedef struct {
  TIPOCHAVE chave;
} REGISTRO;

typedef struct {
  REGISTRO r;
  int proximo;
} ELEMENTO;

typedef struct {
  ELEMENTO v[max];
  int inicio;
  int disponivel;
} LISTA;

void inicializar(LISTA *l);
int tamanho(LISTA *l);
void imprimir(LISTA *l);
int buscar_sequencial_ordenada(LISTA *l, TIPOCHAVE ch);
bool inserir_ordenado(LISTA *l, REGISTRO r);
int obtencao_NO(LISTA *l);
bool excluir(LISTA *l, TIPOCHAVE ch);
void devolver_NO(LISTA *l, int i);
void reiniciar(LISTA *l);