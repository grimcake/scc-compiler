#include "DynArray.h"
#include <cstdlib>
#include <iostream>

using namespace std;


DynArray::DynArray()
{

}

DynArray::~DynArray()
{

}

void DynArray::add_token(TkWord *p)
{
    data.push_back(p);
}

