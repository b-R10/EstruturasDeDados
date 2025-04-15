#include "lista.h"

void inicializarLista(Lista *L) {
  L->NumeroDeElementos = 0;
}

int numeroDeElementos(Lista *L) {
  return L->NumeroDeElementos;
}

void imprimirLista(Lista *L) {
  printf("Lista:\n");
  for (int i = 0; i < L->NumeroDeElementos; ++i) {
    printf("Nome: ");
    for (int j = 0; j < tamanhoString; j++) {
      printf("%c", L->Vetor[i].nome[j]);
    }
    printf("\nConta: %d", L->Vetor[i].conta);
    printf("\nSaldo: %.2f", L->Vetor[i].saldo);
  }
}

int BuscaSequencial(Lista *L, TipoConta conta, TipoNome nome[]) {
  int i=0;
  while (i < L->NumeroDeElementos) {
    if(conta == L->Vetor[i].conta)
      return i;
    i++;
  }
  i=0;
  while (i < L->NumeroDeElementos) {
    for (int j = 0; j < tamanhoString; ++j) {
      if (nome[j] != L->Vetor[i].nome[j])
        return inv;
    }
    i++;
  }
  return inv;
}

Registro CriarRegistro(TipoConta conta, TipoNome nome[], TipoSaldo saldo) {
  Registro R;
  R.conta = conta;
  for(int i=0; i<tamanhoString; ++i) {
    R.nome[i] = nome[i];
  }
  R.saldo = saldo;
  return R;
}

bool InserirElemento(Lista *L, Registro r, int pos) {
  if ((L->NumeroDeElementos == max) || (pos < 0 ) || (pos > L->NumeroDeElementos)) {
    return false;
  }
  for (int i = L->NumeroDeElementos; i > pos; --i) {
    L->Vetor[i] = L->Vetor[i-1];
  }
  L->Vetor[pos] = r;
  L->NumeroDeElementos++;
  return true;
}

bool ExcluirElemento(Lista *L, TipoConta conta, TipoNome nome) {
  int pos = BuscaSequencial(L, conta, nome);
  if (pos != inv) {
    for (int i = pos; i < L->NumeroDeElementos-1; i++) {
      L->Vetor[i] = L->Vetor[i+1];
    }
    L->NumeroDeElementos--;
    return true;
  }
  return false;
}

void ReiniciarLista(Lista *L) {
  L->NumeroDeElementos = 0;
}