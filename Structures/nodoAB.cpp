#include "nodoAB.h"

NodoAB::NodoAB() {
    this->nuevo = new CubeImage();
    this->nDerecho = nullptr;
    this->nIzquierdo = nullptr;
}

NodoAB::NodoAB(CubeImage *&nuevo) {
    this->nuevo = nuevo;
    this->nDerecho = nullptr;
    this->nIzquierdo = nullptr;
}

