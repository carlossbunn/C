#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 100

typedef struct {
  int Item[MAXTAM];
  int Topo;
} TPilha;

void TPilha_Inicio(TPilha *p) { p->Topo = -1; }

int TPilha_Vazia(TPilha *p) {
  if (p->Topo == -1)
    return 1;
  else
    return 0;
}
int TPilha_Cheia(TPilha *p) {
  if (p->Topo == MAXTAM - 1)
    return 1;
  else
    return 0;
}
void Tpilha_Insere(TPilha *p, int x) {
  if (TPilha_Cheia(p) == 1)
    printf("Pilha cheia camarao");
  else
    p->Topo++;
  p->Item[p->Topo] = x;
}

int TPilha_Retira(TPilha *p) {
  int aux;
  if (TPilha_Vazia(p) == 1)
    printf("pilha vazia");
  else
    aux = p->Item[p->Topo];
  p->Topo--;
  printf("elemento retirado: %i\n", aux);
  return aux;
}
int main() {
  int numero = 0;
  int aux = 0;
  TPilha *p = (TPilha *)malloc(sizeof(TPilha));
  TPilha_Inicio(p);
  while (1) {
    printf("para inserir 1 /para retirar 2\n");
    scanf("%i", &aux);
    switch (aux) {
    case 1:
      printf("\ndigite um int: ");
      scanf("%i", &numero);
      Tpilha_Insere(p, numero);
      break;
    case 2:
      TPilha_Retira(p);
      break;
    default:
      break;
    }
  }

  return 0;
}