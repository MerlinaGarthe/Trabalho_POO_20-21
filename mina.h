//
// Created by Merlina Garthe on 01/12/2020.
//

#ifndef MINA_H
#define MINA_H
#include <iostream>
#include <string>
#include "territorio.h"
using namespace std;
class Mina : public Territorio
{
    string nome = "Mina";
    int conta;
    static int num;
    int resistencia = 5;
    int criacao_o = 0;	//primeiros 3 turnos produz 1 unidade e nos segundos 3 turnos produz duas unidades
    int pontos = 1;

public:
    Mina(string tipo= "Mina",   int resistencia = 5,int criacao_o = 0,int pontos = 1): conta(num++), Territorio(tipo,num ,resistencia,0, criacao_o, pontos) {}
    string getAsStringM() const;
};

#endif