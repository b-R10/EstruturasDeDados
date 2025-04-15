#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 10
#define inv -1

typedef int TipoChave;

typedef struct {
  TipoChave chave;
} Registro;

typedef struct {
  Registro vetor[max];
  int tamanho;
} Lista;

Lista* criarLista();

Registro criarRegistro(int chave);

void inicializarLista(Lista *L);

int tamanho(Lista *L);

bool inserirDados(Lista *L, Registro reg, int i);

bool buscaValor(Lista *L, TipoChave ch);

bool removerDados(Lista *L, TipoChave ch);

void percorrerLista(Lista *L);

void reiniciarLista(Lista *L);