//
// Created by Merlina Garthe on 01/12/2020.
//
#ifndef FORTALEZA_H
#define FORTALEZA_H
#include <iostream>
#include <string>
#include "continente.h"
using namespace std;

class Fortaleza : public Continente
{

    int conta;
    static int num;

public:
    Fortaleza(string tipo = "Fortaleza",   int resistencia = 8,int pontos = 1) : conta(num++), Continente(tipo,num,resistencia,0, 0, pontos) {}
    string getAsStringF() const;
};

#endif