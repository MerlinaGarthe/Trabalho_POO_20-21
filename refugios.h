//
// Created by Merlina Garthe on 01/12/2020.
//

#ifndef REFUGIOS_H
#define REFUGIOS_H
#include <iostream>
#include <string>
#include "territorio.h"
using namespace std;
class Refugios : public Territorio
{
    string nome = "Planicie";
    static int num;
    int conta;
    int resistencia = 9;
    int criacao_o = 1;
    int pontos = 2;
public:
    Refugios(string tipo = "planicie",   int resistencia = 9,int criacao_o = 1,int pontos = 2): conta(num++), Territorio(tipo,num,resistencia,0, criacao_o, pontos) {}
    string getAsStringP() const;
};

#endif