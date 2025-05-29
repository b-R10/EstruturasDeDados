#include "pilha.h"

int main() {
  Pilha *p1 = (Pilha *)malloc(sizeof(Pilha));
  Pilha *p2 = (Pilha *)malloc(sizeof(Pilha));

  inicializa(p1);
  inicializa(p2);

  char palavra[] = "radar";
  int i=0;

  while (palavra[i] != '\0'){
    PUSH(p1, palavra[i]);
    i++;
  }

  imprime(*p1);
  
  i=p1->topo;
  while (i >= 0){
    PUSH(p2, p1->vetor[i]);
    i--;
  }
  
  imprime(*p2);
  
  return 0;
}