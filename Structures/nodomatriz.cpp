#include "nodomatriz.h"

NodoMatriz::NodoMatriz()
{
    this->x = 0;
    this->y = 0;
    this->r = 0;
    this->g = 0;
    this->b = 0;
    this->up = nullptr;
    this->down = nullptr;
    this->next = nullptr;
    this->previous = nullptr;
}

NodoMatriz::NodoMatriz(int x, int y , int r, int g, int b)
{
    this->x = x;
    this->y = y;
    this->r = r;
    this->g = g;
    this->b = b;
    this->up = nullptr;
    this->down = nullptr;
    this->next = nullptr;
    this->previous = nullptr;
}


