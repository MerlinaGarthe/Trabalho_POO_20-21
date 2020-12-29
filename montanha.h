//
// Created by Merlina Garthe on 01/12/2020.
//

#ifndef MONTANHA_H
#define MONTANHA_H
#include <string>
#include <iostream>
#include "continente.h"
#include "territorio.h"
using namespace std;

class Montanha : public Territorio
{
    string nome = "Montanha";
    int conta;
    static int num;
    int resistencia = 6;
    int criacao_p = 0;	// primeiros 2 turnos dps de ser conquistado produz zero, depois produz 1
    int criacao_o = 0;
    int pontos = 1;
public:
    Montanha(string tipo = "montanha",   int resistencia = 6,int criacao_p = 0,int criacao_o = 0,int pontos = 1): conta(num++), Territorio(tipo,num,resistencia,criacao_p, criacao_o, pontos) {}
    string getAsStringMO() const;
};

#endif