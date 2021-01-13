//
// Created by Merlina Garthe on 01/12/2020.
//

#include "duna.h"
#include <sstream>

int Duna::num = 1;

string Duna::getAsString() const {
    ostringstream os;
    os << Territorio::getAsString();
    return os.str();
}



