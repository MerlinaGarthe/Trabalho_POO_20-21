//
// Created by Merlina Garthe on 01/12/2020.
//

#include "planicie.h"
#include <sstream>

int Planicie::num = -1;

string Planicie::getAsStringP() const
{
    ostringstream os;

    os << "\n" << nome <<  " \n Resistencia :" << resistencia << " com criacao de produtos em : " << criacao_p << " unidade, " << " Com criaÁao de ouro em :" << criacao_o << " unidade, " ;
    return os.str();
}