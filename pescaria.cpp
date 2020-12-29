//
// Created by Merlina Garthe on 01/12/2020.
//

#include "pescaria.h"
#include <sstream>
int Pescaria::num =-1;


string Pescaria::getAsStringP() const
{
    ostringstream os;

    os << "\n" << nome << " \n Resistencia :" << resistencia << " Com criaÁao de produtos em :" << criacao_p << " unidade, " ;
    return os.str();
}