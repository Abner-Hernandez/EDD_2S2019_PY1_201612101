#ifndef NODO_H
#define NODO_H
#include <string>

class Nodo
{
public:
    Nodo();
    Nodo(std::string nameNodo);
    Nodo *next, *previous;
    std::string nameNodo;
};

#endif // NODO_H
