#ifndef ARBOLOBB_H
#define ARBOLOBB_H
#include "nodoAB.h"
#include <iostream>
#include "listcircularde.h"

class ArbolBB {
    void insertarNodo(NodoAB *&pivote, NodoAB *&insertar);
    void GuardandoArchivo(std::string txtArchivo, std::string postGraph);
    void arbolbinario(NodoAB *&nodo, std::string &txtArchivo);
    bool deleteNodo(NodoAB *&padre, NodoAB *&pivote, std::string codigo, int lado);
    void graficarInorder(NodoAB *&pivote , std::string &txtArchivo, ListCircularDE *&lista);
    void graficarPostOrden(NodoAB *&pivote , std::string &txtArchivo, ListCircularDE *&lista);
    void graficarPreOrden(NodoAB *&pivote , std::string &txtArchivo, ListCircularDE *& lista);
    void graficarNodesABB(NodoAB *&pivote , std::string &txtArchivo);
    int contImagen;
public:
    ArbolBB();
    NodoAB *Raiz;
    void insertarNodo(CubeImage *&insertar);
    bool eliminarNodo(std::string codigo);
    void graficarArbol();
    void graficarInorder();
    void graficarPostOrden();
    void graficarPreOrden();

private:

};

#endif /* ARBOLOBB_H */

