//
// Created by Merlina Garthe on 01/12/2020.
//

#ifndef CASTELO_H
#define CASTELO_H
#include <iostream>
#include <string>
#include <sstream>
#include "territorio.h"
using namespace std;



class Castelo : public Territorio
{
    static int num;
    int conta;

public:
    Castelo(string tp = "Castelo",   int resistencia = 7,int criacao_p = 0,int criacao_o = 0,int pontos = 1) : conta (num++),Territorio(tp,num,resistencia,criacao_p, criacao_o, pontos) {}
    string getAsString() const;
};

#endif