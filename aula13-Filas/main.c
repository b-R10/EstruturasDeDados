#include "fila.h"

int main(){
  Fila *fila1 = (Fila *)malloc(sizeof(Fila));

  iniciar(fila1);
  
  printf("%s\n", isVazia(fila1) ? "true" : "false");
  
  for(int i=0; i<10; ++i){
    inserir(fila1, i);
  }
  
  remover(fila1);
  remover(fila1);
  
  printf("%s\n", isVazia(fila1) ? "true" : "false");
  
  return 0;
}