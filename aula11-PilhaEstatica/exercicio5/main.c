#include "pilha.h"

int main(){
  char expr1[] = "(())- -(()())- -()()";
  char expr2[] = ")(- - (()(- -))((";

  printf("Expr1: %s -> %s\n", expr1, verificar(expr1) ? "Correto" : "Incorreto");
  printf("Expr2: %s -> %s\n", expr2, verificar(expr2) ? "Correto" : "Incorreto");

  return 0;
}