#include "nodo.h"

Nodo::Nodo()
{
    this->next = nullptr;
    this->previous = nullptr;
    this->nameNodo = "";
}

Nodo::Nodo(std::string nameNodo)
{
    this->next = nullptr;
    this->previous = nullptr;
    this->nameNodo = nameNodo;
}
