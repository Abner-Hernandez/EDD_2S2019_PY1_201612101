#ifndef ARBOLOBB_H
#define ARBOLOBB_H
#include "nodoAB.h"
#include <iostream>
#include "listcircularde.h"

class ArbolBB {
private:
    void insertarNodo(NodoAB *&pivote, NodoAB *&insertar);
    void GuardandoArchivo(std::string txtArchivo, std::string postGraph);
    void arbolbinario(NodoAB *&nodo, std::string &txtArchivo);
    bool deleteNodo(NodoAB *&padre, NodoAB *&pivote, std::string codigo, int lado);
    void graficarInorder(NodoAB *&pivote , std::string &txtArchivo, ListCircularDE *&lista);
    void graficarPostOrden(NodoAB *&pivote , std::string &txtArchivo, ListCircularDE *&lista);
    void graficarPreOrden(NodoAB *&pivote , std::string &txtArchivo, ListCircularDE *& lista);
    void graficarNodesABB(NodoAB *&pivote , std::string &txtArchivo);
    void getImages(NodoAB *&pivote, ListCircularDE*& images);
    void getImage(NodoAB *&pivote, CubeImage*& image, std::string nameImage);
public:
    ArbolBB();
    NodoAB *Raiz;
    void insertarNodo(CubeImage *&insertar);
    bool eliminarNodo(std::string codigo);
    void graficarArbol();
    void graficarInorder();
    void graficarPostOrden();
    void graficarPreOrden();
    void getImages(ListCircularDE*& images);
    void getImage(CubeImage *&image, std::string nameImage);

private:

};

#endif /* ARBOLOBB_H */

