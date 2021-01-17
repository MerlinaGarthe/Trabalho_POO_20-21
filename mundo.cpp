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
#include "territorioI.h"
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

    if(tipo == "planicie" || tipo == "Planicie") {
        for (int i = 0; i < quantidade; i++) {
            te.push_back(new Planicie());// vamos adicionar territoirios ao nosso vetor de territorio

        }
        return true;
    }
        if (tipo == "pescaria" || tipo == "Pescaria") {
            for (int i = 0; i < quantidade; i++) {
                te.push_back(new Pescaria());// vamos adicionar territoirios ao nosso vetor de territorio

            }
            return true;
        }
        if (tipo == "refugios" || tipo == "Refugios") {
            for (int i = 0; i < quantidade; i++) {
                te.push_back(new Refugios());// vamos adicionar territoirios ao nosso vetor de territorio

            }
            return true;

    }


    return false;


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


bool Mundo::conquista(string nome) //aqui só vou ver se o territorio que quero existe
{

    for (int i = 0; i < (int)te.size(); i++)
    {

        if (te[i]->getNome()==nome )
        {
            tj.conquista(*te[i]);   // se sim envio esse territorio para este funçã
            tj.verifica(*te[i]);

        }

    }

    return true;
}

bool Mundo::adquire(string tipo)  {

   tj.adquire(tipo);
    return true;
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


//esta toma serve para o comando toma que serve para o DEBUG
bool Mundo::toma(string nome) {

    for (int i = 0; i < (int)te.size(); i++)
    {

        if (te[i]->getNome()==nome )
        {

            tj.toma(*te[i]);   // se sim envio esse territorio para este função
        }

    }

    return true;
}

void Mundo::tomatec(string tipo) {
    return tj.tomatec(tipo);
}

bool Mundo::mudaOuro(int quantidade) {
   tj.mudaOuro(quantidade);
    return true;
}

bool Mundo::mudaProd(int quantidade) {
    tj.mudaProd(quantidade);
    return true;
}

void Mundo::evento() {
    return tj.evento();
}

void Mundo::eventoforcado(string tipo) {
    return tj.eventoforcado(tipo);
}

string Mundo::cadamostra(string nome) {
    ostringstream os;
    for(int i=0; i< te.size(); i++)
    {
        if(te[i]->getNome() == nome)
        {
            os << te[i]->getAsString() << endl;
        }
    }
    return os.str();
}

string Mundo::mostraPontos() {
    return tj.aviso_final();
}

bool Mundo::recolha(int f) {
    tj.recolha(f);
    return true;
}

bool Mundo::bolsa() {
    if(tj.verificaBolsa())
        return true;
    else
        return false;
}

bool Mundo::trocabolsa(int m) {
    tj.trocabols(m);
        return true;
}

string Mundo::mundoso() {
    ostringstream os;
    for(int i=0; i<te.size(); i++)
    {
        if(tj.verifica(*te[i]))
            os << "Nome :" << te[i]->getNome() << " Resistencia:" << te[i]->getResis() <<endl;
    }
    return os.str();
}

string Mundo::juntos() {
    ostringstream os;
    os << tj.stringjuntas() << endl;
    return os.str();
}

string Mundo::todos() {
    ostringstream os;
    os << tj.cadaterr() << endl;
    return os.str();
}

Mundo::Mundo(const Mundo& ob) {
    *this = ob;
}


Mundo &Mundo::operator=(const Mundo &novo) {
    if (this == &novo) {
        return *this;
    }

    for (unsigned int i = 0; i < te.size(); i++) {
        delete te[i];
    }
    te.clear();

    for (unsigned int i = 0; i < novo.te.size(); i++) {
        Territorio* t = novo.te[i]->duplica();
        te.push_back(t);

    }
    return *this;
}















