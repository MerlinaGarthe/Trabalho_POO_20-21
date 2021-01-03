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


public:
    Mina(string tipo= "Mina",   int resistencia = 5,int criacao_o = 0,int pontos = 1): conta(num++), Continente(tipo,num ,resistencia,0, criacao_o, pontos) {}
    string getAsStringM() const;
};

#endif