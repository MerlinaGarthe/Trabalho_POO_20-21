//
// Created by Merlina Garthe on 01/12/2020.
//
#include "interface.h"
#include <string>
#include <fstream>
#include <sstream>
#include "logica.h"



void Interface::comandosi() //aqui vamos verificar os comando cria, lista e carrega (e conquista)
{
    string comando, comando_cmp, tipo_t, fich, comando_cmp1, tipo_t1,nome, tipo;
    int quantidade, quantidade1;
    do
    {
        cout << "Introduza o comando pretendido: ";
        getline(cin, comando);

        istringstream is(comando); // o is contem o conteudo do comando para os posteriormente podermos dividir e comparar
        is >> comando_cmp >> tipo_t >> quantidade >> tipo; //aqui a string vai ser dividida e o comando_cmp = cria/carrega..., o tipo_t= castelo..., o quantidade= nº desejado

        if (comando_cmp == "cria")
        {

            logica.addTerritorio(tipo_t,quantidade);


            quantidade=1;
            tipo_t = ' ';

        }
        else if (comando_cmp == "carrega")
        {
            string linha;
            ifstream arq(tipo_t);

            if (arq.is_open())//vê se o ficheiro esta aberto
            {
                while (!arq.eof()) //enquanto não chegar ao fim do ficheiro
                {
                    getline(arq, linha);

                    istringstream os(linha); // o os contem o conteudo da linha do ficheiro para os posteriormente podermos dividir e comparar
                    os >> comando_cmp1;
                    if (comando_cmp1 == "cria")
                    {

                        os >> tipo_t1 >> quantidade1;
                        logica.addTerritorio(tipo_t1, quantidade1);
                        quantidade1=1;
                        tipo_t1 = ' ';

                    }
                    else if(comando_cmp1 == "conquista")
                    {
                        os >> tipo_t1;
                        logica.conquista(tipo_t1);
                        tipo_t1 = ' ';

                    }

                }
                arq.close(); //no fim fecha o arquivo
            }
            else
            {
                cout << "ERRO: ao abrir o ficheiro ou o ficheiro nao existe!! \n";
            }



        }
        else if (comando_cmp == "lista")
        {
            if(tipo_t == "") {
                cout << logica.lista() << endl;
                tipo_t = ' ';
                comando_cmp = ' ';
            }
            else {
                mostra(tipo_t);
                tipo_t = ' ';
            }
        }
        else if(comando_cmp == "conquista")
        {

            logica.conquista(tipo_t);
        }
        else if(comando_cmp == "passa")
        {
            cout << "Nenhum territorio foi conquistado" << endl;
        }
        else if(comando_cmp == "adquire")
        {
            logica.adquire(tipo_t);

        }
        else if(comando_cmp == "maisouro")
        {
            logica.mouro();
        }
        else if(comando_cmp == "maisprod")
        {
            logica.mproduto();
        }
        else if(comando_cmp == "maismilitar")
        {
            logica.mmilitar();
        }
        else if(comando_cmp == "toma")
        {
            if(tipo_t == "tec")
            {
                logica.tomatec(tipo);
            }
            else if( tipo_t == "terr")
            {
                logica.tomaterr(tipo);
            }
        }
        else if(comando_cmp == "modifica")
        {
            if(tipo_t == "ouro")
            {
                logica.mudaOuro(quantidade);
            }
            else if(tipo_t == "prod")
            {
                logica.mudaProd(quantidade);
            }
        }
        else if(comando_cmp == "evento")
        {
            logica.evento();
        }
        else if (comando_cmp == "fevento")
        {
            logica.eventoforcado(tipo_t);
        }

    } while (comando != "terminar");
}

void Interface::mostra(string tipo)
{
    if (tipo == "tudo")
    {
        cout << logica.mostra()  << endl;
    }
    else if (tipo == "meu")
    {
        cout << logica.territorioJogador() << endl;

    }

    /* else if (tipo == "castelo")
      {
         cout << c.getAsString() << endl;
            /*else if (tipo == "duna")
      {
          cout << d.getAsStringD() << endl;
      }
      else if (tipo == "fortaleza")
      {
          cout << f.getAsStringF() << endl;
      }
      else if (tipo == "mina")
      {
          cout << mina.getAsStringM() << endl;
      }
      else if (tipo == "montanha")
      {
          cout << montanha.getAsStringMO() << endl;
      }
      else if (tipo == "planicie")
      {
          cout << p.getAsStringP() << endl;
      }
      else if (tipo == "pescaria")
      {
          cout << pesc.getAsStringP() << endl;
      }
      else if(tipo=="refugio")
      {
          cout << r.getAsStringP() << endl;
      }*/
}
