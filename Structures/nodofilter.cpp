#include "nodofilter.h"

NodoFilter::NodoFilter()
{
    this->next = nullptr;
    this->previous = nullptr;
    this->nameFilter = "";
}

NodoFilter::NodoFilter(CubeImage *&filter, std::string nameFilter)
{
    this->filter = filter;
    this->next = nullptr;
    this->previous = nullptr;
    this->nameFilter = nameFilter;
}
