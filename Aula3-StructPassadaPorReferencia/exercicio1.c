#include <stdio.h>

typedef struct {
  char *nome;
  char *situacao;
  float saldo;
} conta;

int main() {
  conta cliente;
  
  return 0;
}

void funcao(char nome, float saldo) {}

void funcao2(conta *cliente) {
  if (cliente->saldo >= 1000) {
    cliente->situacao = "PREFERENCIAL";
    cliente->saldo *= 1.1;
  } else {
    cliente->situacao = "CONVENCIONAL";
  }
}

void funcao3(conta *cliente) {
  printf("nome: %s", cliente->nome);
  printf("situacao: %s", cliente->situacao);
  printf("saldo: %f", cliente->saldo);
}