//
// Created by Merlina Garthe on 18/12/2020.
//

#ifndef UNTITLED1_LOGICA_H
#define UNTITLED1_LOGICA_H
#include "mundo.h"
#include <iostream>

using namespace std;

class Logica {
    Mundo m;

public:
    bool addTerritorio(string tipo, int quant);
    string mostra() const ;
    bool conquista(string tipo);
    string lista() ;
    bool adquire(string tipo);
    bool mouro();
    bool mproduto();
    bool mmilitar();
    string territorioJogador();
    bool tomaterr(string tipo);
    bool tomatec(string tipo);
    bool mudaOuro(int quant);
    bool mudaProd(int quant);
    bool evento();
    bool eventoforcado(string tipo);
};

#endif //UNTITLED1_LOGICA_H
