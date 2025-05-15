#include "pilha.h"

int main(){
  Pilha *pilha1 = (Pilha *)malloc(sizeof(Pilha));

  inicializa(pilha1);

  TipoItem item;
  for(int i=0; i<10; ++i){
    item.chave = i;
    PUSH(pilha1, item);
  }

  imprime(*pilha1);

  inverte(pilha1);

  imprime(*pilha1);

  return 0;
}