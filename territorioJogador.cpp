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

    int j = forcamilitar + random();   //soma se a força militar mais o tal numero random

    if (ter.getTipo() == "Castelo" || ter.getTipo() == "Duna" || ter.getTipo() == "Fortaleza" ||
        ter.getTipo() == "Mina" || ter.getTipo() == "Montanha"  ||
        ter.getTipo() == "Planicie") {
        if (j >= ter.getResis())  //se a forca militar (já somada) for maior à resitencia do suposto territorio
        {

            territorios.push_back(&ter);    //metemos apontar para o tal territorio(não se faz o new porque nós não queremos memoria dinamica mas sim oara que este vetor aponte para o objeto do outro)
            if (ouro < cofremax)


                ouro += ter.getOuro();//soma se o ouro e os produtos da conquist

            if (produtos < armazemmax)
                produtos += ter.getProd();


            pontos += ter.getPontos();
            cout << aviso() << endl;
        }

    }else if (ter.getTipo() == "Pescaria" || ter.getTipo() == "Refugios") {
            if (tam() && encontra()) {
                if (j >= ter.getResis())  //se a forca militar (já somada) for maior à resitencia do suposto territorio
                {

                    territorios.push_back(
                            &ter);    //metemos apontar para o tal territorio(não se faz o new porque nós não queremos memoria dinamica mas sim oara que este vetor aponte para o objeto do outro)
                    if (ouro < cofremax)


                        ouro += ter.getOuro();//soma se o ouro e os produtos da conquist

                    if (produtos < armazemmax)
                        produtos += ter.getProd();


                    if (ter.getTipo() == "refugio" || ter.getTipo() == "pescaria") {
                        pontos += 2 * ter.getPontos();
                    }


                    cout << aviso() << endl;
                }
            }
        else
            {
            cout << "Não possui materiais suficientes para conquistar" << endl;
            }
        } else {
            if (forcamilitar > 0)          // se não conseguir conquistar a força militar diminui
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
        os << territorios[i]->getNome() << "-> Criacao de ouro: " << ouro << ", Criacao de produtos: " << criacao_p << "\n";
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


        if (produtos >= 2)
        {
            if (ouro != cofremax) { // o max é 3 logo se tivemos no max nao incrementa
                ouro++;
            }
            produtos -= 2;
            return true;
        }
        return false;

}

bool TerritorioJogador::maisproduto() {
    if (ouro >= 2)
    {
        if (produtos != armazemmax)
        {
            produtos++;
        }
        ouro -= 2;
        return true;
    }
    return false;
}

int TerritorioJogador::getOuro() {
    return ouro;
}

bool TerritorioJogador::maismilitar() {

        if (forcamilitar != limforca)
        {
            forcamilitar++;
        }
        ouro --;
        produtos--;
        return true;

    return false;
}

bool TerritorioJogador::encontra() {
    for(int i =0; i < tecno.size(); i++)
    {
        if(tecno[i]->getTipo() == "misseis_teleguiados" || tecno[i]->getTipo() == "Misseis_Teleguiados")
            return true;
    }
    return false;
}

string TerritorioJogador::aviso() const {
    ostringstream os;
    os << "Conseguiu conquistar este territorio!" << forcamilitar << endl;
    return os.str();
}


bool TerritorioJogador::tam() {
  if(territorios.size() > 5)
  {
      return true;
  }
    return false;
}

void TerritorioJogador::toma(Territorio &ter) {
    territorios.push_back(&ter);
}

void TerritorioJogador::tomatec(string tipo) {

    if (tipo == "drones_militar" || tipo == "Drones_Militar") {
            tecno.push_back(new Tecnologias(tipo));

    } else if (tipo == "Misseis_Teleguiados" || tipo == "misseis_teleguiados") {
            tecno.push_back(new Tecnologias(tipo));

    } else if (tipo == "defesas_territoriais" || tipo == "Defesas_Territoriais") {

            tecno.push_back(new Tecnologias(tipo));


    } else if (tipo == "Bolsa_de_Valores" || tipo == "bolsa_de_valores") {

            tecno.push_back(new Tecnologias(tipo));

    } else if (tipo == "Banco_Central" || tipo == "banco_central") {
        tecno.push_back(new Tecnologias(tipo));

    }
}

bool TerritorioJogador::mudaOuro(int quant) {
    ouro = quant;
    return true;
}

bool TerritorioJogador::mudaProd(int quant) {
    produtos=quant;
    return true;
}

int TerritorioJogador::randomevento() {
        int x;
        x = 1+rand() % 4;
        return x;

}

void TerritorioJogador::evento() {
    int j;
    j = randomevento();
    cout << j << endl;

    if(j==1)
    {
        cout << "Calhou o Recurso Abandonado" << endl;

        if(ouro < cofremax) {
            ouro += 1; // se estiver no primeiro ano do jogo recebe prod se nao recebe ouro (no segundo)
        }

    }
    else if(j==2)
    {
        cout << "Calhou a Invasão" << endl;
        int k;
        k = randomsorte() + 2; // 2 no primeiro ano e 3 no segundo

        if( k > territorios.back()->getResis())
        {
            if(territorios.size()>=1) {
                territorios.pop_back();

                for (int i = 0; i < tecno.size(); i++) {
                    if (tecno[i]->getTipo() == "defesas_territoriais" || tipo == "Defesas_Territoriais") {
                        resistencia += 1;
                    }
                }
            }
            else
            {
                cout << "VOCE PERDEU IHIHI" << endl;
                //falta aqui mostrar aquelas cenad do fim do jogo
                //O somatório dos pontos de vitória correspondentes aos territórios que integram o seu império;
                //Um ponto adicional por cada tecnologia adquirida;
                //Um ponto adicional caso tenham sido adquiridas 5 tecnologias (bónus científico);
                //Três pontos adicionais se todos os terrenos do mundo fizerem parte do império (é o bónus “imperador supremo”).

                exit;
            }
        }

    }
    else if( j == 3)
    {
        cout << "Calhou Aliança Diplomática" << endl;

        if(forcamilitar < limforca)
        {
            forcamilitar+=1;
        }

    }
    else if(j == 4)
    {
        cout << "Não irá ocorrer nenhum evento" << endl;
    }
}

int TerritorioJogador::randomsorte() {
   int x;
   x= 1+rand() % 6;
    return x;
}

void TerritorioJogador::eventoforcado(string tipo) {

        if(tipo == "Recurso_Abandonado")
        {
            cout << "Calhou o Recurso Abandonado" << endl;

            if(ouro < cofremax) {
                ouro += 1; // se estiver no primeiro ano do jogo recebe prod se nao recebe ouro (no segundo)
            }

        }
        else if(tipo == "Invasão")
        {
            cout << "Calhou a Invasão" << endl;
            int k;
            k = randomsorte() + 2; // 2 no primeiro ano e 3 no segundo

            if( k > territorios.back()->getResis())
            {
                if(territorios.size()>=1) {
                    territorios.pop_back();

                    for (int i = 0; i < tecno.size(); i++) {
                        if (tecno[i]->getTipo() == "defesas_territoriais" || tipo == "Defesas_Territoriais") {
                            resistencia += 1;
                        }
                    }
                }
                else
                {
                    cout << "VOCE PERDEU IHIHI" << endl;
                    //falta aqui mostrar aquelas cenad do fim do jogo
                    //O somatório dos pontos de vitória correspondentes aos territórios que integram o seu império;
                    //Um ponto adicional por cada tecnologia adquirida;
                    //Um ponto adicional caso tenham sido adquiridas 5 tecnologias (bónus científico);
                    //Três pontos adicionais se todos os terrenos do mundo fizerem parte do império (é o bónus “imperador supremo”).

                    exit;
                }
            }

        }
        else if( tipo == "Aliança_Diplomática")
        {
            cout << "Calhou Aliança Diplomática" << endl;

            if(forcamilitar < limforca)
            {
                forcamilitar+=1;
            }

        }
        else if(tipo == "Sem_Evento")
        {
            cout << "Não irá ocorrer nenhum evento" << endl;
        }

}
