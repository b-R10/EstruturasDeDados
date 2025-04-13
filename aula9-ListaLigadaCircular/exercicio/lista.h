#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define maxCPF 11

typedef struct {
  char nomeCliente[100];
  char CPF[5];
  int numeroDaConta[5];
  int qtdContas;
  double saldo;
} Registro;

typedef struct AuxElemento {
  Registro r;
  struct AuxElemento *proximo;
} Elemento;

typedef Elemento *PONT;
typedef struct {
  PONT no;
} Lista;

void iniciarLista(Lista *l);

int tamanho(Lista *l);

void imprimirLista(Lista *l);

PONT busca(Lista *l, char cpf[maxCPF]);

PONT buscaAux(Lista *l, char cpf[maxCPF], PONT *anterior);

bool inserirElemento(Lista *l, Registro r);

bool excluirElemento(Lista *l, char cpf[maxCPF]);

void reiniciarLista(Lista *l);