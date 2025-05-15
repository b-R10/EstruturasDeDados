#include "pilha.h"

void inicializar(Pilha *p) {
  p->topo = -1;
}

int isVazia(Pilha *p) {
  return (p->topo == -1);
}

int isCheia(Pilha *p) {
  return (p->topo == max-1);
}

void PUSH(Pilha *p, char c) {
  if(!isCheia(p)) {
    p->dados[++(p->topo)] = c;
  }
}

char POP(Pilha *p) {
  if(!isVazia(p)) {
    return (p->dados[(p->topo)--]);
  }
  return '\0';
}

void inverterPalavras(char *entrada, char *saida, Pilha *p) {
  int i=0, j=0;
  char c;

  while ((c = entrada[i]) != '\0') {
    if( !isspace(c) ) {
      PUSH(p, c);  // empilha as letras da palavra
    } else {
      while (!isVazia(p)) {
        saida[j++] = POP(p); // desempilha invertendo
      }
      saida[j++] = c; // add espaco
    }
    i++;
  }

  // desempilha a ultima palavra (caso nao tenha espaco no final)
  while (!isVazia(p)) {
    saida[j++] = POP(p);
    saida[j] = '\0';
  }
  
}