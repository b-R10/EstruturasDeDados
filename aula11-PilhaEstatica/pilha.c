#include "pilha.h"

void inicializa(Pilha *p){
  p->topo = -1;
}

int vazia(Pilha p){
  return p.topo == -1;
}

int tamanho(Pilha p){
  return p.topo+1;
}

void imprime(Pilha p){
  printf("Pilha estatica\n");
  if(vazia(p))
    printf("Vazia");
  else {
    for (int i = p.topo; i >= 0; --i){
      printf("%d ", p.item[i].chave);
    }
    printf("\n");
  }
}

void push(Tipoitem x, Pilha *p){
  if(p->topo == MAXTAM-1)
    printf("Pilha cheia");
  else {
    p->topo = p->topo + 1;
    p->item[p->topo] = x;
  }
}

void pop(Pilha *p, Tipoitem *item){
  if(vazia(*p))
    printf("Pilha vazia\n");
  else {
    *item = p->item[p->topo];
    p->topo = p->topo - 1;
  }
}