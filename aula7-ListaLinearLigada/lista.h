#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 50
#define inv -1

typedef int TipoChave;

typedef struct {
  TipoChave chave;
} Registro;

typedef struct {
  Registro r;
  int proximo;
} Elemento;

typedef struct {
  Elemento V[max];
  int inicio;
  int disponivel;
} Lista;