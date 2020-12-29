//
// Created by Merlina Garthe on 01/12/2020.
//
#ifndef FORTALEZA_H
#define FORTALEZA_H
#include <iostream>
#include <string>
#include "territorio.h"
using namespace std;

class Fortaleza : public Territorio
{
    string nome = "Fortaleza";
    int conta;
    static int num;
    int resistencia = 8;
    int pontos = 1;
public:
    Fortaleza(string tipo = "Fortaleza",   int resistencia = 8,int pontos = 1) : conta(num++), Territorio(tipo,num,resistencia,0, 0, pontos) {}
    string getAsStringF() const;
};

#endif