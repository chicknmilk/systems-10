#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "products.h"

int main() {

  struct product *list = NULL;

  printf("---empty list---\n");
  print_list(list);


  list = insert_front(list, "potato", 5);
  list = insert_front(list, "candy", 10);
  list = insert_front(list, "chicken", 25);
  list = insert_front(list, "food", 3);

  printf("\n---list of stuff---\n");
  print_list(list);

  printf("\n---removing candy---\n");
  list = remove_product(list, "candy", 10);
  print_list(list);

  printf("\n---removing more potato---\n");
  list = remove_product(list, "potato", 5);
  print_list(list);

  printf("\n---freeing list---\n");
  list = free_list(list);

  printf("\n---print final list after freed---\n");
  print_list(list);

  return 0;
}

