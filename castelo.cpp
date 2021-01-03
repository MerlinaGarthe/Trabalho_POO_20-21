//
// Created by Merlina Garthe on 01/12/2020.
//

#include "castelo.h"
#include <sstream>

int Castelo::num = 1;

string Castelo::getAsString() const {
    ostringstream os;
    os << Territorio::getAsString();
    return os.str();
}