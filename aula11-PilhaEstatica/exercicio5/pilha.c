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

void push(TipoItem x, Pilha *p){
  if(p->topo == MAXTAM-1)
    printf("Pilha cheia");
  else {
    p->topo = p->topo + 1;
    p->item[p->topo] = x;
  }
}

int verificar(char *expressao){
  Pilha *p = (Pilha *)malloc(sizeof(Pilha));
  inicializa(p);
  TipoItem temp;

  for(int i=0; expressao[i] != '\0'; ++i){
    if(expressao[i] == '(') {
      temp.chave = 1;
      push(temp, p);
    } else if(expressao[i] == ')'){
      if(vazia(*p)){
        return 0;
      }
      p->topo--;
    }
  }
  return vazia(*p);
}