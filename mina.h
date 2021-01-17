//
// Created by Merlina Garthe on 01/12/2020.
//

#ifndef MINA_H
#define MINA_H
#include <iostream>
#include <string>
#include "continente.h"
using namespace std;

class Mina : public Continente
{

    int conta;
    static int num;
    int o;
    int p;

public:
    Mina(string tipo= "Mina",   int resistencia = 5,int pontos = 1): conta(num++), Continente(tipo,num ,resistencia,0, o, pontos) {}
    string getAsString() const;
    Mina* duplica() const {return new Mina (*this);}
};

#endif