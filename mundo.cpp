//
// Created by Merlina Garthe on 01/12/2020.
//

#include "mundo.h"
#include "territorio.h"
#include "territorioJogador.h"
#include "castelo.h"
#include "duna.h"
#include "fortaleza.h"
#include "mina.h"
#include "montanha.h"
#include "pescaria.h"
#include "planicie.h"
#include "refugios.h"
#include <sstream>
#include <string>

Mundo::~Mundo()
{
    for(auto c : te)
    {
        delete c;
    }
    te.clear();
}


bool Mundo::addTerritorio(string tipo, int quantidade)
{

    //if (tipo == "castelo" || tipo == "duna" || tipo == "fortaleza" || tipo == "mina" || tipo == "montanha" || tipo == "pescaria" || tipo == "planicie" || tipo == "refugios") {
        if(tipo == "castelo" || tipo == "Castelo") {
            for (int i = 0; i < quantidade; i++) {
                te.push_back(new Castelo());// vamos adicionar territoirios ao nosso vetor de territorio

            }
            return true;
       }
    if(tipo == "duna" || tipo == "Duna") {
        for (int i = 0; i < quantidade; i++) {
            te.push_back(new Duna());// vamos adicionar territoirios ao nosso vetor de territorio

        }
        return true;
    }
    if(tipo == "fortaleza" || tipo == "Fortaleza") {
        for (int i = 0; i < quantidade; i++) {
            te.push_back(new Fortaleza());// vamos adicionar territoirios ao nosso vetor de territorio

        }
        return true;
    }
    if(tipo == "mina" || tipo == "Mina") {
        for (int i = 0; i < quantidade; i++) {
            te.push_back(new Mina());// vamos adicionar territoirios ao nosso vetor de territorio

        }
        return true;
    }
    if(tipo == "montanha" || tipo == "Montanha") {
        for (int i = 0; i < quantidade; i++) {
            te.push_back(new Montanha());// vamos adicionar territoirios ao nosso vetor de territorio

        }
        return true;
    }
    if(tipo == "pescaria" || tipo == "Pescaria") {
        for (int i = 0; i < quantidade; i++) {
            te.push_back(new Pescaria());// vamos adicionar territoirios ao nosso vetor de territorio

        }
        return true;
    }
    if(tipo == "planicie" || tipo == "Planicie") {
        for (int i = 0; i < quantidade; i++) {
            te.push_back(new Planicie());// vamos adicionar territoirios ao nosso vetor de territorio

        }
        return true;
    }
    if(tipo == "refugios" || tipo == "Refugios") {
        for (int i = 0; i < quantidade; i++) {
            te.push_back(new Refugios());// vamos adicionar territoirios ao nosso vetor de territorio

        }
        return true;
    }
   // }
    //return false;


}
string  Mundo::imprimeMeu() {
    return tj.getForcaMil();
}
string Mundo::getAsString() const
{
    ostringstream os;

    for (int i = 0; i < (int)te.size(); i++)	//percorre o vetor
    {
        os << te[i]->getAsString() <<endl;
    }
    return os.str();
}

string Mundo::imprimeTerritoriosJogador()
{
   return tj.getAsString();

}
string Mundo :: imprimeTudo()
{
    return tj.getAsString2();
}
bool Mundo::conquista(string nome) //aqui só vou ver se o territorio que quero existe
{

    for (int i = 0; i < (int)te.size(); i++)
    {

        if (te[i]->getNome()==nome )
        {

            tj.conquista(*te[i]);   // se sim envio esse territorio para este função
        }

    }

    return true;
}

void Mundo::adquire(string tipo)  {
    return tj.adquire(tipo);
}

bool Mundo::ouro() {
    tj.maisOuro();
    return true;
}

bool Mundo::produto() {
    tj.maisproduto();
    return true;
}

bool Mundo::militar() {
    tj.maismilitar();
    return true;
}







