#ifndef NODOMATRIZ_H
#define NODOMATRIZ_H
#include <string>

class NodoMatriz
{
public:
    NodoMatriz();
    NodoMatriz(int x, int y , int r, int g, int b);
    NodoMatriz *up;
    NodoMatriz *down;
    NodoMatriz *next;
    NodoMatriz *previous;
    int x;
    int y;
    int r;
    int g;
    int b;
};

#endif // NODOMATRIZ_H
