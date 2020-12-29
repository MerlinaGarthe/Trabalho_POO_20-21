//
// Created by Merlina Garthe on 01/12/2020.
//

#include "territorioJogador.h"
#include "mundo.h"
#include "territorio.h"
#include <sstream>
#include <string>



TerritorioJogador::TerritorioJogador() {

     armazemmax = 3;	//quantidade maxima
     cofremax = 3;		//quantidade maxima
     resistencia = 9;
   criacao_p = 0;
   criacao_o =0;
   pontos = 0;
   forcamilitar =3; //Nivel de forÁa militar, falta fazer o nivel
   limforca=3;
   ouro =0;
    produtos=0;
}
TerritorioJogador::~TerritorioJogador()
{
    for(auto c : territorios)
    {
        delete c;
    }
    territorios.clear();
}

int TerritorioJogador::random() {
   //srand((unsigned)time(NULL));
    int x;
    x = rand() % 7;
    return x;
}



void TerritorioJogador::conquista(Territorio &ter) {

    int j=forcamilitar + random();   //soma se a força militar mais o tal numero random

    if(j>= ter.getResis())  //se a forca militar (já somada) for maior à resitencia do suposto territorio
    {

        territorios.push_back(&ter);    //metemos apontar para o tal territorio(não se faz o new porque nós não queremos memoria dinamica mas sim oara que este vetor aponte para o objeto do outro)
        if(ouro < cofremax)


           ouro +=  ter.getOuro() ;//soma se o ouro e os produtos da conquist

        if(produtos < armazemmax)
            produtos += ter.getProd();


        if(ter.getTipo() == "refugio"  || ter.getTipo()=="pescaria")
        {
            pontos +=2* ter.getPontos();
        }
        else
            pontos += ter.getPontos();

    }
    else
    {
        if(forcamilitar>0)          // se não conseguir conquistar a força militar diminui
            forcamilitar--;

    }

}

string TerritorioJogador::getAsString() const
{
    ostringstream os;

    for (int i = 0; i < (int)territorios.size(); i++)	//percorre o vetor
    {
        os << territorios[i]->getNome() << "-> Criacao de ouro: " << ouro << ", Criacao de produtos: " << produtos<< "\n";
        //os << "Pontos vitoria do Imperio: " << pontos << "\n";


    }
    for(int j= 0 ; j < (int)tecno.size();j++)
    {
        os << tecno[j]->getTipo()<< endl;
    }
    return os.str();
}
string TerritorioJogador::getAsString2() const
{
    ostringstream os;

    for (int i = 0; i < (int)territorios.size(); i++)	//percorre o vetor
    {
        os << territorios[i]->getNome() << "-> Criacao de ouro: " << criacao_o << ", Criacao de produtos: " << criacao_p << "\n";
        os << "Pontos vitoria do Imperio: " << pontos << "\n";
        os << "Resistencia ->" << resistencia << " ,ForçaMilitar -> " << forcamilitar << endl;

    }
    return os.str();
}
string TerritorioJogador::getForcaMil() {


    ostringstream os;
    os << "Força militar do territorio inicial:" << forcamilitar << endl;
    return os.str();

}

string TerritorioJogador::getResis() {
    ostringstream os;
    os << "A resistencia é: " << resistencia << endl;
    return os.str();
}

void TerritorioJogador::adquire(string tipo) {

    if (tipo == "drones_militar" || tipo == "Drones_Militar") {


        if (ouro >= 3) {

            limforca = 5;
            ouro -= 3;
            tecno.push_back(new Tecnologias(tipo));

        }

    } else if (tipo == "Misseis_Teleguiados" || tipo == "misseis_teleguiados") {
        if (ouro >= 4) {
            ouro -= 4;
            tecno.push_back(new Tecnologias(tipo));

        }
    } else if (tipo == "defesas_territoriais" || tipo == "Defesas_Territoriais") {
        if (ouro >= 4) {
            resistencia++;
            ouro -= 4;
            tecno.push_back(new Tecnologias(tipo));

        }
    } else if (tipo == "Bolsa_de_Valores" || tipo == "bolsa_de_valores") {
        if (ouro >= 2) {
            tecno.push_back(new Tecnologias(tipo));

        }
    } else if (tipo == "Banco_Central" || tipo == "banco_central") {
        tecno.push_back(new Tecnologias(tipo));

        if (cofremax <= 5 && armazemmax <= 5) {
            cofremax = 5;
            armazemmax = 5;
        }


    }

}




bool TerritorioJogador::maisOuro() {

    cout << produtos;
    return true;
        /*if (produtos >= 2)
        {
            cout << "LALALALAALLA";
            if (ouro != cofremax) { // o max é 3 logo se tivemos no max nao incrementa
                ouro++;
            }
            produtos -= 2;
            return true;
        }
        return false;*/

}

int TerritorioJogador::getOuro() {
    return ouro;
}



