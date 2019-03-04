#pragma once
#include "DynArray.h"

#define MAXKEY 1024

typedef struct TkWord
{
    int tkcode;  //单词编码
    struct TkWord *next; //指向哈希冲突的同义词
    char spelling;  //单词字符串
}TkWord;

extern TkWord *tk_hashtable[MAXKEY];
extern DynArray tktable;


int get_hash(char *key);
TkWord *tkword_direct_insert(TkWord *tp);
TkWord *tkword_find(char *p, int hash_key);

