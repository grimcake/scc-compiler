#include "TkWord.h"
#include <string.h>
class DynArray;
TkWord *tk_hashtable[MAXKEY];
DynArray tktable;

int get_hash(string key)
{
    int h = 0, g;
    for(int i = 0; i<key.size(); i++)
    {
        h = (h<<4)+key[i];
        g = h & 0xf0000000;
        if(g) h^=g>>24;
        h &= ~g;
    }
    return h%MAXKEY;
}

TkWord *tkword_direct_insert(TkWord *tp)
{
    int hash_key;
    hash_key = get_hash(tp->spelling);
    tktable.add_token(tp);
    tp->next = tk_hashtable[hash_key]; //将冲突连成一个链表
    tk_hashtable[hash_key] = tp;
    return tp;
}

TkWord *tkword_find(const string p, int hash_key)
{
    TkWord *tp = 0, *p1;
    for(p1 = tk_hashtable[hash_key]; p1; p1 = p1->next)
    {
        if(p == p1->spelling)
        {
            tp = p1;
        }
    }
    return tp;
}




