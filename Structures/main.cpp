#include "ArboloBB.h"
#include "listfilters.h"
#include <stdlib.h>
#include <sys/stat.h>

using namespace std;

void menu(CubeImage *&imageNew, ArbolBB *&images, ListFilters *&filters);
void sub_menu1(CubeImage *&imageNew, ArbolBB *&images);
void sub_menu2(CubeImage *&imageNew, ArbolBB *&images);
void crearFilter(ListFilters *&filters, CubeImage *&imageNew);
void sub_menu4(CubeImage *&imageNew, ListFilters *filters);
void sub_menu5(CubeImage *&imageNew, ListFilters *filters);
void sub_menu6(ListFilters *filters, ArbolBB *&images);

void fileConfig(CubeImage *&imageNew);
void leerCapas(CubeImage *&imageNew);
void mirrorX(Matriz *& original, Matriz *& mirror, int width);
void mirrorY(Matriz *& original, Matriz *& mirror, int height);
void collage(Matriz *& original, Matriz *& collage, int x, int y);
void grayscale(Matriz *& grayscale);
void negative(Matriz *& negative);
string convertDecToHex(int num);
string numHex(int num);
string RGBToHex(int rNum, int gNum, int bNum);
void RGBToGrayscale(int &r, int &g, int &b);
void RGBToNegative(int &r, int &g, int &b);
void fileHTML(CubeImage cube);
void fileCSS(CubeImage *imageNew, string fileName);
void getNumInter(int &num, int lS, int lI);
Matriz*& listLayouts(CubeImage *layouts);
CubeImage &listFilters(ListFilters *&filters);
void listImages(CubeImage *&imageNew, ArbolBB *&images);
void GuardandoArchivo(string txtArchivo, string tipeFile, string nameFile);
void createFile(string path);
void deleteExtension(string &name);


int main()
{
    createFile("Exports");
    CubeImage *imageNew = new CubeImage();
    ArbolBB *images = new ArbolBB();
    ListFilters *filters = new ListFilters();
    cout << "\"Hello World!\"" << endl;

    /*
    CubeImage *c1 = new CubeImage();
    c1->imageName = "image10.csv";
    CubeImage *c2 = new CubeImage();
    c2->imageName = "image5.csv";
    CubeImage *c3 = new CubeImage();
    c3->imageName = "image15.csv";
    CubeImage *c4 = new CubeImage();
    c4->imageName = "image7.csv";
    CubeImage *c5 = new CubeImage();
    c5->imageName = "image11.csv";
    CubeImage *c6 = new CubeImage();
    c6->imageName = "image02.csv";
    CubeImage *c7 = new CubeImage();
    c7->imageName = "image05.csv";
    CubeImage *c8 = new CubeImage();
    c8->imageName = "image00.csv";

    images->insertarNodo(c1);
    images->insertarNodo(c2);
    images->insertarNodo(c3);
    images->insertarNodo(c4);
    images->insertarNodo(c5);
    images->insertarNodo(c6);
    images->insertarNodo(c7);
    images->insertarNodo(c8);
    //images->graficarArbol();
    //nuevo->graficarInorder();
    //nuevo->graficarPreOrden();
    //nuevo->graficarPostOrden();
    */

    menu(imageNew, images, filters);

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

void getNumInter(int &num, int lS, int lI)
{
    try {
        cin >> num;
    } catch (exception e) {
        cout << "la tecla seleccionada no es valida\n";
    }

    while( num < lI || num > lS )
    {
        cout << "Digite una opcion de Valida\n";
        try {
            cin >> num;
        } catch (exception e) {
            cout << "la tecla seleccionada no es valida \n Digite una opcion de nuevo";
            num = 9;
        }
    }
}


void menu(CubeImage *&imageNew, ArbolBB *&images, ListFilters *&filters)
{
    while(true)
    {
        system("cls");

        cout << "***************MENU***************\n";
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
        getNumInter(entrada,7,1);

        switch (entrada) {
        case 1: sub_menu1(imageNew, images);
            break;
        case 2: sub_menu2(imageNew, images); filters = new ListFilters();
            break;
        case 3: crearFilter(filters, imageNew);
            break;
        case 4: sub_menu4(imageNew,filters);
            break;
        case 5:sub_menu5(imageNew,filters);
            break;
        case 6:sub_menu6(filters,images);
            break;
        }
        if (entrada == 7)
            break;
    }

}

//****************************************************sub_menu1
void sub_menu1(CubeImage *&imageNew, ArbolBB *&images)
{
    imageNew = new CubeImage();
    //***** Read first file ******
    while (true)
    {
        system("cls");
        bool layer = false, firstword = false;
        cout << "ingrese la direccion del archivo\n";
        string path, contenido, nameLayer, file = "", nameImage;
        cin >> path;
        bool character = false;
        for (int i = static_cast<int>(path.length()-1) ; i >= 0 ; i--) {
            if(path[i] == '\\')
                character = true;
            if(character)
                file = path[i] + file;
            else
                nameImage = path[i] + nameImage;
        }
        imageNew->pathImage = file;
        deleteExtension(nameImage);
        imageNew->imageName = nameImage;
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
                            deleteExtension(nameLayer);
                            imageNew->layouts->insertar(numLayer, nameLayer);
                            word = "";

                        }else
                            word = word + x;
                    }
                }
            } catch (exception e) {}
        }else
              continue;
        break;
    }
    //***** Read file Config ******
    fileConfig(imageNew);
    leerCapas(imageNew);
    images->insertarNodo(imageNew);
}

void fileConfig(CubeImage *&imageNew)
{
    string path = imageNew->pathImage + imageNew->layouts->primero->nameLayout + ".csv", contenido;
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
                            if(word == "config")
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
                                    imageNew->image_width = -1;
                                else if(word == "image_height")
                                    imageNew->image_height = -1;
                                else if(word == "pixel_width")
                                    imageNew->pixel_width = -1;
                                else if(word == "pixel_height")
                                    imageNew->pixel_height = -1;
                            }
                            word = "";
                        }
                    } else if (i == tam-1)
                    {
                        word = word + x;
                        if(config == false)
                        {
                            if(word == "image_width")
                                imageNew->image_width = valor;
                            else if(word == "image_height")
                                imageNew->image_height = valor;
                            else if(word == "pixel_width")
                                imageNew->pixel_width = valor;
                            else if(word == "pixel_height")
                                imageNew->pixel_height = valor;
                        }
                        else
                        {
                            if(imageNew->image_width == -1)
                                imageNew->image_width = stoi(word);
                            else if(imageNew->image_height == -1)
                                imageNew->image_height = stoi(word);
                            else if(imageNew->pixel_width == -1)
                                imageNew->pixel_width = stoi(word);
                            else if(imageNew->pixel_height == -1)
                                imageNew->pixel_height = stoi(word);
                        }
                        word = "";

                    }else
                        word = word + x;
                }
            }
        } catch (exception e) {}
    }
}

void leerCapas(CubeImage *&imageNew)
{
    if(imageNew->layouts->primero != nullptr)
    {
        NodoLayout *aux = imageNew->layouts->primero->next;
        while(aux != imageNew->layouts->primero)
        {
            string path = imageNew->pathImage + aux->nameLayout + ".csv", contenido;
            int x = 1, y = 1;
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
                            if(word != "x" && word != "")
                            {
                                int r = -1 , g = -1 , b = -1, ini = 0, tWord = static_cast<int>(word.length());
                                for (int j = 0; j < tWord  ; j++) {
                                    if(word[j] == '-' or j == tWord -1)
                                    {
                                        try {
                                            if(r == -1)
                                                r = stoi(word.substr(ini, j));
                                            else if(g == -1)
                                                g = stoi(word.substr(ini, j));
                                            else if(b == -1)
                                            {
                                                b = stoi(word.substr(ini, j));
                                                aux->layout->add(x,y,r,g,b);
                                            }
                                        } catch (exception e) {cout << "error";}
                                        ini = j+1;
                                    }
                                }
                            }
                            x++;
                            word = "";
                            if(i == tam-1)
                            {
                                y++;
                                x = 1;
                            }
                        }else
                            word = word + c;
                    }
                }
            } catch (exception e) {}
            //aux->layout->graficar(aux->nameLayout);
            aux = aux->next;
        }
    }
}

//****************************************************sub_menu2
void sub_menu2(CubeImage *&imageNew, ArbolBB *&images)
{
    imageNew = new CubeImage();
    listImages(imageNew, images);
}

//****************************************************sub_menu3
void crearFilter(ListFilters *&filters, CubeImage *&imageNew)
{
    if(imageNew->imageName != "")
    {
        CubeImage imageFilter = *imageNew;
        system("cls");
        cout << "***************Filters***************\n";
        cout << "1 - Grayscale\n";
        cout << "2 - Negative\n";
        cout << "3 - X-Mirror\n";
        cout << "4 - Y-Mirror\n";
        cout << "5 - Double Mirror\n";
        cout << "6 - Collage\n";
        int entrada;
        getNumInter(entrada,6,1);
        int x = 0, y = 0;
        if(entrada == 6)
        {
            cout << "Enter the repetitions in X: ";
            getNumInter(x,100,0);
            cout << "\nEnter the repetitions in Y: ";
            getNumInter(y,100,0);
        }
        cout << "\n\n*************filter type*************\n";
        cout << "1 - Full Image\n";
        cout << "2 - A Layout\n";
        int type;
        getNumInter(type,2,1);

        if(type == 1)
        {
            if(entrada == 1)
            {
                NodoLayout *auxLayer = imageFilter.layouts->primero->next;
                do
                {
                    grayscale(auxLayer->layout);
                    auxLayer = auxLayer->next;
                }while(auxLayer != imageNew->layouts->primero);
               filters->insertar("grayscale", imageFilter);
            }else if(entrada == 2)
            {
                NodoLayout *auxLayer = imageFilter.layouts->primero->next;
                do
                {
                    negative(auxLayer->layout);
                    auxLayer = auxLayer->next;
                }while(auxLayer != imageNew->layouts->primero);
               filters->insertar("negative", imageFilter);
            }else if(entrada == 3)
            {
                //create layers
                NodoLayout *auxLayer = imageFilter.layouts->primero->next;

                do
                {
                    Matriz *nueva = new Matriz();
                    mirrorX(auxLayer->layout,nueva , imageNew->image_width);
                    auxLayer->layout = nueva;
                    auxLayer = auxLayer->next;
                }while(auxLayer != imageNew->layouts->primero);
                filters->insertar("mirrorX", imageFilter);
            }else if(entrada == 4)
            {
                NodoLayout *auxLayer = imageFilter.layouts->primero->previous;
                int numLay = 1;
                ListLayout *listAux = new ListLayout();
                listAux->insertar(0,"config");
                do
                {
                    Matriz *nueva = new Matriz();
                    mirrorY(auxLayer->layout,nueva, imageFilter.image_height);
                    listAux->insertar(numLay++,auxLayer->nameLayout,nueva);
                    auxLayer = auxLayer->previous;
                }while(auxLayer != imageNew->layouts->primero);
                imageFilter.layouts = listAux;
                filters->insertar("mirrorY", imageFilter);
            }else if(entrada == 5)
            {
                NodoLayout *auxLayer = imageFilter.layouts->primero->next;
                do
                {
                    Matriz *nueva = new Matriz();
                    Matriz *nuevaXY = new Matriz();
                    mirrorX(auxLayer->layout,nueva, imageNew->image_width);
                    mirrorY(nueva,nuevaXY, imageFilter.image_height);
                    auxLayer->layout = nuevaXY;
                    auxLayer = auxLayer->next;
                }while(auxLayer != imageNew->layouts->primero);
               filters->insertar("mirrorXY", imageFilter);
            }else if(entrada == 6)
            {
                NodoLayout *auxLayer = imageFilter.layouts->primero->next;
                do
                {
                    Matriz *nueva = new Matriz();
                    collage(auxLayer->layout,nueva, x, y);
                    auxLayer->layout = nueva;
                    auxLayer = auxLayer->next;
                }while(auxLayer != imageNew->layouts->primero);
                if(x > 0)
                    imageFilter.image_width = imageFilter.image_width*x;
                if(y > 0)
                    imageFilter.image_height = imageFilter.image_height*y;
               filters->insertar("collage", imageFilter);
            }
        }else
        {
            cout << "\n\n*************Layout list*************\n";
            Matriz *mEdit = listLayouts(&imageFilter);

            if(entrada == 1)
            {
                grayscale(mEdit);
                filters->insertar("grayscaleALayer", imageFilter);
            }else if(entrada == 2)
            {
                negative(mEdit);
                filters->insertar("negativeALayer", imageFilter);
            }else if(entrada == 3)
            {
                Matriz *nueva = new Matriz();
                mirrorX(mEdit,nueva, imageNew->image_width);
                mEdit = nueva;
               filters->insertar("mirrorXALayer", imageFilter);
            }else if(entrada == 4)
            {
                Matriz *nueva = new Matriz();
                mirrorY(mEdit,nueva, imageFilter.image_height);
                mEdit = nueva;
                filters->insertar("mirrorYALayer", imageFilter);
            }else if(entrada == 5)
            {

                    Matriz *nueva = new Matriz();
                    Matriz *nuevaXY = new Matriz();
                    mirrorX(mEdit,nueva, imageNew->image_width);
                    mirrorY(nueva,nuevaXY, imageFilter.image_height);
                    mEdit = nuevaXY;
               filters->insertar("mirrorXYALayer", imageFilter);
            }else if(entrada == 6)
            {
                Matriz *nueva = new Matriz();
                collage(mEdit,nueva, x, y);
                if(x > 0)
                    imageFilter.image_width = imageFilter.image_width*x;
                if(y > 0)
                    imageFilter.image_height = imageFilter.image_height*y;
                filters->insertar("collageALayer", imageFilter);
            }
        }
    }
}

void mirrorX(Matriz *& original, Matriz *& mirror, int width)
{
    NodoMatriz *aux = original->header->down;
    while(aux != nullptr)
    {
        NodoMatriz *auxNodo = aux->next;
        while(auxNodo != nullptr)
        {
            mirror->add(abs(width - auxNodo->x)+1, auxNodo->y, auxNodo->r, auxNodo->g, auxNodo->b);
            auxNodo = auxNodo->next;
        }
        aux = aux->down;
    }
}

void mirrorY(Matriz *& original, Matriz *& mirror, int height)
{
    NodoMatriz *aux = original->header->down;
    while(aux != nullptr)
    {
        NodoMatriz *auxNodo = aux->next;
        while(auxNodo != nullptr)
        {
            mirror->add(auxNodo->x, abs(height - auxNodo->y)+1, auxNodo->r, auxNodo->g, auxNodo->b);
            auxNodo = auxNodo->next;
        }
        aux = aux->down;
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

//****************************************************sub_menu4
void sub_menu4(CubeImage *&imageNew, ListFilters *filters)
{
    system("cls");
    cout << "***************Manual Editing***************\n";
    cout << "1 - OG image\n";
    cout << "2 - Filters\n";

    int entrada;
    getNumInter(entrada,2,1);
    Matriz *modifyMatrix = nullptr;

    if(entrada == 1 && imageNew->imageName != "")
    {
        system("cls");
        cout << "*************Layout list*************\n";
        modifyMatrix = listLayouts(imageNew);
    }else if(filters->primero != nullptr)
    {

        CubeImage aux = listFilters(filters);
        system("cls");
        cout << "*************Layout list*************\n";
        modifyMatrix = listLayouts(&aux);
    }

    if(modifyMatrix != nullptr)
    {
        int x = -1, y = -1, r = 0, g = 0, b = 0;
        cout << "Enter Coordenate X: ";
        getNumInter(x,10000,1);
        cout << "Enter Coordenate Y: ";
        getNumInter(y,10000,1);

        cout << "Enter Color R: ";
        getNumInter(r,255,1);
        cout << "Enter Color G: ";
        getNumInter(g,255,1);
        cout << "Enter Color B: ";
        getNumInter(b,255,1);
        modifyMatrix->modify(x, y, r, g, b);
    }
}

//****************************************************sub_menu5
void sub_menu5(CubeImage *&imageNew, ListFilters *filters)
{
    system("cls");
    cout << "***************EXPORT IMAGE***************\n";
    cout << "1 - OG image\n";
    cout << "2 - Filters\n";

    int entrada;
    getNumInter(entrada,2,1);

    if(entrada == 1)
        fileHTML(*imageNew);
    else
    {
        CubeImage aux = listFilters(filters);
        fileHTML(aux);
    }
}

//****************************************************sub_menu6
void sub_menu6(ListFilters *filters, ArbolBB *&images)
{
    system("cls");
    cout << "***************REPORTS***************\n";
    cout << "1 - IMPORTED IMAGES REPORT\n";
    cout << "2 - IMAGE LAYER REPORT\n";
    cout << "3 - LINEAR MATRIX REPORT\n";
    cout << "4 - TRAVERSAL REPORT\n";
    cout << "5 - FILTERS REPORT\n";
    int entrada;
    getNumInter(entrada,5,1);
    if(entrada == 1 && images->Raiz != nullptr)
        images->graficarArbol();
    else if(entrada == 2 && images->Raiz != nullptr)
    {
        CubeImage *aux = new CubeImage();
        listImages(aux, images);
        cout << "\n\n*********IMAGE LAYER REPORT*********\n";
        cout << "1 - A layer\n";
        cout << "2 - All Layer\n";
        int entrada;
        getNumInter(entrada,2,1);
        if(entrada == 1)
        {
            Matriz *graph = listLayouts(aux);
            graph->graficar(aux->imageName + "layout");
        }else
        {
            NodoLayout *auxLayout = aux->layouts->primero->next;
            while(auxLayout!= aux->layouts->primero)
            {
                Matriz *auxM = auxLayout->layout;
                auxM->graficar(auxLayout->nameLayout);
                auxLayout = auxLayout->next;
            }
        }
    }else if(entrada == 3 && images->Raiz != nullptr)
    {
        CubeImage *aux = new CubeImage();
        listImages(aux, images);
        Matriz *graph = listLayouts(aux);
        cout << "\n\n*********LINEAR MATRIX REPORT*********\n";
        cout << "1 - Rows\n";
        cout << "2 - Columns\n";
        int entrada;
        getNumInter(entrada,2,1);
        if(entrada == 1)
            graph->graficarLineRows(aux->imageName+"row");
        else if(entrada == 2)
            graph->graficarLineColumns(aux->imageName+"Column");

    }else if(entrada == 4 && images->Raiz != nullptr)
    {
        cout << "\n\n*********TRAVERSAL REPORT*********\n";
        cout << "1 - Inorder\n";
        cout << "2 - Postorder\n";
        cout << "3 - Preorder\n";
        int entrada;
        getNumInter(entrada,3,1);
        switch (entrada)
        {
        case 1:
            images->graficarInorder();
            break;
        case 2:
            images->graficarPostOrden();
            break;
        case 3:
            images->graficarPreOrden();
            break;
        }
    }else if(entrada == 5 && filters->primero != nullptr)
    {
        cout << "\n\n*********FILTERS REPORT*********\n";
        cout << "1 - All filters report\n";
        cout << "2 - Individual filter report\n";
        int entrada;
        getNumInter(entrada,2,1);
        if (entrada == 1)
            filters->graphFilters();
        else if(entrada == 2)
        {
            CubeImage aux = listFilters(filters);
            cout << "\n\n*********Individual filter report*********\n";
            cout << "1 - A layer\n";
            cout << "2 - All Layer\n";
            int entrada;
            getNumInter(entrada,2,1);
            if(entrada == 1)
            {
                Matriz *graph = listLayouts(&aux);
                graph->graficar(aux.imageName + "layout");
            }else
            {
                NodoLayout *auxLayout = aux.layouts->primero->next;
                while(auxLayout!= aux.layouts->primero)
                {
                    Matriz *auxM = auxLayout->layout;
                    auxM->graficar(auxLayout->nameLayout);
                    auxLayout = auxLayout->next;
                }
            }
        }
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

void fileHTML(CubeImage cube)
{
    if(cube.image_width != -2)
    {
        string nameFile = cube.imageName;
        string txtHtml = "";
        txtHtml += "<!DOCTYPE html>\n<html>\n<head>\n<!-- Link to our stylesheet Painting our Pixel Art -->\n";
        txtHtml += "<link rel=\"stylesheet\" href=\""+ nameFile +".css\">\n</head>\n<body>\n";
        txtHtml += "<!-- div container representing the canvas -->\n";
        txtHtml += "<div class=\"canvas\">\n";
        txtHtml += "<div class=\"pixel\"></div>\n";
        txtHtml += "<!-- ...add as many pixels as needed. -->\n";

        for (int i = 0; i<(cube.image_width*cube.image_height);i++) {
            txtHtml += "  <div class=\"pixel\"></div>\n";
        }
        txtHtml += "</body>\n</html>";
        GuardandoArchivo(txtHtml,"html",nameFile);
        fileCSS(&cube,nameFile);
        system(("\\Exports\\" + nameFile + ".html").c_str());
    }

}

void fileCSS(CubeImage *imageNew, string fileName)
{
    string txtscss = "";
    txtscss += "body {\nbackground: #333333;      /* Background color of the whole page */\n";
    txtscss += "height: 100vh;            /* 100 viewport heigh units */\n";
    txtscss += "display: flex;            /* defines a flex container */\n";
    txtscss += "justify-content: center;  /* centers the canvas horizontally */\n";
    txtscss += "align-items: center;      /* centers the canvas vertically */\n}\n";

    txtscss += ".canvas \n{\n";
    txtscss += "width: " + to_string(imageNew->image_width*imageNew->pixel_width) + "px;   /* Width of the canvas */\n";
    txtscss += "height: " + to_string(imageNew->image_height*imageNew->pixel_height) + "px;  /* Height of the canvas */\n}\n";

    txtscss += ".pixel \n{\n";
    txtscss += "width: " + to_string(imageNew->pixel_width) + "px;    /* Width of each pixel */\n";
    txtscss += "height: " + to_string(imageNew->pixel_height) + "px;   /* Height of each pixel */\n";
    txtscss += "float: left;    /* Everytime it fills the canvas div it will begin a new line */\n";
    txtscss += "/*box-shadow: 0px 0px 1px #fff;*/  /* Leave commented, showing the pixel boxes */\n}\n";

    txtscss += "/* list of pixels that will be painted */\n";

    NodoLayout *auxLayer = imageNew->layouts->primero->next;
    string colorPrev = "", color = "";
    int numRow = 0;
    do
    {
        txtscss += "\n/* " + auxLayer->nameLayout + " */\n";
        NodoMatriz *auxRow = auxLayer->layout->header->down;
        while(auxRow != nullptr)
        {
            NodoMatriz *auxColumn = auxRow->next;
            while(auxColumn != nullptr)
            {
                color = RGBToHex(auxColumn->r, auxColumn->g, auxColumn->b);
                if(colorPrev != color && colorPrev !="")
                    txtscss += "\n{\n background: "+ colorPrev +";\n}\n";
                else if(colorPrev != "")
                    txtscss += ",\n";
                txtscss += ".pixel:nth-child(" + to_string(auxColumn->x + (numRow*imageNew->image_width)) + ")";
                colorPrev = color;
                auxColumn = auxColumn->next;
            }
            auxRow = auxRow->down;
            numRow += 1;
        }
        auxLayer = auxLayer->next;
    }while(auxLayer != imageNew->layouts->primero);
    txtscss += "{\n background: "+ color +";\n}";

    GuardandoArchivo(txtscss, "css", fileName);
}

Matriz *&listLayouts(CubeImage* layouts)
{
    system("cls");
    cout << "*************Layouts list*************\n";
    int contLay = 1;
    NodoLayout *auxLay = layouts->layouts->primero->next;
    do
    {
        cout << to_string(contLay) + " - " + auxLay->nameLayout + "\n";
        contLay += 1;
        auxLay = auxLay->next;
    }while(auxLay != layouts->layouts->primero);

    int numLay;
    cout << "Enter the number of the option you wish to select\n";
    getNumInter(numLay,contLay,1);
    auxLay = layouts->layouts->primero->next;
    for (int i = 1 ; i < numLay; i++)
        auxLay = auxLay->next;
    return auxLay->layout;
}

CubeImage &listFilters(ListFilters *&filters)
{
    system("cls");
    cout << "*************Filter list*************\n";
    int numcapas = 1;
    NodoFilter *auxFilter = filters->primero;
    do
    {
        cout << to_string(numcapas) + " - " + auxFilter->nameFilter + "\n";
        numcapas += 1;
        auxFilter = auxFilter->next;
    }while(auxFilter != filters->primero);

    int numLay;
    cout << "Enter the number of the option you wish to select\n";
    getNumInter(numLay,numcapas,1);
    auxFilter = filters->primero;
    for (int i = 0 ; i < numLay; i++)
        auxFilter = auxFilter->next;
    return auxFilter->filter;
}

void listImages(CubeImage *&imageNew, ArbolBB *&images)
{
    ListCircularDE *imagesNames = new ListCircularDE();
    images->getImages(imagesNames);
    int cont = 1;
    system("cls");
    cout << "***************IMAGES***************\n";
    Nodo *aux = imagesNames->primero;
    do
    {
        cout << to_string(cont) + " - " + aux->nameNodo + "\n";
        cont += 1;
        aux = aux->next;
    }while(aux != imagesNames->primero);
    int entrada;
    cout << "Enter the number of the option you wish to select\n";
    getNumInter(entrada,cont,1);
    aux = imagesNames->primero;
    for (int i = 1; i < entrada ; i++)
        aux = aux->next;
    images->getImage(imageNew, aux->nameNodo);
}

void GuardandoArchivo(string txtArchivo, string tipeFile, string nameFile)
{
    std::ofstream nuevo;
    string path = "";
    if(tipeFile == "html")
        path += nameFile + ".html";
    else if(tipeFile == "css")
        path += nameFile + ".css";
    nuevo.open(path, std::ofstream::out);
    nuevo << txtArchivo << std::endl;
    nuevo.close();

}

void createFile(string path)
{
    if ( access( path.c_str(), 0 ) != 0 )
        system("mkdir Exports");
}

void deleteExtension(string &name)
{
    if(name.substr(name.find_last_of(".") + 1) == "csv")
        name = name.substr(0, name.size()-4);
}
