//
// Created by Merlina Garthe on 01/12/2020.
//

#include "refugios.h"
#include <sstream>

int Refugios::num = -1;

string Refugios::getAsStringP() const
{
    ostringstream os;

    os << "\n" << nome << " \n Resistencia :" << resistencia << " Com criaÁao de ouro em :" << criacao_o << " unidade, " ;
    return os.str();
}