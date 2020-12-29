//
// Created by Merlina Garthe on 01/12/2020.
//

#include "duna.h"
#include <sstream>

int Duna::num = -1;


string Duna::getAsStringD() const
{
    ostringstream os;

    os << "\n" << nome  << "\n Resistencia:" << resistencia << " com criacao de produtos em : " << criacao_p << " unidade, " ;
    return os.str();
}