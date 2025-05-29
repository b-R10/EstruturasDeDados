#include "lista.h"

void inicializa(no **l){
  *l = NULL;
}

void percorreLista(no *l){
  no *p = l;
  printf("Lista\n");
  while(p != NULL){
    printf(" %d\n ", p->info);
    p = p->link;
  }
}

void insereFinal(no **l, int valor){
  no *n = (no *)malloc(sizeof(no));;
  no *p;
  n->info = valor;
  if(*l == NULL)
    *l = n;
  else {
    p = *l;
    while(p->link != NULL)
      p = p->link;
    p->link = n;
  }
  n->link = NULL;
}

void removeFinal(no **l){
  if(l != NULL) {
    if((*l)->link == NULL){
      free(*l);
      *l = NULL;
    } else {
      no *p = *l;
      no *ant = NULL;
      while(p->link != NULL){
        p = p->link;
        ant = ant->link;
      }
      ant->link = NULL;
      free(p);
    }
  }
}