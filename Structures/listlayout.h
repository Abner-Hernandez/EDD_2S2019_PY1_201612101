#ifndef LISTLAYOUT_H
#define LISTLAYOUT_H
#include "nodolayout.h"

class ListLayout
{
public:
    void insertar(int numLay, NodoLayout *&nuevo);
    ListLayout();
    NodoLayout *primero;
    void insertar(int numLay, std::string nameLay);
    void insertar(int numLay, std::string nameLay, Matriz *&lay);

};

#endif // LISTLAYOUT_H
