//
// Created by Merlina Garthe on 13/01/2021.
//

#include "logica.h"
#include <sstream>
#include <string>
#include <cctype>

int Logica::fase=0;
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

        if (fase <= 4) {
            if (fase == 4) {
                m.evento();
                turno++;
                fase = 1;
                comandos.clear();
            }
            if(fase==2)
            {

                m.recolha(turno);

            }

        }
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

int Logica::getTurno() {
    return turno;
}

bool Logica::trocabola(int num) {
    m.trocabolsa(num);
    return true;
}

bool Logica::verificabolsa() {
    m.bolsa();
    return true;
}

string Logica::mundoresta() {
    ostringstream os;
    os << m.mundoso() << endl;
    return os.str();
}

string Logica::fimturno() {
    ostringstream os;
    if(getTurno()<=6)
        os << "Ano 1, turno " << getTurno() << endl;
    else if(getTurno()>6)
        os << "Ano 2, turno " << getTurno() << endl;
    os << "Os seus territorios:\n" << m.imprimeTerritoriosJogador() << endl;
    os << "Territorios restantes no mundo:\n " << m.mundoso() << endl;
    os << "Dados: \n" << m.juntos() ;
    os << tecnologias() << endl;
    return os.str();
}

string Logica::tecnologias() {
   ostringstream os;
   os << "Tecnologias disponiveis para compra: " << endl;
   os << "-> Drones Militares (o limite da força militar passa a 5): preço 3 unidades de ouro" << endl;
   os << "-> Misseis Teleguiados (tecnologia necessária para conquistar ilhas): preço 4 unidades de ouro"<< endl;
   os << "-> Defesas Territoriais (equipamento especial de defesa que acrescenta 1 unidade à resitência): preco 4 unidades de ouro" << endl;
   os << "-> Bolsa Valores (sistema comercial que torna possíveis as trocas entre produtos e ouro): preço 2 unidades de ouro" << endl;
   os << "-> Banco Central (ao ser adquirida, esta tecnologia permite aumentar em duas unidades a capacidade de armazenamento do armazém e do cofre do império: passam poder armazenar até 5 de produtos e 5 unidades de ouro):" << endl;
    return os.str();
}


