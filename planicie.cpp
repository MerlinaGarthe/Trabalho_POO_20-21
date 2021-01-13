//
// Created by Merlina Garthe on 01/12/2020.
//

#include "planicie.h"
#include <sstream>

int Planicie::num = 1;

string Planicie::getAsString() const {
    ostringstream os;
    os << Territorio::getAsString();
    return os.str();
}

