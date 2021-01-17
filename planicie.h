//
// Created by Merlina Garthe on 01/12/2020.
//

#ifndef PLANICIE_H
#define PLANICIE_H
#include <iostream>
#include <string>
#include "continente.h"
using namespace std;

class Planicie : public Continente
{

    static int num;
    int conta;
    int o;
    int p;
public:
    Planicie(string tipo = "planicie",   int resistencia = 5,int pontos = 1): conta(num++), Continente(tipo, num,resistencia,p, o, pontos) {}
    string getAsString() const;
    Planicie* duplica() const {return new Planicie(*this);}
};

#endif // !1