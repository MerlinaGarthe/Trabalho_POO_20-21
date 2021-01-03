//
// Created by Merlina Garthe on 01/12/2020.
//

#ifndef CONTINENTE_H
#define CONTINENTE_H
#include <iostream>
#include <string>
#include "territorio.h"
using namespace std;

class Continente : public Territorio
{


public:

    Continente(string tp, int ct, int resis, int prod, int ou, int pont) :Territorio( tp, ct, resis, prod, ou, pont) {} //construtor que recebe o tipo de territorio

};
#endif