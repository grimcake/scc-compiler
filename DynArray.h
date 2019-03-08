#pragma once
#include <vector>

using namespace std;

class TkWord;

class DynArray
{
public:
	DynArray();
	~DynArray();
	void add_token(TkWord *p);	

    int size;
    vector<TkWord* > data;
};

