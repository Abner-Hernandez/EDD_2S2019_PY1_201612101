#ifndef NODOLAYOUT_H
#define NODOLAYOUT_H
#include <string>

class NodoLayout
{
public:
    NodoLayout();
    NodoLayout *next, *previous;
    int numLayout;
    std::string nameLayout;
    NodoLayout(int numLay, std::string nameLay);

};

#endif // NODOLAYOUT_H
