#ifndef PEDRO_GIT_PROJECTS_GO_FLAVORED_C_DATA_STRUCTURES_SLICE_H
#define PEDRO_GIT_PROJECTS_GO_FLAVORED_C_DATA_STRUCTURES_SLICE_H

#include <stddef.h>

typedef struct {
  void *array;
  size_t len;
  size_t cap;
  size_t el_size;
} Slice;

Slice *make(size_t len, size_t cap, size_t el_size);
void destroy(Slice *s);
void *get(Slice *s, size_t index);

#endif
