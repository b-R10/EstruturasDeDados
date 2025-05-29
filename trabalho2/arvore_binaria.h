#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Nodo {
  int info;
  struct Nodo* esquerda;
  struct Nodo* direita;
  struct Nodo* pai;
};

typedef struct Nodo* No;

No getNode();
No vazia();
No criaArvore(int chave);

No getEsquerda(No pai);
No getDireita(No pai);

No inserir(No raiz, int chave);
No busca_chave(No raiz, int chave);
No remover(No raiz, int chave);
void preOrdem(No raiz);
void inOrdem(No raiz);
void posOrdem(No raiz);
void preInPosOrdem(No arvore);
No predecessor(No raiz);
No sucessor(No raiz);
No maximo(No raiz);
No minimo(No raiz);