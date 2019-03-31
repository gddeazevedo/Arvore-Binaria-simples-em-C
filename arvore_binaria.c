#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Tree {
  int value;
  struct Tree *left, *right;
};

typedef struct Tree Tree;

Tree *tree;


void plant(Tree **tree);
void show_pre_fixed(Tree *aux);
void show_post_fixed(Tree *aux);
void show_central(Tree *aux);


void plant(Tree **tree) {
  int n;

  printf("Digite um numero: ");
  scanf("%d", &n);

  if(n > 0) {
    *tree = (Tree *)malloc(sizeof(Tree));
    (*tree)->value = n;
    plant(&(*tree)->left);
    plant(&(*tree)->right);
  }
  else {
    *tree = (Tree *)NULL;
  }
}

void show_pre_fixed(Tree *aux) {
  if(aux != (Tree *)NULL) {
    printf(" %d ", aux->value);
    show_pre_fixed(aux->left);
    show_pre_fixed(aux->right);
  }
  else {
    printf(" . ");
  }
}

void show_central(Tree *aux) {
  if(aux != (Tree *)NULL) {
    show_central(aux->left);
    printf(" %d ", aux->value);
    show_central(aux->right);
  }
  else {
    printf(" . ");
  }
}

void show_post_fixed(Tree *aux) {
  if(aux != (Tree *)NULL) {
    show_post_fixed(aux->left);
    show_post_fixed(aux->right);
    printf(" %d ", aux->value);
  }
  else {
    printf(" . ");
  }
}

int main() {
  setlocale(LC_ALL, "Portuguese");
  plant(&tree);

  printf("\n\n\nNotação Pré-fixada: ");
  show_pre_fixed(tree);

  printf("\n\n\nNotação Central: ");
  show_central(tree);

  printf("\n\n\nNotação Pós-fixada: ");
  show_post_fixed(tree);

  return 0;
}
