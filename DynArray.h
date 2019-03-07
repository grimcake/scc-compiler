#pragma once
#include <vector>
#include "TkWord.h"

using namesapce sdt;

class DynArray
{
public:
	DynArray();
	~DynArray();
	void add_token();	

    int size;
    vector<TkWord> data;
};

