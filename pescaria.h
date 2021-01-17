//
// Created by Merlina Garthe on 01/12/2020.
//

#ifndef PESCARIA_H
#define PESCARIA_H
#include <iostream>
#include <string>
#include "ilhas.h"
using namespace std;

class Pescaria : public Ilhas
{
    int conta;
    static int num;


public:
    Pescaria(string tipo = "Pescaria",   int resis = 9, int p = 2,int pon = 2): conta(num++), Ilhas(tipo, num,resis,p,0, pon) {}
    string getAsString() const;
    Pescaria* duplica() const {return new Pescaria (*this);}

};

#endif