#include <core/mm/slab.h>
#include <lib/libcore/math.h>
#include <lib/print.h>

#define SLABCOUNT 10
#define LARGEST_SLAB 1024 // largest slab is pow(2, SLABCOUNT)
#define NORMAL_FCRAM 0x20000000
#define EXTENDED_FCRAM /* TODO */

static struct slab slabs[SLABCOUNT];

static i32 find_free(int which);
static i32 find_allocated(int which);

void slab_init(void)
{
	u32 fcram = (u32)NORMAL_FCRAM;

	for (int i = 0; i < SLABCOUNT; i++)
	{
		slabs[i].size = pow(2, i + 1);
		slabs[i].first_free = 0;
		slabs[i].exhausted = false;

		int objects_per_slab = LARGEST_SLAB / pow(2, i + 1);
		printv("verbose: %d allocatable objects of size %d", objects_per_slab, slabs[i].size);
		for (int j = 0; j < objects_per_slab; j++, fcram += slabs[i].size)
		{
			slabs[i].objects[j] = (u32*)fcram;
		}
	}
	print("slab: ok");
}

u32 *slab_alloc(int sz)
{
	for (int i = 0; i < SLABCOUNT; i++)
	{
		if (slabs[i].size != sz)
			continue;

		if (slabs[i].exhausted)
			return NULL;
		
		u32 *ret = NULL;

		i32 idx = find_free(i);
		if (idx == -1)
		{
			slabs[i].exhausted = true;
		}
		else
		{
			ret = slabs[i].objects[idx];
			slabs[i].objects[idx] = NULL;
		}
		return ret;
	}
	return NULL;
}

void slab_free(u32 *ptr, int sz)
{
	if (!ptr || sz % 2 != 0)
		return;

	for (int i = 0; i < SLABCOUNT; i++)
	{
		if (slabs[i].size != sz)
			continue;

		i32 idx = find_allocated(i);
		if (idx == -1)
			return;

		slabs[i].objects[idx] = ptr;
	}
}

// Find an allocated object in the objects and return it's index.
// Returns -1 on error.
static i32 find_allocated(int which)
{
	int objects_per_slab = LARGEST_SLAB / pow(2, which + 1);
	for (int i = 0; i < objects_per_slab; i++)
	{
		// Found an allocated object. It doesn't matter whom it belongs to since
		// there is no metadata, and there are no concerns about fragmentation.
		if (slabs[which].objects[i] == NULL)
			return i;
	}

	return -1; // Invalid free(), objects are completely free.
}

static i32 find_free(int which)
{
	int objects_per_slab = LARGEST_SLAB / pow(2, which + 1);
	for (int i = 0; i < objects_per_slab; i++)
	{
		// Found a free object. It doesn't matter whom it belongs to since
		// there is no metadata, and there are no concerns about fragmentation.
		if (slabs[which].objects[i] != NULL)
			return i;
	}

	return -1; // Objects are completely full
}
