#include "pilha.h"

int main() {
  Pilha *pilha1 = (Pilha*)malloc(sizeof(Pilha));

  iniciar(pilha1);

  Registro reg;
  for(int i=0;i<10;++i){
    reg.chave = i;
    push(pilha1, reg);
  }

  imprimir(pilha1);

  inverter(pilha1);

  imprimir(pilha1);
  
  return 0;
}