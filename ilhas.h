//
// Created by Merlina Garthe on 01/12/2020.
//

#ifndef ILHAS_H
#define ILHAS_H
#include <iostream>
#include <string>
#include "territorio.h"
using namespace std;

class Ilhas : public Territorio
{

public:

Ilhas(string tp, int ct, int resis, int prod, int ou, int pont) :Territorio( tp, ct, resis, prod, ou, pont) {} //construtor que recebe o tipo de territorio

};

#endif