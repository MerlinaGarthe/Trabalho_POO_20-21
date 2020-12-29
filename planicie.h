//
// Created by Merlina Garthe on 01/12/2020.
//

#ifndef PLANICIE_H
#define PLANICIE_H
#include <iostream>
#include <string>
#include "territorio.h"
using namespace std;

class Planicie : public Territorio
{
    string nome = "Planicie";
    static int num;
    int conta;
    int resistencia = 5;
    int criacao_p = 0;	//aumenta 1 em cada turno (1ano), aumento 2 em cada turno (2turno)
    int criacao_o = 0;	//aumenta 1 em cada turno (1ano), aumento 1 em cada turno (2turno)
    int pontos = 1;
public:
    Planicie(string tipo = "planicie",   int resistencia = 5,int criacao_p = 0,int criacao_o = 0,int pontos = 1): conta(num++), Territorio(tipo, num,resistencia,criacao_p, criacao_o, pontos) {}
    string getAsStringP() const;
};

#endif // !1