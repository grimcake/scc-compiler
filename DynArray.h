#pragma once

typedef struct DynArray
{
    int size;
    int caplen;
    void **data;
}DynArray;

void dynarray_realloc(DynArray *parr, int new_size);
void dynarray_add(DynArray *parr, void *data);
void dynarray_init(DynArray *parr, int init_size);
void dynarray_free(DynArray *parr);
int dynarray_search(DynArray *parr, int key);
