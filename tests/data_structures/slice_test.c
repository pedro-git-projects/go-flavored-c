#include "data_structures/slice.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  Slice *s = make(5, 10, sizeof(int));
  assert(s != NULL);

  int values[] = {1, 2, 3, 4, 5};
  for (size_t i = 0; i < s->len; i++) {
    *((int *)get(s, i)) = values[i];
  }

  for (size_t i = 0; i < s->len; i++) {
    assert(*((int *)get(s, i)) == values[i]);
  }

  assert(get(s, 10) == NULL);

  destroy(s);

  puts("All tests passed!");
  EXIT_SUCCESS;
}
