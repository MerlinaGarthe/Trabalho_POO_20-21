//
// Created by Merlina Garthe on 18/12/2020.
//

#ifndef UNTITLED1_LOGICA_H
#define UNTITLED1_LOGICA_H
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

using namespace std;

class Logica {
    Mundo m;
    Castelo c;
    Duna d;
    Fortaleza f;
    Mina mina;
    Montanha montanha;
    Planicie p;
    Pescaria pesc;
    Refugios r;
public:
    bool addTerritorio(string tipo, int quant);
    string mostra() ;
};


#endif //UNTITLED1_LOGICA_H
