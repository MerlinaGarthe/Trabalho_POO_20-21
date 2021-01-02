//
// Created by Merlina Garthe on 01/12/2020.
//

#include "interface.h"
#include <string>
#include <fstream>
#include <sstream>




void Interface::comandosi() //aqui vamos verificar os comando cria, lista e carrega (e conquista)
{
    string comando, comando_cmp, tipo_t, fich, comando_cmp1, tipo_t1,nome;
    int quantidade, quantidade1;
    do
    {
        cout << "Introduza o comando pretendido: ";
        getline(cin, comando);

        istringstream is(comando); // o is contem o conteudo do comando para os posteriormente podermos dividir e comparar
        is >> comando_cmp >> tipo_t >> quantidade; //aqui a string vai ser dividida e o comando_cmp = cria/carrega..., o tipo_t= castelo..., o quantidade= nº desejado

        if (comando_cmp == "cria")
        {

            //m.addTerritorio(tipo_t, quantidade);//vou mandar o tipo e quantidade para a lógica para adicionar um novo território
          m.addTerritorio(tipo_t,quantidade);
           //logica.addTerritorio(tipo_t,quantidade);


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
                    cout << linha << endl; //mostro conteúdo do ficheiro

                    istringstream os(linha); // o os contem o conteudo da linha do ficheiro para os posteriormente podermos dividir e comparar
                    os >> comando_cmp1;
                    if (comando_cmp1 == "cria")
                    {

                        os >> tipo_t1 >> quantidade1;

                        m.addTerritorio(tipo_t1, quantidade1);
                        quantidade1=1;
                        tipo_t1 = ' ';

                    }
                    else if(comando_cmp1 == "conquista")
                    {
                        os >> tipo_t1;
                        m.conquista(tipo_t1);
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
                cout << m.imprimeTudo() << endl;
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

            m.conquista(tipo_t);
        }
        else if(comando_cmp == "passa")
        {
            cout << "Nenhum territorio foi conquistado" << endl;
        }
        else if(comando_cmp == "adquire")
        {
           m.adquire(tipo_t);

        }
        else if(comando_cmp == "maisouro")
        {
            m.ouro();
        }
        else if(comando_cmp == "maisprod")
        {
            m.produto();
        }
        else if(comando_cmp == "maismilitar")
        {
            m.militar();
        }

    } while (comando != "terminar");
}

void Interface::mostra(string tipo)
{
    if (tipo == "tudo")
    {
        cout << m.imprimeTudo() << endl;
      cout << m.getAsString() << endl; //este é o que falta, o resto serve para mostrar a informação de cada cena (AH AINDA NÃO CRIEI A CENAS DAS ILHAS TEMOS DE FAZER ISSO MAS O PROCESSO É IGUAL)

    }
    else if (tipo == "meu")
    {
        cout << m.imprimeTerritoriosJogador() << endl;

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