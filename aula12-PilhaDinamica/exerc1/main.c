/*
Desenvolva uma função que transfere os valores de uma pilha P1 para uma pilha P2.
Obs: a pilha P1, ao final da execução da função, deve estar vazia.
*/

#include "pilha.h"

int main(){
  Pilha *pilha1 = (Pilha *)malloc(sizeof(Pilha));
  Pilha *pilha2 = (Pilha *)malloc(sizeof(Pilha));

  iniciar(pilha1);
  iniciar(pilha2);

  Registro reg;
  for(int i=0; i<10; ++i){
    reg.chave = i;
    push(pilha1, reg);
  }

  imprimir(pilha1);

  for(int i=0; i<10; ++i){
    pop(pilha1, &reg);
    push(pilha2, reg);
  }

  imprimir(pilha2);
  
  return 0;
}