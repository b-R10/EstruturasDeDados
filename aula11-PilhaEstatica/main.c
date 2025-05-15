#include "pilha.h"

int main(){
  Pilha *pilha1 = (Pilha *)malloc(sizeof(Pilha));

  inicializa(pilha1);
  
  Tipoitem item;
  for(int i=0; i<10; ++i){
    item.chave = i;
    push(item, pilha1);
  }

  imprime(*pilha1);
  
  item.chave = 3;
  pop(pilha1, &item);
  
  imprime(*pilha1);
  
  return 0;
}