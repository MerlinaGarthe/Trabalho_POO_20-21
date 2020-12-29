//
// Created by Merlina Garthe on 01/12/2020.
//

#ifndef INTERFACE_H
#define INTERFACE_H
#include "mundo.h"
#include <iostream>
#include "castelo.h"
#include "duna.h"
#include "fortaleza.h"
#include "mina.h"
#include "montanha.h"
#include "planicie.h"
#include "pescaria.h"
#include "refugios.h"
#include "territorioJogador.h"
#include "logica.h"

using namespace std;

class Interface
{
    Mundo m;
    Castelo c;
    Duna d;
    Fortaleza f;
    Mina mina;
    Montanha montanha;
    Planicie p;
    Pescaria pesc;
    Refugios r;
    TerritorioJogador tj;
    Logica logica;
public:
    Interface() {}
    void comandosi();
    void mostra(string tipo);

};

#endif // !INTERFACE_H