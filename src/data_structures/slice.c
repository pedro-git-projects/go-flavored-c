#include "data_structures/slice.h"
#include <stdio.h>
#include <stdlib.h>

Slice *make(size_t len, size_t cap, size_t el_size) {
  Slice *s = (Slice *)malloc(sizeof(Slice));
  if (s == NULL) {
    fprintf(stderr, "failed to allocated memory");
    return NULL;
  }

  s->array = malloc(cap * el_size);
  if (s->array == NULL) {
    free(s);
    fprintf(stderr, "failed to allocate memory");
    return NULL;
  }

  s->len = len;
  s->cap = cap;
  s->el_size = el_size;

  return s;
}

void destroy(Slice *s) {
  if (s == NULL) {
    return;
  }

  if (s->array != NULL) {
    free(s->array);
    s->array = NULL;
  }

  free(s);
}

void *get(Slice *s, size_t index) {
  if (index >= s->len) {
    fprintf(stderr, "index out of bounds");
    return NULL;
  }
  return (char *)s->array + index * s->el_size;
}
