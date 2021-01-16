//
// Created by Merlina Garthe on 01/12/2020.
//

#include "castelo.h"
#include <sstream>

int Castelo::num = 1;

Castelo::Castelo(string tp, int resistencia, int pontos): conta (num++),Continente(tp,num,resistencia,p, o, pontos)  {

}

string Castelo::getAsString() const {
    ostringstream os;
    os << Territorio::getAsString();
    return os.str();
}




