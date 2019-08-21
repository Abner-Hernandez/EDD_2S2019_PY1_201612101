#include "matriz.h"

Matriz::Matriz()
{
    this->header = new NodoMatriz();
}

void Matriz::add(int x, int y, int r, int g, int b)
{
    NodoMatriz *insert = new NodoMatriz(x, y, r, g, b);

    if (header->next == nullptr)
    {
        NodoMatriz *xInsert = new NodoMatriz(x, 0, 0, 0, 0);
        xInsert->previous = this->header;
        this->header->next = xInsert;
        //asign node to headerX
        xInsert->down = insert;
        insert->up = xInsert;
    }else
    {
        NodoMatriz *aux = this->header->next;
        while(aux != nullptr)
        {
            if(aux->x > x)
            {
                NodoMatriz *xInsert = new NodoMatriz(x, 0, 0, 0, 0);
                xInsert->previous = aux->previous;
                aux->previous->next = xInsert;
                xInsert->next = aux;
                aux->previous = xInsert;

                //asign node to headerX
                xInsert->down = insert;
                insert->up = xInsert;
                break;
            }else if(aux->x == x)
            {
                NodoMatriz *auxY = aux->down;
                while(auxY != nullptr)
                {
                    if(auxY->y > y)
                    {
                        insert->up = auxY->up;
                        insert->down = auxY;
                        auxY->up->down = insert;
                        auxY->up = insert;
                        break;
                    }else if(auxY->down == nullptr && auxY->y < y)
                    {
                        insert->up = auxY;
                        auxY->down = insert;
                        break;
                    }
                    auxY = auxY->down;
                }
                break;
            }else if(aux->next == nullptr)
            {
                NodoMatriz *xInsert = new NodoMatriz(x, 0, 0, 0, 0);
                aux->next = xInsert;
                xInsert->previous = aux;

                //asign node to headerX
                xInsert->down = insert;
                insert->up = xInsert;
                break;
            }
            aux = aux->next;
        }
    }

    if (header->down == nullptr)
    {
        NodoMatriz *yInsert = new NodoMatriz(0, y, 0, 0, 0);
        yInsert->up = this->header;
        this->header->down = yInsert;
        //asign node to headerX
        yInsert->next = insert;
        insert->previous = yInsert;
    }else
    {
        NodoMatriz *aux = this->header->down;
        while(aux != nullptr)
        {
            if(aux->y > y)
            {
                NodoMatriz *xInsert = new NodoMatriz(0, y, 0, 0, 0);
                xInsert->up = aux->up;
                aux->up->down = xInsert;
                xInsert->down = aux;
                aux->up = xInsert;

                //asign node to headerX
                xInsert->next = insert;
                insert->previous = xInsert;
                break;
            }else if(aux->y == y)
            {
                NodoMatriz *auxX = aux->next;
                while(auxX != nullptr)
                {
                    if(auxX->x > x)
                    {
                        insert->previous = auxX->previous;
                        insert->next = auxX;
                        auxX->previous->next = insert;
                        auxX->previous = insert;
                        break;
                    }else if(auxX->next == nullptr && auxX->x < x)
                    {
                        insert->previous = auxX;
                        auxX->next = insert;
                        break;
                    }
                    auxX = auxX->next;
                }
                break;
            }else if(aux->down == nullptr)
            {
                NodoMatriz *xInsert = new NodoMatriz(0, y, 0, 0, 0);
                aux->down = xInsert;
                xInsert->up = aux;
                xInsert->down = nullptr;

                //asign node to headerX
                xInsert->next = insert;
                insert->previous = xInsert;
                break;
            }
            aux = aux->down;
        }
    }

}

void Matriz::deleteM(int x, int y)
{
    NodoMatriz *aux = this->header->next;
    while(aux != nullptr)
    {
        if(aux->x == x)
        {
            NodoMatriz *auxY = aux->down;
            while (auxY != nullptr)
            {
                if(auxY->y == y)
                {
                    if(auxY->next != nullptr)
                    {
                        auxY->previous->next = auxY->next;
                        auxY->next->previous = auxY->previous;
                    }
                    else if (auxY->next == nullptr)
                    {
                        if(auxY->previous->x == auxY->x || auxY->previous->x == 0)
                        {
                            NodoMatriz *colAux = auxY->previous;
                            if(colAux->down != nullptr)
                            {
                                colAux->up->down = colAux->down;
                                colAux->down->up = colAux->up;
                            }else
                                colAux->up->down = nullptr;
                            delete colAux;
                        }else
                            auxY->previous->next = nullptr;
                    }
                    if(auxY->down != nullptr)
                    {
                        auxY->up->down = auxY->down;
                        auxY->down->up = auxY->up;
                    }
                    else if (auxY->down == nullptr)
                    {
                        if(auxY->up == aux)
                        {
                            NodoMatriz *rowAux = auxY->up;
                            aux = this->header;
                            if(rowAux->next != nullptr)
                            {
                                rowAux->previous->next = rowAux->next;
                                rowAux->next->previous = rowAux->previous;
                            }else
                                rowAux->previous->next = nullptr;
                            delete rowAux;
                        }else
                            auxY->up->down = nullptr;
                        delete auxY;
                    }break;
                }
                auxY = auxY->down;
            }
        }
        aux = aux->next;
    }
}

void Matriz::graficar(std::string postGraph)
{
    if(this->header->next != nullptr || this->header->down != nullptr)
    {
        std::string txtArchivo;
        txtArchivo ="";
        txtArchivo += "digraph Mass{\n";
        txtArchivo += "rankdir = TB; \n";
        txtArchivo += "node[shape = rectangle, height = 1, width = 1]; \n";
        txtArchivo += "graph[nodesep = 0.5]; \n";

        //txtArchivo += "subgraph cluster_0{\n";
        //txtArchivo += "matriz[color = green style= filled fontcolor = white ];\n";

        // ************************************************************   escribir nodos

        NodoMatriz *auxNext = this->header->next;
        txtArchivo += "header[shape = record  label= \"Header\"]; \n";

        while(auxNext != nullptr)
        {
            txtArchivo += "nodoX"+std::to_string(auxNext->x)+"[label= \"X = "+std::to_string(auxNext->x)+"\"";
            txtArchivo += "];\n";
            auxNext = auxNext->next;
        }
        txtArchivo += "header -> nodoX"+std::to_string(this->header->next->x) + " [constraint=false, dir=\"both\"]; \n";

        NodoMatriz *auxDown = this->header->down;

        while(auxDown != nullptr)
        {
            txtArchivo += "nodoY"+std::to_string(auxDown->y)+"[label= \"y = "+std::to_string(auxDown->y)+"\"";
            txtArchivo += "];\n";
            auxDown = auxDown->down;
        }
        txtArchivo += "header -> nodoY"+std::to_string(this->header->down->y) + " [ constraint=false, dir=\"both\"]; \n";

        auxDown = this->header->down;

        while(auxDown != nullptr)
        {
            graficarRecursivo(auxDown->next,txtArchivo);
            if(auxDown->next != nullptr)
                txtArchivo += "nodoY"+std::to_string(auxDown->y)+" -> "+ "nodoXY"+std::to_string(auxDown->next->x)+std::to_string(auxDown->next->y)+" [constraint=false, dir=\"both\"]; \n";
            if(auxDown->down != nullptr)
                txtArchivo += "nodoY"+std::to_string(auxDown->y)+" -> "+ "nodoY"+std::to_string(auxDown->down->y) + " [dir=\"both\"]; \n";
            auxDown = auxDown->down;
        }

        auxNext = this->header->next;

//Modificar **********************************

        while(auxNext != nullptr)
        {
            NodoMatriz *aux = auxNext->down;
            while(aux != nullptr)
            {
                if(aux->down != nullptr)
                    txtArchivo += "nodoXY"+std::to_string(aux->x)+std::to_string(aux->y) +" -> "+ "nodoXY"+std::to_string(aux->down->x)+std::to_string(aux->down->y)+"; \n";
                aux = aux->down;
            }

            if (auxNext->down != nullptr)
                txtArchivo += "nodoX"+std::to_string(auxNext->x)+" -> "+ "nodoXY"+std::to_string(auxNext->down->x)+std::to_string(auxNext->down->y)+" [dir=\"both\"]; \n";

            if(auxNext->next != nullptr)
                txtArchivo += "nodoX"+std::to_string(auxNext->x)+" -> "+ "nodoX"+std::to_string(auxNext->next->x) + " [dir=\"both\"]; \n";
            auxNext = auxNext->next;
        }

        // Alinear
        auxNext = this->header->next;

        txtArchivo += "{ rank=same; header ";
        while (auxNext != nullptr)
        {
            txtArchivo += "nodoX"+std::to_string(auxNext->x)+ " ";
            auxNext = auxNext->next;
        }
        txtArchivo += "}\n";

        auxDown = this->header->down;
        while(auxDown != nullptr)
        {

            auxNext = auxDown->next;
            txtArchivo += "{ rank=same; nodoY"+std::to_string(auxDown->y)+" ";
            while (auxNext != nullptr)
            {
                txtArchivo += "nodoXY"+std::to_string(auxNext->x)+std::to_string(auxNext->y) +" ";
                auxNext = auxNext->next;
            }
            txtArchivo += "}\n";
            auxDown = auxDown->down;
        }


        txtArchivo += "\n}";

        guardarArchivo(txtArchivo , postGraph);
    }
}

void Matriz::graficarRecursivo(NodoMatriz*& nodo, std::string &txtArchivo)
{
    if(nodo != nullptr)
    {
        txtArchivo += "nodoXY"+std::to_string(nodo->x)+std::to_string(nodo->y)+"[label= ";
        txtArchivo += "\"R:"+std::to_string(nodo->r) + "\\nG:" +std::to_string(nodo->g) + "\\nB:" +std::to_string(nodo->b) +"\"";
        txtArchivo += "];\n";

    }else if(nodo == nullptr)
        return;

    graficarRecursivo(nodo->next , txtArchivo);
    if(nodo->next != nullptr)
        txtArchivo += "nodoXY"+std::to_string(nodo->x)+std::to_string(nodo->y) +" -> "+ "nodoXY"+std::to_string(nodo->next->x)+std::to_string(nodo->next->y)+" [ constraint=false, dir=\"both\"]; \n";
}

void Matriz::guardarArchivo(std::string txtArchivo, std::string postGraph)
{
    std::ofstream nuevo;
    nuevo.open("matriz.dot", std::ofstream::out);
    nuevo << txtArchivo << std::endl;

    nuevo.close();
    system(("dot -Tpng matriz.dot -o grafica"+ postGraph +".png").c_str());
    system(("grafica" + postGraph + ".png").c_str());
}



