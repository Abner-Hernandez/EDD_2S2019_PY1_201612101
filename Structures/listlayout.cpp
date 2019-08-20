#include "listlayout.h"

ListLayout::ListLayout()
{
    this->primero = nullptr;
}

void ListLayout::insertar(int numLay, std::string nameLay)
{
    NodoLayout *nuevo = new NodoLayout(numLay, nameLay);

    if(this->primero == nullptr)
        this->primero = nuevo;
    else
    {
        NodoLayout *aux = this->primero;
        do
        {
            if(numLay < aux->numLayout && aux != this->primero)
            {
                aux->previous->next = nuevo;
                nuevo->previous = aux->previous;
                nuevo->next = aux;
                aux->previous = nuevo;
                return;
            }
            else if(numLay < aux->numLayout && aux == this->primero)
            {
                nuevo->next = this->primero;
                this->primero->previous = nuevo;
                this->primero = nuevo;
                return;
            }else if(numLay > aux->numLayout && aux->next == this->primero)
            {
                aux->next = nuevo;
                nuevo->previous = aux;
                this->primero->previous = nuevo;
                nuevo->next = this->primero;
            }else if(aux->next == nullptr && numLay > aux->numLayout && aux == this->primero)
            {
                this->primero->next = nuevo;
                nuevo->previous = this->primero;
                nuevo->next = this->primero;
                this->primero->previous = nuevo;

            }
            aux = aux->next;
        }while(aux != this->primero);

    }
}
