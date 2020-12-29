//
// Created by Merlina Garthe on 01/12/2020.
//

#ifndef DUNA_H
#define DUNA_H
#include <iostream>
#include <string>
#include "territorio.h"
using namespace std;

class Duna: public Territorio
{
    string nome = "Duna";
    static int num;
    int conta;
    int resistencia;
    int criacao_ouro;
    int criacao_p ;	// produz 1 unidade de produtos
    int pontos ;
public:
    Duna(string tipo = "Duna",   int resistencia = 4,int criacao_p = 1,int criacao_o=1,int pontos = 1): conta (num++), Territorio(tipo,num,resistencia,criacao_p,criacao_o, pontos) {}
    string getAsStringD() const;
};

#endif
