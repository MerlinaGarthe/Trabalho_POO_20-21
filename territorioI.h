//
// Created by Merlina Garthe on 03/01/2021.
//

#ifndef UNTITLED1_TERRITORIOI_H
#define UNTITLED1_TERRITORIOI_H
#include <string>
#include <iostream>
#include "territorio.h"


using namespace std;

class TerritorioI : public Territorio{
public:
    TerritorioI(string tp = "TerritorioInicial", int resistencia = 9 , int prod=0, int ouro=0, int pontos=0) : Territorio(tp,0,resistencia, prod, ouro, pontos) {}
};



#endif //UNTITLED1_TERRITORIOI_H
