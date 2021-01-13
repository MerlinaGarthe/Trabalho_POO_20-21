//
// Created by Merlina Garthe on 01/12/2020.
//

#include "refugios.h"
#include <sstream>

int Refugios::num = 1;

string Refugios::getAsString() const {
    ostringstream os;
    os << Territorio::getAsString();
    return os.str();
}


