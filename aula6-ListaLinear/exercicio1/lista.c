#include "lista.h"

int buscaSequencial(int vetor[], int elemento, int tamanho) {
  int i = 0;
  while (i < tamanho) {
    if (elemento == vetor[i]) {
      return i;
    } else {
      i++;
    }
  }
  return inv;
}

bool inserirSemRepetir(int vetor[], int elemento, int quantidadeElementosNoVetor, int quantidadeMaxNoVetor) {
  int i = 0;
  if (inv == buscaSequencial(vetor, elemento, quantidadeElementosNoVetor)) {
    if(quantidadeElementosNoVetor == quantidadeMaxNoVetor) {
      return false;
    }
    vetor[quantidadeElementosNoVetor] = elemento;
    return true;
  } else {
    return false;
  }
}

void percorrer(int vetor[], int tamanho) {
  for (int i = 0; i < tamanho; i++)
  {
    printf("%d", vetor[i]);
  }
  
}