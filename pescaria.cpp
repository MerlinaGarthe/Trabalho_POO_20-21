//
// Created by Merlina Garthe on 01/12/2020.
//

#include "pescaria.h"
#include <sstream>
int Pescaria::num = 1;

string Pescaria::getAsString() const{
    ostringstream os;
    os << Territorio::getAsString();
    return os.str();
}



