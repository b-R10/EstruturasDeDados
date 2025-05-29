#include "lista1.h"

int main(){
  Lista *lista = (Lista *)malloc(sizeof(Lista));

  inicializar(lista);

  printf("tamanho: %d\n", tamanho(lista));
  
  REGISTRO reg;
  for(int i=0; i<10; ++i){
    reg.chave = i;
    inserir(lista, reg);
  }
  
  imprimir(lista);
  
  excluir(lista, 3);
  
  printf("tamanho: %d\n", tamanho(lista));
  
  imprimir(lista);
  
  return 0;
}