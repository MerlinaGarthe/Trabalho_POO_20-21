//
// Created by Merlina Garthe on 01/12/2020.
//

#ifndef DUNA_H
#define DUNA_H
#include <iostream>
#include <string>
#include "continente.h"
using namespace std;

class Duna: public Continente
{

    static int num;
    int conta;

public:
    Duna(string tipo = "Duna",   int resistencia = 4,int criacao_p = 0,int pontos = 1): conta (num++), Continente(tipo,num,resistencia,criacao_p,0, pontos) {}
    string getAsString() const;
    Duna* duplica() const {return new Duna (*this);}
};

#endif
