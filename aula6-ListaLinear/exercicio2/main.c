#include "lista.h"

int main() {
  Lista *lista1 = criarLista();
  
  inicializarLista(lista1);

  Registro reg;
  for (int i = 0; i < 10; ++i) {
    reg = criarRegistro(i);
    inserirDados(lista1, reg, i);
  }
  
  removerDados(lista1, 3);

  percorrerLista(lista1);
  
  reiniciarLista(lista1);
  
  percorrerLista(lista1);
  
  return 0;
}