#ifndef MATRIZ_H
#define MATRIZ_H
#include "nodomatriz.h"
#include <stdlib.h>
#include <string>
#include <fstream>

class Matriz
{
    void graficarRecursivo(NodoMatriz*& nodo, std::string &txtArchivo);
public:
    Matriz();
    NodoMatriz *header;
    void add(int x, int y, int r, int g, int b);
    void deleteM(int x, int y);
    void modify(int x, int y, int r, int g, int b);
    void graficar(std::string postGraph);
    void guardarArchivo(std::string txtArchivo, std::string postGraph);
};

#endif // MATRIZ_H
