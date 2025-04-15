#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 10
#define tamanhoString 20
#define inv -1

typedef char TipoNome;
typedef int TipoConta;
typedef double TipoSaldo;

typedef struct {
  TipoConta conta;
  TipoNome nome[tamanhoString];
  TipoSaldo saldo;
} Registro;

typedef struct {
  Registro Vetor[max];
  int NumeroDeElementos;
} Lista;

void inicializarLista(Lista *L);

int numeroDeElementos(Lista *L);

void imprimirLista(Lista *L);

int BuscaSequencial(Lista *L, TipoConta conta, TipoNome nome[]);

Registro CriarRegistro(TipoConta conta, TipoNome nome[], TipoSaldo saldo);

bool InserirElemento(Lista *L, Registro r, int pos);

bool ExcluirElemento(Lista *L, TipoConta conta, TipoNome nome);

void ReiniciarLista(Lista *L);