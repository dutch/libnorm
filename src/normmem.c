#include <normmem.h>
#include <string.h>

arena_t
mkarena(ptrdiff_t capacity)
{
  arena_t arena;

  arena.beginning = malloc(capacity);
  arena.end = arena.beginning ? arena.beginning + capacity : 0;

  return arena;
}

void *
alloc(arena_t *parena, ptrdiff_t size, ptrdiff_t align, ptrdiff_t count)
{
  ptrdiff_t padding, available;
  void *p;

  padding = -(uintptr_t)parena->beginning & (align - 1);
  available = parena->end - parena->beginning - padding;

  if (available < 0 || count > available / size)
    exit(EXIT_FAILURE);

  p = parena->beginning + padding;
  parena->beginning += padding + count * size;

  return memset(p, 0, count * size);
}
