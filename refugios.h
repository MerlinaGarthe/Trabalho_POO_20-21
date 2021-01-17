//
// Created by Merlina Garthe on 01/12/2020.
//

#ifndef REFUGIOS_H
#define REFUGIOS_H
#include <iostream>
#include <string>
#include "ilhas.h"
using namespace std;
class Refugios : public Ilhas
{

    static int num;
    int conta;

public:
    Refugios(string tipo = "Refugios",   int resistencia = 9,int criacao_o = 1,int pontos = 2): conta(num++), Ilhas(tipo,num,resistencia,0, criacao_o, pontos) {}
    string getAsString() const;
    Refugios* duplica() const {return new Refugios (*this);}
};

#endif