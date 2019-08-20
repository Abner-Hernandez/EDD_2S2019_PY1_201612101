#ifndef LISTLAYOUT_H
#define LISTLAYOUT_H
#include "nodolayout.h"

class ListLayout
{
public:
    ListLayout();
    NodoLayout *primero;
    void insertar(int numLay, std::string nameLay);
};

#endif // LISTLAYOUT_H
