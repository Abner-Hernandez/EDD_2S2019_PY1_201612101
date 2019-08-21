#include "nodolayout.h"

NodoLayout::NodoLayout()
{
    this->numLayout = 0;
    this->nameLayout = "";
    this->next = nullptr;
    this->previous = nullptr;
    this->layout = new Matriz();
}

NodoLayout::NodoLayout(int numLay, std::string nameLay)
{
    this->numLayout =numLay;
    this->nameLayout = nameLay;
    this->previous = nullptr;
    this->next = nullptr;
    this->layout = new Matriz();
}
