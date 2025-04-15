#include "lista.h"

Lista* criarLista() {
  Lista *L = (Lista *)malloc(sizeof(Lista));
  return L;
}

Registro criarRegistro(int chave) {
  Registro R;
  R.chave = chave;
  return R;
}

void inicializarLista(Lista *L) {
  L->tamanho = 0;
}

int tamanho(Lista *L) {
  return L->tamanho;
}

bool inserirDados(Lista *L, Registro reg, int i) {
  if ((L->tamanho == max) || (i < 0) || (i > L->tamanho)) {
    return false;
  }
  for (int j = L->tamanho; j > i; --j) {
    L->vetor[j] = L->vetor[j-1];
  }
  L->vetor[i] = reg;
  L->tamanho++;
  return true;
}

bool buscaValor(Lista *L, TipoChave ch) {
  int i=0;
  while (i < L->tamanho) {
    if(ch == L->vetor[i].chave) {
      return i;
    } else {
      i++;
    }
  }
  return inv;
}

bool removerDados(Lista *L, TipoChave ch) {
  int pos = buscaValor(L, ch);
  if(pos == inv)
    return false;
  for (int i = pos; i < L->tamanho; ++i) {
    L->vetor[i] = L->vetor[i+1];
  }
  L->tamanho--;
  return true;
}

void percorrerLista(Lista *L) {
  printf("Lista: ");
  for(int i = 0; i < L->tamanho; ++i) {
    printf("%d ", L->vetor[i].chave);
  }
  printf("\n");
}

void reiniciarLista(Lista *L) {
  L->tamanho = 0;
}