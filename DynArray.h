#pragma once
#include <vector>
#include "TkWord.h"

using namespace std;

class DynArray
{
public:
	DynArray();
	~DynArray();
	void add_token(TkWord *p);	

    int size;
    vector<TkWord* > data;
};

