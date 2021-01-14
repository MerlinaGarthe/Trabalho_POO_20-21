//
// Created by Merlina Garthe on 01/12/2020.
//

#ifndef INTERFACE_H
#define INTERFACE_H
#include "logica.h"

using namespace std;

class Interface
{
    Logica logica;
    string cmd;
    string tipo;
    int turno;
    static int fase;
    static int flag;
    static int flag2;
    static int flag3;
public:
    Interface() {}
    void comandosi();
    void mostra(string tipo);

};

#endif // !INTERFACE_H