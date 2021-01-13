#include <climits>
//
// Created by Merlina Garthe on 01/12/2020.
//

#ifndef CASTELO_H
#define CASTELO_H
#include <iostream>
#include <string>
#include <sstream>
#include "continente.h"
using namespace std;



class Castelo : public Continente
{
    static int num;
    int conta;
   int p;
   int o;
   int fase;
public:
    Castelo(string tp = "Castelo",   int resistencia = 7,int pontos = 1): conta (num++),Continente(tp,num,resistencia,p, o, pontos) {}
    string getAsString() const;

};

#endif