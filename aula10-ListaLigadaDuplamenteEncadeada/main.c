#include "lista.h"

int main(){
  Lista *lista1 = (Lista *)malloc(sizeof(Lista));

  iniciar(lista1);

  printf("tamanho: %d\n", tamanho(lista1));

  Registro reg;
  for(int i=0; i<10; ++i){
    reg.chave = i;
    inserir(lista1, reg);
  }

  imprimir(lista1);

  excluir(lista1, 3);

  imprimir(lista1);

  return 0;
}