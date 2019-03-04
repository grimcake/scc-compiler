#include "DynArray.h"
#include <cstdlib>
#include <iostream>

using namespace std;
/**************
 * 重新分配内存
***************/
void dynarray_realloc(DynArray *parr, int new_size)
{
    int caplen;
    void **data;

    caplen = parr->caplen;
    while(caplen<new_size)
    {
        caplen *= 2;
    }
    data = (void **)realloc(parr->data, caplen);
    if(!data)
    {
        cout<<"内存分配失败"<<endl;
    }
    parr->caplen = caplen;
    parr->data = data;
}

/************
 * 加入内容
*************/
void dynarray_add(DynArray *parr, void *data)
{
    int size;
    size = parr->size+1;
    if(size*sizeof(void *) > parr->caplen)
    {
        dynarray_realloc(parr, size*sizeof(void *));
    }
    parr->data[size-1] = data;
    parr->size = size;
}
/********
 * 初始化
*********/
void dynarray_init(DynArray *parr, int init_size)
{
    if(parr != NULL)
    {
        parr->data = (void **)malloc(sizeof(char)*init_size);
        parr->size = 0;
        parr->caplen = init_size;
    }
}
/******
 * 清空
******/
void dynarray_free(DynArray *parr)
{
    void **p;
    for(p = parr->data; parr->caplen; ++p, --(parr->size))
    {
        if(*p) free(*p);
    }
    free(parr->data);
    parr->data = NULL;
}
/******
 * 搜索
*******/
int dynarray_search(DynArray *parr, int key)
{
    int **p;
    p = (int **)parr->data;
    for(int i = 0; i<parr->size; ++i, p++)
    {
        if(key == *(*p)) return i;
    }
    return -1;
}

