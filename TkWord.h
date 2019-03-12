#pragma once
#include <string>
#include "DynArray.h"
#define MAXKEY 1024
using namespace std;

class DynArray;

struct TkWord
{
    int tkcode;  //单词编码
    struct TkWord *next; //指向哈希冲突的同义词
    string spelling;  //单词字符串
};



extern TkWord *tk_hashtable[MAXKEY];
extern DynArray tktable;

int get_hash(string key);
TkWord *tkword_direct_insert(TkWord *tp);
TkWord *tkword_find(const string p, int hash_key);

