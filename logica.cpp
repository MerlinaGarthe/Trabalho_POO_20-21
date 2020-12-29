//
// Created by Merlina Garthe on 18/12/2020.
//

#include "logica.h"
#include <sstream>

bool Logica::addTerritorio(string tipo, int quant) {

     m.addTerritorio(tipo,quant);
    return true;

}

string Logica::mostra() {
   ostringstream os;
   os << m.getAsString() ;
    return os.str();
}
