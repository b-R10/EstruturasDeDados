#include "pilha.h"

void inicializa(Pilha *p){
  p->topo = -1;
}

int tamanho(Pilha p){
  return (p.topo + 1);
}

bool isVazia(Pilha p){
  return (p.topo == -1);
}

TipoChave topo(Pilha p){
  return (p.vetor[p.topo]);
}

bool PUSH(Pilha *p, TipoChave chave){
  if(p->topo == max-1){
    printf("Lista cheia\n");
    return false;
  } else {
    p->vetor[++p->topo] = chave;
    return true;
  }
}

TipoChave POP(Pilha *p){
  return (p->vetor[p->topo--]);
}

void imprime(Pilha p){
  for (int i = 0; i < p.topo+1; ++i)
    printf("%c ", p.vetor[i]);
  printf("\n");
}