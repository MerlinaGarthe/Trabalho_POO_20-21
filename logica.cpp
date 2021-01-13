//
// Created by Merlina Garthe on 13/01/2021.
//

#include "logica.h"
#include <sstream>
#include <string>
#include <cctype>

int Logica::fase=1;
int Logica::turno=1;

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

string Logica::cadamostra(string nome) {
    ostringstream os;
    os << m.cadamostra(nome) << endl;
    return os.str();
}


bool Logica::avanca() {
    if(turno!=12) {
        fase++;
        if(turno<=6)
            cout <<"ANO 1, turno: " << turno << " ,fase " << fase << endl;
        else
            cout << "ANO 2, turno: "<< turno << " ,fase " << fase << endl;

        if (fase <= 4) {
            if (fase == 4) {
                cout << "EVENTO: " << endl;
                m.evento();
                turno++;
                fase = 1;
                comandos.clear();
            }
            if(fase==2)
            {
                cout << "Recolha de bens! " << endl;
                m.recolha(turno);
                fase++;
            }

        }
    }
    else
    { cout << aviso_final() << endl;exit(0);
       }
}
    bool Logica::addcomando(string comando) {

        comandos.push_back((comando));

        return true;
    }


    string Logica::mostraCmd() const{
        ostringstream os;
        for(int i=0; i< comandos.size() ; i++)
        {
            os << comandos[i] << endl;
        }
        return os.str();
    }

    string Logica::getAs1(string comando, string tipo) {
        ostringstream os;
        os << comando << " " << tipo;
        return os.str();
    }

    string Logica::getAs2(string comando) {
        ostringstream os;
        os << comando;
        return os.str();
    }

bool Logica::conquista() {

    string comando, tipo;
    for (int i = 0; i < comandos.size(); i++) {
        istringstream is(comandos[i]);
        is >> comando;
        if (comando == "conquista") {
            is >> tipo;
            conquista(tipo);
            break;
        }
    }
}

    int Logica::faseq() {
        return fase;
    }

    bool Logica::adquire() {
        string comando, tipo, tipo_2, nome;
        for (int i = 0; i < comandos.size(); i++) {
            istringstream is(comandos[i]);
            is >> comando;

            if (comando == "adquire") {
                is >> tipo >> tipo_2;
                nome = getAs1(tipo, tipo_2);
                m.adquire(nome);
                break;
            }
        }
    }

    string Logica::aviso_final() {
        return m.mostraPontos();
    }

int Logica::getfase() {
   return fase;
}
