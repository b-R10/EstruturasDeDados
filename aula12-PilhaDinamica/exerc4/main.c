#include "pilha.h"

int main() {
  Pilha *pilha1 = (Pilha*)malloc(sizeof(Pilha));
  Pilha *pilha2 = (Pilha*)malloc(sizeof(Pilha));
  
  iniciar(pilha1);
  iniciar(pilha2);

  Registro reg;
  for(int i=0; i<10; ++i){
    reg.chave = i;
    push(pilha1, reg);
    push(pilha2, reg);
  }

  printf("Iguais: %s", pilhasIguais(pilha1, pilha2) ? "sim" : "nao");

  return 0;
}