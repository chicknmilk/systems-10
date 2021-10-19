#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "products.h"

void print_product(struct product *p) {
  if (p == NULL) return;
  printf("%d %s in stock\n", p -> quantity, p -> name);
}

struct product * make_product(char *n, int q) {
  struct product *p = malloc(sizeof(struct product));

  strncpy(p -> name, n, sizeof(p -> name));
  p -> quantity = q;
  p -> next = NULL;

  return p;
}

void print_list(struct product *p) {
  if (p == NULL) {
    printf("empty list\n");
    return;
  }

  print_product(p);

  if (p -> next != NULL) print_list(p -> next);
}

struct product * insert_front(struct product *p, char *n, int q) {
  if (p == NULL) return;
  struct product *new_product = make_product(n, q);
  new_product -> next = p;

  return new_product;
}

struct product * free_list(struct product *p) {
  if (p == NULL) return;
  if (p -> next != NULL) free_list(p -> next);

  printf("freeing %s\n", p -> name);
  free(p);
  return p;
}

struct product * remove_product(struct product *front, char *n, int q) {
  if (front == NULL || front -> next == NULL) return front;

  if (strcmp(front -> next -> name, n) == 0 && front -> next -> quantity == q) {
    struct product * hold = front -> next -> next;
    free(front -> next);

    front -> next = hold;
  }
  else remove_product(front -> next, n, q);

  return front;
}