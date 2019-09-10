#ifndef NODOFILTER_H
#define NODOFILTER_H
#include <string>
#include "listlayout.h"

class NodoFilter
{
public:
    NodoFilter();
    NodoFilter(CubeImage *&Filter, std::string nameFilter);
    std::string nameFilter;
    NodoFilter *next, *previous;
    CubeImage *filter;
};

#endif // NODOFILTER_H
