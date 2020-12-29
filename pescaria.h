//
// Created by Merlina Garthe on 01/12/2020.
//

#ifndef PESCARIA_H
#define PESCARIA_H
#include <iostream>
#include <string>
#include "territorio.h"
using namespace std;

class Pescaria : public Territorio
{
    string nome = "Pescaria";
    int conta;
    static int num;
    int resistencia ;
    int criacao_p ;
    int pontos ;
public:
    Pescaria(string tipo = "Pescaria",   int resis = 9, int p = 2,int pon = 2): conta(num++), Territorio(tipo, num,resis,p,0, pon) {}

    string getAsStringP() const;
};

#endif