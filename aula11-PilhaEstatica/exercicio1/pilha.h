#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define max 100

typedef struct {
  char dados[max];
  int topo;
} Pilha;

void inicializar(Pilha *p);
int isVazia(Pilha *p);
int isCheia(Pilha *p);
void PUSH(Pilha *p, char c);
char POP(Pilha *p);
void inverterPalavras(char *entrada, char *saida, Pilha *p);