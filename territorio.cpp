//
// Created by Merlina Garthe on 01/12/2020.
//

#include "territorio.h"
#include <sstream>



string Territorio::getNome() const
{

    return nome;
}

string Territorio::getTipo() const
{
    return tipo;
}

int Territorio::getResis()
{
    return resistencia;
}

int Territorio::getOuro()
{
    return Ouro;
}
int Territorio::getProd()
{
    return Produtos;
}
int Territorio::getPontos()
{
    return pontos;
}

string Territorio::getAsString() const {
   ostringstream os;
   os << nome;
   os << ",Resistencia-> " << resistencia  << endl;
  return os.str();
}

void Territorio::Nome()  {
   ostringstream os;
   os << tipo << conta;
   nome = os.str();
}

Territorio::Territorio(string tp, int ct, int resis, int prod, int ou, int pont): tipo(tp), conta(ct), resistencia(resis), Produtos(prod), Ouro(ou),pontos(pont) {
    Nome();
    getOuro();
    getPontos();
    getProd();
    getResis();
}
