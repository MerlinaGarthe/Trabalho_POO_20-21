//
// Created by Merlina Garthe on 01/12/2020.
//

#include "mina.h"
#include <sstream>

int Mina::num = -1;


string Mina::getAsStringM() const
{
    ostringstream os;
    os << "\n" << nome << " \n Resistencia: " << resistencia << " ,com criaÁao de ouro em :" << criacao_o << " unidade, " ;
    return os.str();
}