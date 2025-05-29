#include "lista.h"

int main(){
  no *lista1;

  inicializa(&lista1);

  for (int i = 0; i < 10; ++i){
    insereFinal(&lista1, i);
  }
  
  percorreLista(lista1);
  
  removeFinal(&lista1);
  removeFinal(&lista1);
  
  percorreLista(lista1);

  return 0;
}