struct product {
  char name[100];
  int quantity;
  struct product *next; 
};

void print_product(struct product *p);
struct product * make_product(char *n, int q);
void print_list(struct product *p);
struct product * insert_front(struct product *p, char *n, int q);
struct product * free_list(struct product *p);
struct product * remove_product(struct product *front, char *n, int q);