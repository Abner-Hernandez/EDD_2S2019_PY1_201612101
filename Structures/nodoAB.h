#ifndef NODOAB_H
#define NODOAB_H
#include <string>
#include "listlayout.h"

struct CubeImage{
    ListLayout *layouts;
    int image_width, image_height, pixel_width, pixel_height;
    std::string imageName, pathImage;
    CubeImage()
    {
        this->layouts = new ListLayout();
        this->image_width = -2;
        this->image_height = -2;
        this->pixel_width = -2;
        this->pixel_height = -2;
        this->imageName = "";
        this->pathImage = "";
    }

};

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

