#ifndef NORM_MEMORY_HEADER
#define NORM_MEMORY_HEADER

#include <stdlib.h>

#define new(a,b,c) (b *)alloc(a, sizeof(b), _Alignof(b), c)

typedef struct
{
  char *beginning;
  char *end;
} arena_t;

arena_t mkarena(ptrdiff_t);
void *alloc(arena_t *, ptrdiff_t, ptrdiff_t, ptrdiff_t);

#endif
