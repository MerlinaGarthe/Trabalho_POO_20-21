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
    string tipo;
    static int num;
    int conta;
    int resistencia ;
    int criacao_p ;	// nos primeiros dois turnos de cada ano produz 3 unidades
    int criacao_o ;	// produz 1 unidade de ouro
    int pontos ;

public:
    Castelo(string tp = "Castelo",   int resistencia = 7,int criacao_p = 0,int criacao_o = 0,int pontos = 1) : conta (num++),Territorio(tp,num,resistencia,criacao_p, criacao_o, pontos) {}
    //string getAsStringC() const;
    //void nomeget() ;
    //string getNome() const;
};

#endif