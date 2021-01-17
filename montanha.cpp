//
// Created by Merlina Garthe on 01/12/2020.
//

#include "montanha.h"
#include <sstream>

int Montanha::num = 1;

string Montanha::getAsString() const {
    ostringstream os;
    os << Territorio::getAsString();
    return os.str();
}



