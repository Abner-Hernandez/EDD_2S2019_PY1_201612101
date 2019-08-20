#include <iostream>
#include "matriz.h"
#include "listlayout.h"

using namespace std;

void menu(ListLayout *&layouts);
void sub_menu1(ListLayout *&layouts);

int main()
{
    ListLayout *layouts = new ListLayout();
    cout << "\"Hello World!\"" << endl;
    menu(layouts);
/*
    Matriz *matriz = new Matriz();
    matriz->add(0,0,100,100,100);
    matriz->add(1,1,100,100,100);
    matriz->add(2,2,100,100,100);
    matriz->add(3,3,100,100,100);
    matriz->add(4,4,100,100,100);
    matriz->add(0,1,12,13,14);
    matriz->add(0,4,15,16,17);

    matriz->graficar();

*/
    system("PAUSE");
    return 0;
}

void menu(ListLayout *&layouts)
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
        case 1: sub_menu1(layouts);
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

void sub_menu1(ListLayout *&layouts)
{

    while (true)
    {
        system("cls");
        bool layer = false, firstword = false;
        cout << "ingrese la direccion del archivo";
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
                    string word = "";
                    for (int i = 0 ; i < contenido.length() ; i++)
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
                        } else if (i == contenido.length()-1)
                        {
                            word = word + x;
                            if(layer == false)
                                numLayer = stoi(word);
                            else
                                nameLayer = word;
                            layouts->insertar(numLayer,nameLayer);
                            word = "";

                        }else
                        {
                            word = word + x;
                        }
                    }

                }

                system("PAUSE");

            } catch (exception e) {}
        }else
              continue;
        break;
    }

}
