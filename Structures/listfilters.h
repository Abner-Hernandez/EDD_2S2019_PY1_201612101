#ifndef LISTFILTERS_H
#define LISTFILTERS_H
#include "nodofilter.h"
#include "listlayout.h"

class ListFilters
{
public:
    ListFilters();
    NodoFilter *primero;
    void insertar(std::string nameFilter, ListLayout *filter);
    void graphFilters();
    void guardarArchivo(std::string txtArchivo, std::string postGraph);
};

#endif // LISTFILTERS_H
