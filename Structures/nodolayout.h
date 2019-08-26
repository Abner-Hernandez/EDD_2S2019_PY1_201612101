#ifndef NODOLAYOUT_H
#define NODOLAYOUT_H
#include <string>
#include "matriz.h"

class NodoLayout
{
public:
    NodoLayout();
    NodoLayout *next, *previous;
    int numLayout;
    Matriz *layout;
    std::string nameLayout;
    NodoLayout(int numLay, std::string nameLay);
    NodoLayout(int numLay, std::string nameLay, Matriz *& lay);
};

#endif // NODOLAYOUT_H
