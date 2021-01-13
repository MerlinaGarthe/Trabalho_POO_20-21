//
// Created by Merlina Garthe on 01/12/2020.
//

#include "mina.h"
#include <sstream>

int Mina::num = 1;

string Mina::getAsString() const {
    ostringstream os;
    os << Territorio::getAsString();
    return os.str();
}


