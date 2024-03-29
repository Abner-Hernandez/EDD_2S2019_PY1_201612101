#include "listfilters.h"

ListFilters::ListFilters()
{
    this->primero = nullptr;
}

void ListFilters::insertar(std::string nameFilter, CubeImage *&filter)
{
    NodoFilter *nuevo = new NodoFilter(filter, nameFilter);

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

void ListFilters::graphFilters()
{
    if(this->primero != nullptr)
    {
        std::string txtArchivo;
        txtArchivo ="";
        txtArchivo += "digraph Mass{\n";
        txtArchivo += "rankdir = LR; \n";
        txtArchivo += "node[shape = rectangle, height = 1, width = 1]; \n";
        txtArchivo += "graph[nodesep = 0.5]; \n";

        NodoFilter *aux = this->primero;
        do
        {
            txtArchivo += aux->nameFilter +"[label= \"X = "+ aux->nameFilter +"\" ];\n";
            aux = aux->next;
        }while(aux != this->primero);

        aux = this->primero;
        do
        {
            if(aux->next != nullptr)
                txtArchivo += aux->nameFilter + " -> " + aux->next->nameFilter + "\n";
            aux = aux->next;
         }while(aux != this->primero);

        txtArchivo += "}";

        guardarArchivo(txtArchivo, "filters");
    }
}

void ListFilters::guardarArchivo(std::string txtArchivo, std::string postGraph)
{
    std::ofstream nuevo;
    nuevo.open("Exports\\filter.dot", std::ofstream::out);
    nuevo << txtArchivo << std::endl;

    nuevo.close();
    system(("dot -Tpng Exports\\filter.dot -o Exports\\grafica"+ postGraph +".png").c_str());
    system(("Exports\\grafica" + postGraph + ".png").c_str());
}
