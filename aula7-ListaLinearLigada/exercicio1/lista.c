#include "lista.h"

void iniciarLista(Lista *L) {
  L->inicio = inv;
  L->disponivel = 0;

  for (int i = 0; i < maxLista-1; i++) {
    L->nos[i].proximo = i+1;
  }
  L->nos[maxLista-1].proximo = -1;
}

bool inserirAluno(Lista *L, Aluno aluno) {
  if(L->disponivel == inv) {
    return false; // lista cheia
  }
  
  int novo = L->disponivel;
  L->disponivel = L->nos[novo].proximo;   // disponivel recebe o proximo do novo

  L->nos[novo].aluno = aluno;
  L->nos[novo].proximo = L->inicio;
  L->inicio = novo;

  return true;
}

void listarAluno(Lista *L) {
  int atual = L->inicio;

  while (atual != inv)
  {
    Aluno *a = &L->nos[atual].aluno;
    printf("Nome: %s\n", a->nome);
    printf("Matricula: %d\n", a->matricula);
    printf("Disciplinas:\n");
    for(int i=0; i < a->qntdDisciplinas; ++i) {
      printf(" - %s\n", a->disciplinas[i]);
    }
    printf("-----------------------\n");
    atual = L->nos[atual].proximo;
  }
}

void buscarPorDisciplina(Lista *L, char *disciplina) {
  int atual = L->inicio;
  int i=0;
  bool encontrado = false;

  while (atual != -1) {
    Aluno *a = &L->nos[atual].aluno;
    for (int i = 0; i < a->qntdDisciplinas; i++) {
      if(strcmp(a->disciplinas[i], disciplina) == 0) {
        printf("Nome: %s | Matricula: %d\n", a->nome, a->matricula);
        encontrado = true;
      }
      atual = L->nos[atual].proximo;
    }
  }
  if(!encontrado) {
    printf("Nenhum aluno encontrado para disciplina %s.", disciplina);
  }
}