#include "listcircularde.h"

ListCircularDE::ListCircularDE()
{
    this->primero = nullptr;
}

void ListCircularDE::insertar(std::string nameNodo)
{
    Nodo *nuevo = new Nodo(nameNodo);

    if(this->primero == nullptr)
    {
        this->primero = nuevo;
        this->primero->next = this->primero;
        this->primero->previous = this->primero;
    }
    else
    {
        if(this->primero->next == this->primero)
        {
            this->primero->next = nuevo;
            this->primero->previous = nuevo;
            nuevo->next = this->primero;
            nuevo->previous = this->primero;
        }else
        {
            nuevo->previous = this->primero->previous;
            this->primero->previous->next = nuevo;
            nuevo->next = this->primero;
            this->primero->previous = nuevo;
        }

    }
}
