#include "pilha.h"

int main(){
  Pilha *p1 = (Pilha *)malloc(sizeof(Pilha));

  inicializa(p1);

  printf("tamanho: %d\n", tamanho(*p1));
  
  TipoItem item;
  for (int i = 1; i < 10; ++i){
    item.chave = i;
    PUSH(p1, item);
  }
  
  imprime(*p1);
  
  Pilha *p2 = (Pilha *)malloc(sizeof(Pilha));

  inicializa(p2);
  
  while (!isVazia(*p1))
    PUSH(p2, POP(p1));
  
  imprime(*p2);

  return 0;
}