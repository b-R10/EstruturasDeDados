#include "pilha.h"

void inicializa(Pilha *p){
  p->topo = -1;
}

int isVazia(Pilha p){
  return (p.topo == -1);
}

int tamanho(Pilha p){
  return (p.topo+1);
}

void imprime(Pilha p){
  printf("Pilha estatica\n");
  if(isVazia(p))
    printf("Vazia");
  else {
    for(int i = p.topo; i>=0; --i)
      printf("%d ", p.item[i].chave);
    printf("\n");
  }
}

void PUSH(Pilha *p, TipoItem x){
  if(p->topo == maxtam-1)
    printf("Pilha cheia\n");
  else {
    p->topo = p->topo + 1;
    p->item[p->topo] = x;
  }
}

void POP(Pilha *p, TipoItem *item){
  if(isVazia(*p))
    printf("Pilha vazia\n");
  else {
    *item = p->item[p->topo];
    p->topo = p->topo - 1 ;
  }
}

void inverte(Pilha *p){
  if(isVazia(*p))
    return;
  
  TipoItem temp[maxtam];
  int i=0;

  while(!isVazia(*p)){
    POP(p, &temp[i]);
    i++;
  }

  for(int j = 0; j < i; j++){
    PUSH(p, temp[j]);
  }
}