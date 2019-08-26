#include "nodofilter.h"

NodoFilter::NodoFilter()
{
    this->next = nullptr;
    this->previous = nullptr;
    this->filter = new ListLayout();
    this->nameFilter = "";
}

NodoFilter::NodoFilter(ListLayout *filter, std::string nameFilter)
{
    this->filter = filter;
    this->next = nullptr;
    this->previous = nullptr;
    this->nameFilter = nameFilter;
}
