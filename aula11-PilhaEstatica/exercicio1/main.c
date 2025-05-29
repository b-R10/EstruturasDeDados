#include "pilha.h"

int main(){
  Pilha *p = (Pilha *)malloc(sizeof(Pilha));
  inicializar(p);

  char frase[] = "ESTE EXERCICIO E MUITO FACIL";
  char resultado[max];

  inverterPalavras(frase, resultado, p);

  printf("Original: %s\n", frase);
  printf("Invertido: %s\n", resultado);
  
  return 0;
}