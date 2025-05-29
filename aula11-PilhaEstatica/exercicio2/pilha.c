#include "pilha.h"

void inicializa(Pilha *p){
  p->topo = -1;
}

void reinicializa(Pilha *p){
  p->topo = -1;
}

int tamanho(Pilha p){
  return (p.topo + 1);
}

bool isVazia(Pilha p){
  return (p.topo == -1);
}

TipoChave topo(Pilha p){
  return (p.item[p.topo].chave);
}

bool PUSH(Pilha *p, TipoItem item){
  if (p->topo == max - 1){
    printf("Pilha cheia\n");
    return false;
  } else {
    p->item[++p->topo] = item;
    return true;
  }
}

TipoItem POP(Pilha *p){
  return (p->item[p->topo--]);
}

void imprime(Pilha p){
  printf("Pilha:\n");
  for (int i = 0; i < p.topo+1; ++i) {
    printf("%d\n", p.item[i].chave);
  }
}