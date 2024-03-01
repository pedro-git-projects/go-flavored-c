#include "data_structures/slice.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  Slice *s = make(5, 10, sizeof(int));
  if (s == NULL) {
    fprintf(stderr, "failed to create slice \n");
    return EXIT_FAILURE;
  }

  int *arr = (int *)s->array;
  for (size_t i = 0; i < s->len; i++) {
    arr[i] = i + 1;
  }

  puts("Slice elements:");
  for (size_t i = 0; i < s->len; i++) {
    int *current_el = (int *)get(s, i);
    printf("%d", *current_el);
  }

  destroy(s);
}
