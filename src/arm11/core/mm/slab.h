#ifndef MM_SLAB_H
#define MM_SLAB_H

#include <shared/types.h>

struct slab {
  u32 size;
  u32 first_free;
  bool exhausted;    // True if all entries in the freelist are NULL.
  u32 *objects[512]; // An array of objects. Allocated entries will be marked as
                     // NULL
};

void slab_init(void);
u32 *slab_alloc(int sz);
void slab_free(u32 *ptr, int sz);

#endif // MM_SLAB_H