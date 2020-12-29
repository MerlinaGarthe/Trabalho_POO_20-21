//
// Created by Merlina Garthe on 01/12/2020.
//

#include "fortaleza.h"
#include <sstream>

int Fortaleza::num =-1;


string Fortaleza::getAsStringF() const
{
    ostringstream os;
    os << "\n" << nome << " \n Com resistencia: " << resistencia ;
    return os.str();
}