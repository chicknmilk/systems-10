#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
  char name[100];
  int quantity;
  struct product *next; 
};

void print_product(struct product *p) {
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
  print_product(p);

  if (p -> next != NULL) print_list(p -> next);
}

struct product * insert_front(struct product *p, char *n, int q) {
  struct product *new_product = make_product(n, q);
  new_product -> next = p;
}

struct product * free_list(struct product *p) {
  if (p -> next != NULL) free_list(p -> next);

  printf("freeing %s\n", p -> name);
  free(p);
  return p;
}

int main() {

  struct product *p1 = make_product("potato", 5);
  struct product *p2 = insert_front(p1, "candy", 10);
  struct product *p3 = insert_front(p2, "chicken", 23);

  print_list(p3);
  free_list(p3);

  return 0;
}

