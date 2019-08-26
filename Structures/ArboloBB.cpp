#include "ArboloBB.h"

ArbolBB::ArbolBB() {
    this->Raiz = nullptr;
    this->contImagen = 0;
}

void ArbolBB::insertarNodo (NodoAB *&pivote, NodoAB *&insertar) {
    if (pivote == nullptr)
        pivote = insertar;
    else {
        if (pivote->nuevo->imageName.compare(insertar->nuevo->imageName) > 0)
            insertarNodo(pivote->nIzquierdo, insertar);
        else if (pivote->nuevo->imageName.compare(insertar->nuevo->imageName) < 0)
            insertarNodo(pivote->nDerecho, insertar);
    }
}

void ArbolBB::insertarNodo(CubeImage *&insertar) {
    NodoAB *insert = new NodoAB(insertar);

    insertarNodo(this->Raiz, insert);
}

bool ArbolBB::deleteNodo(NodoAB *&padre, NodoAB *&pivote, std::string codigo, int lado) {
    if (pivote != nullptr) {
        //NodoAB *aux = pivote;
        if (pivote->nuevo->imageName.compare(codigo) == 0)
        {
            if (lado == 0 && pivote->nDerecho != nullptr) {
                NodoAB *aux = pivote->nDerecho;
                NodoAB *aux2 = pivote;
                if(aux->nIzquierdo != nullptr)
                {
                    while (aux->nIzquierdo != nullptr) {
                        aux2 = aux;
                        aux = aux->nIzquierdo;
                    }
                    if (aux->nDerecho != nullptr)
                        aux2->nIzquierdo = aux->nDerecho;

                aux->nDerecho = pivote->nDerecho;
                aux->nIzquierdo = pivote->nIzquierdo;
                aux2->nIzquierdo = nullptr;
                aux2 = pivote;
                pivote = aux;
                delete aux2 ; return true;
                }
                padre = pivote->nDerecho;
            }else if (lado == 1 && pivote->nIzquierdo != nullptr) {
                NodoAB *aux = pivote->nIzquierdo;
                NodoAB *aux2 = pivote;
                if(aux->nDerecho != nullptr)
                {
                    while (aux->nDerecho != nullptr) {
                        aux2 = aux;
                        aux = aux->nDerecho;
                    }
                    if (aux->nIzquierdo != nullptr)
                        aux2->nDerecho = aux->nIzquierdo;

                    aux->nDerecho = padre->nDerecho;
                    aux->nIzquierdo = padre->nIzquierdo;

                    aux2->nDerecho = nullptr;
                    aux2 = pivote;
                    pivote = aux;
                    delete aux2 ; return true;
                }
                padre = pivote->nIzquierdo;

            } else if (pivote->nuevo->imageName.compare(codigo) < 0)
            {
                if (pivote->nDerecho != nullptr)
                    return deleteNodo(pivote, pivote->nDerecho, codigo, 0);
                else if (pivote->nIzquierdo != nullptr)
                    return deleteNodo(pivote, pivote->nIzquierdo, codigo, 1);
            }
        }
    }
    return false;
}

bool ArbolBB::eliminarNodo(std::string codigo) {
    NodoAB *aux = this->Raiz;
    if(this->Raiz->nuevo->imageName.compare(codigo) == 0)
    {
        if (this->Raiz->nDerecho == nullptr && this->Raiz->nIzquierdo == nullptr) {
            this->Raiz = nullptr;
            return true;
        }else if (this->Raiz->nDerecho == nullptr && this->Raiz->nIzquierdo != nullptr) {
            this->Raiz = this->Raiz->nIzquierdo;
            delete aux;
            return true;
        }else if (this->Raiz->nDerecho != nullptr && this->Raiz->nIzquierdo == nullptr) {
            this->Raiz = this->Raiz->nDerecho;
            delete aux;
            return true;
        }else{

            NodoAB *aux = this->Raiz->nIzquierdo;
            NodoAB *aux2 = this->Raiz;

                while (aux->nDerecho != nullptr) {
                    aux2 = aux;
                    aux = aux->nDerecho;
                }
                if (aux->nIzquierdo != nullptr)
                    aux2->nDerecho = aux->nIzquierdo;

                aux->nDerecho = this->Raiz->nDerecho;
                if(this->Raiz->nIzquierdo != aux)
                aux->nIzquierdo = this->Raiz->nIzquierdo;
                aux2->nDerecho = nullptr;
                aux2 = this->Raiz;
                this->Raiz = aux;
                delete aux2; return true;
        }
    }else if (this->Raiz->nuevo->imageName.compare(codigo) < 0)
    {
        if (this->Raiz->nDerecho != nullptr)
                return deleteNodo(this->Raiz, this->Raiz->nDerecho, codigo, 0);
        else if (this->Raiz->nIzquierdo != nullptr)
                return deleteNodo(this->Raiz, this->Raiz->nIzquierdo, codigo, 1);
    }
    return false;
}

void ArbolBB::arbolbinario( NodoAB *&nodo, std::string &txtArchivo)
{
        if(nodo != nullptr)
        {
        //std::cout << "\n" << "**************a**************";
        
        if(nodo->nIzquierdo != nullptr)
        {
            txtArchivo += nodo->nIzquierdo->nuevo->imageName + "[label= \" <A0> |";
            txtArchivo += " Image: "+nodo->nIzquierdo->nuevo->imageName+" | <A1> \"];\n";
            txtArchivo += nodo->nuevo->imageName+ ":A0" +" -> "+ nodo->nIzquierdo->nuevo->imageName+";\n";
        }
        if(nodo->nDerecho != nullptr)
        {
        txtArchivo += nodo->nDerecho->nuevo->imageName+"[label= \" <A0> |";
        txtArchivo += " Image: "+nodo->nDerecho->nuevo->imageName+" | <A1> \" ];\n";
        txtArchivo += nodo->nuevo->imageName + ":A1" +" -> "+ nodo->nDerecho->nuevo->imageName+";\n";
        }
        
        arbolbinario(nodo->nIzquierdo, txtArchivo);
        arbolbinario(nodo->nDerecho, txtArchivo);        
        
        }
}

void ArbolBB::graficarArbol()
{
        std::string txtArchivo;
        txtArchivo ="";
        txtArchivo += "digraph Mass{\n";
        txtArchivo += "node[shape = record, height = 0.5, width = 1]; \n";
        txtArchivo += "graph[nodesep = 0.5]; \n";

        txtArchivo += this->Raiz->nuevo->imageName+"[label= \"  <A0> |";
        txtArchivo += " Image: "+this->Raiz->nuevo->imageName+ " | <A1> \"];\n";
        arbolbinario(this->Raiz, txtArchivo);
            
        txtArchivo += "\n} ";
        GuardandoArchivo(txtArchivo, "binario");
}

void ArbolBB::graficarInorder()
{
    std::string txtArchivo;
    txtArchivo ="";
    txtArchivo += "digraph Mass{\n rankdir=LR; \n";
    txtArchivo += "node[shape = record, height = 0.5, width = 1]; \n";
    txtArchivo += "graph[nodesep = 0.5]; \n";
    ListCircularDE *nueva = new ListCircularDE();
    graficarInorder(this->Raiz, txtArchivo, nueva);
    Nodo *aux = nueva->primero;
    do
    {
        if(aux->next != nueva->primero)
            txtArchivo += aux->nameNodo + "->" + aux->next->nameNodo+ "\n";
        aux = aux->next;
    }while(aux != nueva->primero);
    txtArchivo += "}";
    GuardandoArchivo(txtArchivo, "inorder");
}

void ArbolBB::graficarInorder(NodoAB *&pivote, std::string &txtArchivo, ListCircularDE *& lista)
{
    if(pivote == nullptr)
        return;
    else
    {
        graficarInorder(pivote->nIzquierdo, txtArchivo, lista);
        txtArchivo += pivote->nuevo->imageName+"[label= \"";
        txtArchivo += " Image: "+pivote->nuevo->imageName+ "\"];\n";
        lista->insertar(pivote->nuevo->imageName);
        graficarInorder(pivote->nDerecho, txtArchivo, lista);
    }

}

void ArbolBB::graficarPostOrden()
{
    std::string txtArchivo;
    txtArchivo ="";
    txtArchivo += "digraph Mass{\n rankdir=LR; \n";
    txtArchivo += "node[shape = record, height = 0.5, width = 1]; \n";
    txtArchivo += "graph[nodesep = 0.5]; \n";
    ListCircularDE *nueva = new ListCircularDE();
    graficarPostOrden(this->Raiz, txtArchivo, nueva);
    Nodo *aux = nueva->primero;
    do
    {
        if(aux->next != nueva->primero)
            txtArchivo += aux->nameNodo + "->" + aux->next->nameNodo+ "\n";
        aux = aux->next;
    }while(aux != nueva->primero);
    txtArchivo += "}";
    GuardandoArchivo(txtArchivo, "postorden");
}

void ArbolBB::graficarPostOrden(NodoAB *&pivote, std::string &txtArchivo, ListCircularDE *& lista)
{
    if(pivote == nullptr)
        return;
    else
    {
        graficarPostOrden(pivote->nIzquierdo, txtArchivo, lista);
        graficarPostOrden(pivote->nDerecho, txtArchivo, lista);
        txtArchivo += pivote->nuevo->imageName+"[label= \"";
        txtArchivo += " Image: "+pivote->nuevo->imageName+ "\"];\n";
        lista->insertar(pivote->nuevo->imageName);
    }

}

void ArbolBB::graficarPreOrden()
{
    std::string txtArchivo;
    txtArchivo ="";
    txtArchivo += "digraph Mass{\n rankdir=LR; \n";
    txtArchivo += "node[shape = record, height = 0.5, width = 1]; \n";
    txtArchivo += "graph[nodesep = 0.5]; \n";
    ListCircularDE *nueva = new ListCircularDE();
    graficarPreOrden(this->Raiz, txtArchivo, nueva);
    Nodo *aux = nueva->primero;
    do
    {
        if(aux->next != nueva->primero)
            txtArchivo += aux->nameNodo + "->" + aux->next->nameNodo+ "\n";
        aux = aux->next;
    }while(aux != nueva->primero);
    txtArchivo += "}";
    GuardandoArchivo(txtArchivo, "preorden");
}

void ArbolBB::graficarPreOrden(NodoAB *&pivote, std::string &txtArchivo, ListCircularDE *& lista)
{
    if(pivote == nullptr)
        return;
    else
    {
        txtArchivo += pivote->nuevo->imageName+"[label= \"";
        txtArchivo += " Image: "+pivote->nuevo->imageName+ "\"];\n";
        lista->insertar(pivote->nuevo->imageName);
        graficarPreOrden(pivote->nIzquierdo, txtArchivo, lista);
        graficarPreOrden(pivote->nDerecho, txtArchivo, lista);
    }

}

void ArbolBB::GuardandoArchivo(std::string txtArchivo, std::string postGraph)
{
    std::ofstream nuevo;
    nuevo.open("arbol.dot", std::ofstream::out);
    nuevo << txtArchivo << std::endl;

    nuevo.close();
    system(("dot -Tpng arbol.dot -o arbol"+ postGraph +".png").c_str());
    system(("arbol" + postGraph + ".png").c_str());
}
