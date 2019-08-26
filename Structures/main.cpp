#include "ArboloBB.h"
#include "listfilters.h"
#include <stdlib.h>

using namespace std;

void menu(CubeImage *&estructs);
void sub_menu1(CubeImage *&estructs);
void fileConfig(CubeImage *&estructs);
void leerCapas(CubeImage *&estructs);
void crearFilter(int numFilter , ListFilters *filters, CubeImage *&estructs);
void mirrorX(Matriz *& original, Matriz *& mirror);
void mirrorY(Matriz *& original, Matriz *& mirror);
void collage(Matriz *& original, Matriz *& collage, int x, int y);
void grayscale(Matriz *& grayscale);
void negative(Matriz *& negative);
string convertDecToHex(int num);
string numHex(int num);
string RGBToHex(int rNum, int gNum, int bNum);
void RGBToGrayscale(int &r, int &g, int &b);
void RGBToNegative(int &r, int &g, int &b);



int main()
{
    CubeImage *estructs = new CubeImage();
    //ListFilters *filters = new ListFilters();
    cout << "\"Hello World!\"" << endl;
    ArbolBB *nuevo = new ArbolBB;
    CubeImage *c1 = new CubeImage();
    c1->imageName = "image10";
    CubeImage *c2 = new CubeImage();
    c2->imageName = "image5";
    CubeImage *c3 = new CubeImage();
    c3->imageName = "image15";
    CubeImage *c4 = new CubeImage();
    c4->imageName = "image7";
    CubeImage *c5 = new CubeImage();
    c5->imageName = "image11";
    CubeImage *c6 = new CubeImage();
    c6->imageName = "image02";
    CubeImage *c7 = new CubeImage();
    c7->imageName = "image05";
    CubeImage *c8 = new CubeImage();
    c8->imageName = "image00";

    nuevo->insertarNodo(c1);
    nuevo->insertarNodo(c2);
    nuevo->insertarNodo(c3);
    nuevo->insertarNodo(c4);
    nuevo->insertarNodo(c5);
    nuevo->insertarNodo(c6);
    nuevo->insertarNodo(c7);
    nuevo->insertarNodo(c8);
    nuevo->graficarArbol();
    nuevo->graficarInorder();
    nuevo->graficarPreOrden();
    nuevo->graficarPostOrden();


    //menu(estructs);

    /*
    Matriz *matriz = new Matriz();

    matriz->add(15,10,255,229,204);
    matriz->add(3,6,255,229,204);
    matriz->add(5,2,255,229,204);
    matriz->add(16,11,255,229,204);
    matriz->add(4,1,255,229,204);
    matriz->add(1,1,255,229,204);
    matriz->add(2,2,255,229,204);
    matriz->add(2,3,255,229,204);
    matriz->add(15,1,255,229,204);
    matriz->add(15,2,255,229,204);
    matriz->add(15,3,255,229,204);

    matriz->graficar("plan1");

    matriz->deleteM(3,6);
    matriz->deleteM(2,2);

    matriz->graficar("plan2");

    */
    //system("PAUSE");
    return 0;
}

void menu(CubeImage *&estructs)
{
    while(true)
    {
        system("cls");

        cout << "***************Menu***************\n";
        cout << "*  1 - Insert Image              *\n";
        cout << "*  2 - Select Image              *\n";
        cout << "*  3 - Apply filters             *\n";
        cout << "*  4 - Manual Editing            *\n";
        cout << "*  5 - Export Image              *\n";
        cout << "*  6 - reports                   *\n";
        cout << "*  7 - exit                      *\n";
        cout << "**********************************\n";
        cout << "\nIngrese la Opcion deseada\n";

        int entrada;
        try {
            cin >> entrada;
        } catch (exception e) {
            cout << "la tecla seleccionada no es valida\n";
        }

        while( entrada < 1 || entrada > 7 )
        {
            cout << "Digite una opcion de Valida\n";
            try {
                cin >> entrada;
            } catch (exception e) {
                cout << "la tecla seleccionada no es valida \n Digite una opcion de nuevo";
                entrada = 9;
            }
        }

        switch (entrada) {
        case 1: sub_menu1(estructs);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        }
        if (entrada == 7)
            break;
    }

}

void sub_menu1(CubeImage *&estructs)
{

    while (true)
    {
        system("cls");
        bool layer = false, firstword = false;
        cout << "ingrese la direccion del archivo\n";
        string path, contenido, nameLayer, file = "";
        cin >> path;
        bool character = false;
        for (int i = static_cast<int>(path.length()-1) ; i >= 0 ; i--) {
            if(path[i] == '\\')
                character = true;
            if(character)
                file = path[i] + file;
        }
        estructs->pathImage = path;
        int numLayer = 0;
        if(path.substr(path.find_last_of(".") + 1) == "csv")
        {
            try
            {
                ifstream file(path);
                while(!file.eof())
                {
                    file >> contenido;
                    int tam = static_cast<int>(contenido.length()) ;
                    string word = "";
                    for (int i = 0 ; i < tam ; i++)
                    {
                        char x = contenido[i];
                        if (x == ',')
                        {
                            if (firstword == false)
                            {
                                if(word == "layer")
                                    layer = true;
                                firstword = true;
                                word = "";
                                break;
                            }else
                            {
                                if(layer == true)
                                    numLayer = stoi(word);
                                else
                                    nameLayer = word;
                                word = "";
                            }
                        } else if (i == tam-1)
                        {
                            word = word + x;
                            if(layer == false)
                                numLayer = stoi(word);
                            else
                                nameLayer = word;
                            estructs->layouts->insertar(numLayer,nameLayer);
                            word = "";

                        }else
                            word = word + x;
                    }
                }
                system("PAUSE");
            } catch (exception e) {}
        }else
              continue;
        break;
    }

}

void fileConfig(CubeImage *&estructs)
{
    string path = estructs->layouts->primero->nameLayout, contenido;
    bool firstword = false, config = false;
    int valor = -1;
    if(path.substr(path.find_last_of(".") + 1) == "csv")
    {
        try
        {
            ifstream file(path);
            while(!file.eof())
            {
                file >> contenido;
                int tam = static_cast<int>(contenido.length()) ;
                string word = "";
                for (int i = 0 ; i < tam ; i++)
                {
                    char x = contenido[i];
                    if (x == ',')
                    {
                        if (firstword == false)
                        {
                            if(word == "layer")
                                config = true;
                            firstword = true;
                            word = "";
                            break;
                        }else
                        {
                            if(config == false)
                                valor = stoi(word);
                            else
                            {
                                if(word == "image_width")
                                    estructs->image_width = -1;
                                else if(word == "image_height")
                                    estructs->image_height = -1;
                                else if(word == "pixel_width")
                                    estructs->pixel_width = -1;
                                else if(word == "pixel_height")
                                    estructs->pixel_height = -1;
                            }
                            word = "";
                        }
                    } else if (i == tam-1)
                    {
                        word = word + x;
                        if(config == false)
                        {
                            if(word == "image_width")
                                estructs->image_width = valor;
                            else if(word == "image_height")
                                estructs->image_height = valor;
                            else if(word == "pixel_width")
                                estructs->pixel_width = valor;
                            else if(word == "pixel_height")
                                estructs->pixel_height = valor;
                        }
                        else
                        {
                            if(estructs->image_width == -1)
                                estructs->image_width = valor;
                            else if(estructs->image_height == -1)
                                estructs->image_height = valor;
                            else if(estructs->pixel_width == -1)
                                estructs->pixel_width = valor;
                            else if(estructs->pixel_height == -1)
                                estructs->pixel_height = valor;
                        }
                        word = "";

                    }else
                        word = word + x;
                }
            }
            system("PAUSE");
        } catch (exception e) {}
    }
}

void leerCapas(CubeImage *&estructs)
{
    if(estructs->layouts->primero != nullptr)
    {
        NodoLayout *aux = estructs->layouts->primero->next;
        while(aux != estructs->layouts->primero)
        {
            string path = aux->nameLayout, contenido;
            int x = 0, y = 0;
            try
            {
                ifstream file(path);
                while(!file.eof())
                {
                    file >> contenido;
                    int tam = static_cast<int>(contenido.length());
                    string word = "";
                    for (int i = 0 ; i < tam ; i++)
                    {
                        char c = contenido[i];
                        if (c == ',' || i == tam-1)
                        {
                            if(word != "x")
                            {
                                int r = -1 , g = -1 , b = -1, ini = 0;
                                for (int j = 0; j < static_cast<int>(word.length())  ; j++) {
                                    if(word[j] == '-')
                                    {
                                        try {
                                            if(r == -1)
                                                r = stoi(word.substr(ini, j-1));
                                            else if(g == -1)
                                                g = stoi(word.substr(ini, j-1));
                                            else if(b == -1)
                                            {
                                                b = stoi(word.substr(ini, j-1));
                                                aux->layout->add(x,y,r,g,b);
                                            }
                                        } catch (exception e) {}
                                        ini = j+1;
                                    }
                                }
                            }
                                x++;
                                if(i == tam-1)
                                    y++;
                        }else
                            word = word + c;
                    }
                }
            } catch (exception e) {}
            aux = aux->next;
        }
    }
}

void crearFilter(int numFilter , ListFilters *filters, CubeImage *&estructs)
{
    ListLayout *layouts = new ListLayout();

    if(numFilter == 0)
    {
        NodoLayout *auxLayer = estructs->layouts->primero;
        do
        {
            Matriz *nueva = new Matriz();
            nueva = auxLayer->layout;
            grayscale(nueva);
            layouts->insertar(auxLayer->numLayout,auxLayer->nameLayout, nueva);
            auxLayer = auxLayer->next;
        }while(auxLayer != estructs->layouts->primero);
       filters->insertar("grayscale", layouts);
    }else if(numFilter == 1)
    {
        NodoLayout *auxLayer = estructs->layouts->primero;
        do
        {
            Matriz *nueva = new Matriz();
            nueva = auxLayer->layout;
            negative(nueva);
            layouts->insertar(auxLayer->numLayout,auxLayer->nameLayout, nueva);
            auxLayer = auxLayer->next;
        }while(auxLayer != estructs->layouts->primero);
       filters->insertar("negative", layouts);
    }else if(numFilter == 2)
    {
        //create layers
        NodoLayout *auxLayer = estructs->layouts->primero;
        do
        {
            Matriz *nueva = new Matriz();
            mirrorX(auxLayer->layout,nueva);
            layouts->insertar(auxLayer->numLayout,auxLayer->nameLayout, nueva);
            auxLayer = auxLayer->next;
        }while(auxLayer != estructs->layouts->primero);
       filters->insertar("mirrorX", layouts);
    }else if(numFilter == 3)
    {
        NodoLayout *auxLayer = estructs->layouts->primero;
        do
        {
            Matriz *nueva = new Matriz();
            mirrorY(auxLayer->layout,nueva);
            layouts->insertar(auxLayer->numLayout,auxLayer->nameLayout, nueva);
            auxLayer = auxLayer->next;
        }while(auxLayer != estructs->layouts->primero);
       filters->insertar("mirrorY", layouts);
    }else if(numFilter == 4)
    {
        NodoLayout *auxLayer = estructs->layouts->primero;
        do
        {
            Matriz *nueva = new Matriz();
            Matriz *nuevaXY = new Matriz();
            mirrorX(auxLayer->layout,nueva);
            mirrorY(nueva,nuevaXY);
            layouts->insertar(auxLayer->numLayout,auxLayer->nameLayout, nuevaXY);
            auxLayer = auxLayer->next;
        }while(auxLayer != estructs->layouts->primero);
       filters->insertar("mirrorXY", layouts);
    }
}

void mirrorX(Matriz *& original, Matriz *& mirror)
{
    NodoMatriz *aux = original->header;
    while(aux->next != nullptr)
        aux = aux->next;
    int maxColom = aux->x;
    aux = original->header;
    while(aux != nullptr)
    {
        NodoMatriz *auxNodo = aux->next;
        while(auxNodo != nullptr)
        {
            mirror->add(abs(maxColom - auxNodo->x), auxNodo->y, auxNodo->r, auxNodo->g, auxNodo->b);
            auxNodo = auxNodo->next;
        }
        aux = aux->down;
    }
}

void mirrorY(Matriz *& original, Matriz *& mirror)
{
    NodoMatriz *aux = original->header;
    while(aux->down != nullptr)
        aux = aux->down;
    int maxRow = aux->y;
    aux = original->header;
    while(aux != nullptr)
    {
        NodoMatriz *auxNodo = aux->down;
        while(auxNodo != nullptr)
        {
            mirror->add(auxNodo->x, abs(maxRow - auxNodo->y), auxNodo->r, auxNodo->g, auxNodo->b);
            auxNodo = auxNodo->down;
        }
        aux = aux->next;
    }
}

void collage(Matriz *& original, Matriz *& collage, int x, int y)
{
    for (int i = 1 ; i <= y ; i++ ) {
        for (int j = 1 ; j <= x ; j++ ) {
            NodoMatriz *aux = original->header;
            while(aux != nullptr)
            {
                NodoMatriz *auxNodo = aux->next;
                while(auxNodo != nullptr)
                {
                    collage->add(auxNodo->x*j,auxNodo->y*i,auxNodo->r, auxNodo->g, auxNodo->b);
                    auxNodo = auxNodo->next;
                }
                aux = aux->down;
            }
        }
    }
}


void grayscale(Matriz *& grayscale)
{
    NodoMatriz *aux = grayscale->header;
    while(aux != nullptr)
    {
        NodoMatriz *auxNodo = aux->next;
        while(auxNodo != nullptr)
        {
            RGBToGrayscale(auxNodo->r, auxNodo->b, auxNodo->b);
            auxNodo = auxNodo->next;
        }
        aux = aux->down;
    }
}

void negative(Matriz *& negative)
{
    NodoMatriz *aux = negative->header;
    while(aux != nullptr)
    {
        NodoMatriz *auxNodo = aux->next;
        while(auxNodo != nullptr)
        {
            RGBToNegative(auxNodo->r, auxNodo->b, auxNodo->b);
            auxNodo = auxNodo->next;
        }
        aux = aux->down;
    }
}

string RGBToHex(int rNum, int gNum, int bNum)
{
    string hex = "#";
    if(rNum < 16)
        hex += "0" + convertDecToHex(rNum);
    else
        hex += convertDecToHex(rNum);
    if(gNum < 16)
        hex += "0" + convertDecToHex(gNum);
    else
        hex += convertDecToHex(gNum);
    if(bNum < 16)
        hex += "0" + convertDecToHex(bNum);
    else
        hex += convertDecToHex(bNum);
    return hex;
}

string numHex(int num)
{
    switch (num) {
    case 10:
        return("A");
    case 11:
        return("B");
    case 12:
        return("C");
    case 13:
        return("D");
    case 14:
        return("E");
    case 15:
        return("F");
    }
    return("");
}

string convertDecToHex(int num)
{
    std::string hex ="";
    if(num < 256)
    {
        int residuo;
        while(num >15)
        {
            residuo = num%16;
            num = num/16;

            if(residuo < 10)
                hex = std::to_string(residuo) + hex;
            else
                hex = numHex(residuo) + hex;
        }
        if(num < 10)
            hex = std::to_string(num) + hex;
        else
            hex = numHex(num) + hex;

    }

    return hex;
}

void RGBToGrayscale(int &r, int &g, int &b)
{
    int x =  static_cast<int>(r*0.58 + 0.17*g +0.8*b);
    r = g = b = x;
}

void RGBToNegative(int &r, int &g, int &b)
{
    r = 255 - r;
    g = 255 - g;
    b = 255 - b;
}
