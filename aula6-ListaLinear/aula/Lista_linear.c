#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Lista_linear.h"

Lista* criarLista() {
  Lista *L = (Lista *)malloc(sizeof(Lista));
  return L;
}

Registro criarRegistro(int i) {
  Registro R;
  R.chave = i;
  return R;
}

void inicializarLista(Lista *L) {
  L->N = 0;
}

int tamanho(Lista *L) {
  return L->N;
}

void imprimirLista(Lista *L) {
  printf("Lista: ");
  for(int i = 0; i<L->N; ++i)
    printf("%d ", L->V[i].chave);
}

int buscarElemento(Lista *L, TipoChave ch) {
  int i=0;
  while (i < L->N) {
    if (ch == L->V[i].chave) {
      return i;
    } else {
      i++;
    }
  }
  return inv;
}

bool inserirElemento(Lista *L, Registro reg, int i) {
  if ((L->N == max) || (i < 0) || (i > L->N)) {
    return false;
  }
  for (int j = L->N; j > i ; --j) {
    L->V[j] = L->V[j-1];
  }
  L->V[i] = reg;
  L->N++;
  return true;
}

bool removerElemento(Lista *L, TipoChave ch) {
  int pos = buscarElemento(L, ch);
  if (pos == inv) {
    return false;
  }
  for(int i=pos; i < L->N-1; ++i) {
    L->V[i] = L->V[i+1];
  }
  L->N--;
  return true;
}

void reiniciarLista(Lista *L) {
  L->N = 0;
}