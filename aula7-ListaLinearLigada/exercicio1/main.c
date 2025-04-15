#include "lista.h"

int main() {
  Lista lista;
  iniciarLista(&lista);

  Aluno a1 = {"Breno", 1234, {"Matematica", "Fisica"}, 2};
  Aluno a2 = {"Maria", 5678, {"Biologia", "Matematica"}, 2};
  Aluno a3 = {"Pedro", 9101, {"Matematica"}, 1};

  inserirAluno(&lista, a1);
  inserirAluno(&lista, a2);
  inserirAluno(&lista, a3);

  printf("Todos os alunos:\n");
  listarAluno(&lista);

  printf("\nBuscando alunos da disciplina 'matematica':\n");
  buscarPorDisciplina(&lista, "Matematica");
  
  return 0;
}