//
// Created by Merlina Garthe on 01/12/2020.
//

#include "fortaleza.h"
#include <sstream>

int Fortaleza::num = 1;

string Fortaleza::getAsString() const {
    ostringstream os;
    os << Territorio::getAsString();
    return os.str();
}



