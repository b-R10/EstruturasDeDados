#include "pilha.h"

int main() {
  Pilha *pilha1 = (Pilha *)malloc(sizeof(Pilha));

  iniciar(pilha1);

  printf("%s\n", isVazia(pilha1) ? "true" : "false");

  printf("tamanho: %d\n", tamanho(pilha1));

  Registro reg;
  for(int i=0; i<10; ++i){
    reg.chave = i;
    push(pilha1, reg);
  }

  imprimir(pilha1);
  
  pop(pilha1, &reg);
  
  imprimir(pilha1);

  reiniciar(pilha1);
  
  return 0;
}