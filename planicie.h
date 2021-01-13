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

public:
    Planicie(string tipo = "planicie",   int resistencia = 5,int criacao_p = 0,int criacao_o = 0,int pontos = 1): conta(num++), Continente(tipo, num,resistencia,criacao_p, criacao_o, pontos) {}
    string getAsString() const;
};

#endif // !1