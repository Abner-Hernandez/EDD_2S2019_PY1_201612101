#include <iostream>
#include "listlayout.h"

using namespace std;

struct estructurasProy{
    ListLayout *layouts;
    int image_width = -2, image_height = -2, pixel_width = -2, pixel_height = -2;
};

void menu(estructurasProy *&estructs);
void sub_menu1(estructurasProy *&estructs);
void fileConfig(estructurasProy *&estructs);
void leerCapas(estructurasProy *&estructs);


int main()
{
    //estructurasProy *estructs = new estructurasProy();
    //estructs->layouts = new ListLayout();
    cout << "\"Hello World!\"" << endl;
    //menu(estructs);

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

    //system("PAUSE");
    return 0;
}

void menu(estructurasProy *&estructs)
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

void sub_menu1(estructurasProy *&estructs)
{

    while (true)
    {
        system("cls");
        bool layer = false, firstword = false;
        cout << "ingrese la direccion del archivo\n";
        string path, contenido, nameLayer;
        cin >> path;
        int numLayer = 0;
        if(path.substr(path.find_last_of(".") + 1) == "csv")
        {
            try
            {
                ifstream file(path);
                while(!file.eof())
                {
                    file >> contenido;
                    int tam = contenido.length();
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

void fileConfig(estructurasProy *&estructs)
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
                int tam = contenido.length();
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

void leerCapas(estructurasProy *&estructs)
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
                    int tam = contenido.length();
                    string word = "";
                    for (int i = 0 ; i < tam ; i++)
                    {
                        char x = contenido[i];
                        if (x == ',' || i == tam-1)
                        {
                            if(word != "x")
                            {
                                int r = -1 , g = -1 , b = -1, ini = 0;
                                for (int j = 0; j < word.length() ; j++) {
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
                            word = word + x;
                    }
                }
            } catch (exception e) {}

            aux = aux->next;

        }
    }


}
