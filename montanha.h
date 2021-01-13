//
// Created by Merlina Garthe on 01/12/2020.
//

#ifndef MONTANHA_H
#define MONTANHA_H
#include <string>
#include <iostream>
#include "continente.h"


using namespace std;

class Montanha : public Continente
{

    int conta;
    static int num;

public:
    Montanha(string tipo = "montanha",   int resistencia = 6,int criacao_p = 0,int criacao_o = 0,int pontos = 1): conta(num++), Continente(tipo,num,resistencia,criacao_p, criacao_o, pontos) {}
    string getAsString() const;
};

#endif