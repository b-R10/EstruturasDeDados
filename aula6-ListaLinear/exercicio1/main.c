#include "lista.h"

int main() {
  int lista[max];
  int quantidadeElementos = 0;

  for (int i = 0; i < 10; ++i)
  {
    if(inserirSemRepetir(lista, i, quantidadeElementos, max)) {
      quantidadeElementos++;
    }
  }

  int a = 7;
  if(inserirSemRepetir(lista, a, quantidadeElementos, max)) {
    quantidadeElementos++;
  }

  a = 11;
  if(inserirSemRepetir(lista, a, quantidadeElementos, max)) {
    quantidadeElementos++;
  }

  percorrer(lista, quantidadeElementos);

  return 0;
}