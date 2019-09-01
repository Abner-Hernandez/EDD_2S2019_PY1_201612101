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

#endif // LISTLAYOUT_H
