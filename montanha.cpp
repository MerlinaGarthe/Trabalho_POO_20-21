//
// Created by Merlina Garthe on 01/12/2020.
//

#include "montanha.h"
#include <sstream>

int Montanha::num =-1;

string Montanha::getAsStringMO() const
{
    ostringstream os;
    os << "\n" << nome << " \n Resistencia: " << resistencia << "  ,com criacao de produtos em : " << criacao_p << " unidade, " << " Com criaÁao de ouro em :" << criacao_o << " unidade, " ;
    return os.str();
}