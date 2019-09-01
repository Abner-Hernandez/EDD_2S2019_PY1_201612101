#ifndef NODOAB_H
#define NODOAB_H
#include <string>
#include "listlayout.h"

class NodoAB {
public:
    CubeImage *nuevo;
    NodoAB *nIzquierdo;
    NodoAB *nDerecho;
    
    NodoAB();
    NodoAB(CubeImage *&nuevo);
private:

};

#endif /* NODOAB_H */

