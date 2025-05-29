#include "pilha.h"

int main() {
  Pilha *estacionamento = (Pilha*)malloc(sizeof(Pilha));
  iniciar(estacionamento);

  Carro carros[MAX_CARROS];
  int totalCarros = 0;

  char comando;
  int placa;
  while (scanf(" %c %d", &comando, &placa) == 2) {
    if (comando == 'E') {
      if (tamanho(estacionamento) >= MAX_CARROS) {
        printf("Carro %d chegou: estacionamento cheio\n", placa);
      } else {
        Registro reg;
        reg.chave = placa;
        push(estacionamento, reg);
        carros[totalCarros].placa = placa;
        carros[totalCarros].manobras = 0;
        totalCarros++;
        printf("Carro %d chegou: entrou no estacionamento\n", placa);
      }
    } else if (comando == 'S') {
      Pilha *aux = (Pilha*)malloc(sizeof(Pilha));
      iniciar(aux);
      int manobras = 0;
      int found = 0;
      Registro r;
      while (!isVazia(estacionamento)) {
        pop(estacionamento, &r);
        if (r.chave == placa) {
          found = 1;
          break;
        } else {
          push(aux, r);
          for (int i = 0; i < totalCarros; i++) {
            if (carros[i].placa == r.chave) {
              carros[i].manobras++;
              break;
            }
          }
        }
      }
      while (!isVazia(aux)) {
        pop(aux, &r);
        push(estacionamento, r);
      }
      if (found) {
        int manobrasCarro = 0;
        for (int i = 0; i < totalCarros; i++) {
          if (carros[i].placa == placa) {
            manobrasCarro = carros[i].manobras;
            for (int j = i; j < totalCarros - 1; j++)
              carros[j] = carros[j + 1];
            totalCarros--;
            break;
          }
        }
        printf("Carro %d saiu: foi manobrado %d vezes\n", placa, manobrasCarro);
      } else {
        printf("Carro %d nao esta no estacionamento\n", placa);
      }
    }
  }
  return 0;
}