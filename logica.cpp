//
// Created by Merlina Garthe on 18/12/2020.
//

#include "logica.h"
#include <sstream>

bool Logica::addTerritorio(string tipo, int quant) {

    m.addTerritorio(tipo,quant);
    return true;

}

string Logica::mostra() const{

    ostringstream os;

    os << m.getAsString() << endl ;

    return os.str();
}

bool Logica::conquista(string tipo) {
    m.conquista(tipo);
    return true;

}

string Logica ::lista()  {
    ostringstream os;
    os << m.imprimeTudo() << endl;
    return os.str();
}

bool Logica::adquire(string tipo) {
    m.adquire(tipo);
    return true;
}

bool Logica::mouro() {
    m.ouro();
    return true;
}

bool Logica::mproduto() {
    m.produto();
    return true;
}

bool Logica::mmilitar() {
    m.militar();
    return true;
}

string Logica::territorioJogador() {
    ostringstream os;
    os << m.imprimeTerritoriosJogador() << endl;
    return os.str();
}

bool Logica::tomaterr(string tipo) {
    m.toma(tipo);
    return true;
}

bool Logica::tomatec(string tipo) {
    m.tomatec(tipo);
    return true;
}

bool Logica::mudaOuro(int quant) {
    m.mudaOuro(quant);
    return true;
}

bool Logica::mudaProd(int quan) {
    m.mudaProd(quan);
    return true;
}

bool Logica::evento() {
    m.evento();
    return true;
}

bool Logica::eventoforcado(string tipo) {
   m.eventoforcado(tipo);
    return true;
}
