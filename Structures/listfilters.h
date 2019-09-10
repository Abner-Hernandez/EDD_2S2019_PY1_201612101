#ifndef LISTFILTERS_H
#define LISTFILTERS_H
#include "nodofilter.h"

class ListFilters
{
public:
    ListFilters();
    NodoFilter *primero;
    void insertar(std::string nameFilter, CubeImage *&filter);
    void graphFilters();
    void guardarArchivo(std::string txtArchivo, std::string postGraph);
};

#endif // LISTFILTERS_H
