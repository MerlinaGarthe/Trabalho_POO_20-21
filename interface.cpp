//
// Created by Merlina Garthe on 01/12/2020.
//
#include "interface.h"
#include <string>
#include <fstream>
#include <sstream>
#include "logica.h"

int Interface::fase=1;
int Interface::flag=0;

void Interface::comandosi() //aqui vamos verificar os comando cria, lista e carrega (e conquista)
{
    string comando, comando_cmp, tipo_t, fich, comando_cmp1, tipo_t1, nome, tipo;
    int quantidade, quantidade1;

        do {

            cout << "Introduza o comando pretendido: ";
            getline(cin, comando);

            istringstream is(
                    comando); // o is contem o conteudo do comando para os posteriormente podermos dividir e comparar
            is>> comando_cmp;//>> tipo_t >> quantidade >> tipo; //aqui a string vai ser dividida e o comando_cmp = cria/carrega..., o tipo_t= castelo..., o quantidade= nº desejado

            if (comando_cmp == "cria") {
                if (is >> tipo_t && is >> quantidade) {
                    logica.addTerritorio(tipo_t, quantidade);
                    quantidade = 1;
                    tipo_t = " ";
                }
            } else if (comando_cmp == "carrega") {
                string linha;
                is >> tipo_t;
                ifstream arq(tipo_t);

                if (arq.is_open())//vê se o ficheiro esta aberto
                {
                    while (!arq.eof()) //enquanto não chegar ao fim do ficheiro
                    {
                        getline(arq, linha);

                        istringstream os(
                                linha); // o os contem o conteudo da linha do ficheiro para os posteriormente podermos dividir e comparar
                        os >> comando_cmp1;
                        if (comando_cmp1 == "cria") {

                            os >> tipo_t1 >> quantidade1;
                            logica.addTerritorio(tipo_t1, quantidade1);
                            quantidade1 = 1;
                            tipo_t1 = " ";

                        } else if (comando_cmp1 == "conquista") {
                            os >> tipo_t1;
                            //logica.conquista(tipo_t1);
                            cmd = logica.getAs1(comando_cmp1, tipo_t1);
                            logica.addcomando(cmd);
                            tipo_t1 = " ";

                        }

                    }
                    arq.close(); //no fim fecha o arquivo
                } else {
                    cout << "ERRO: ao abrir o ficheiro ou o ficheiro nao existe!! \n";
                }


            } else if (comando_cmp == "lista") {
                if (is >> tipo_t) {
                    mostra(tipo_t);
                    tipo_t = " ";

                } else {
                    cout << logica.lista() << endl;
                    tipo_t = " ";
                    comando_cmp = " ";
                }
            } else if (comando_cmp == "conquista") {
                if(logica.getfase()==1) {
                    if (is >> tipo_t)
                        // logica.conquista(tipo_t);
                        cmd = logica.getAs1(comando_cmp, tipo_t);
                    logica.addcomando(cmd);
                    logica.conquista();
                }
                else
                {
                    cout << "comando impossivel nesta fase" << endl;
                }

            } else if (comando_cmp == "passa")
            {
                if(logica.getfase()==1 ) {
                    cout << "Nenhum territorio foi conquistado" << endl;
                }
                else
                {
                    cout << "comando impossivel nesta fase" << endl;
                }
            }
            else if (comando_cmp == "adquire") {
                if(logica.getfase()==3) {
                    if (is >> tipo_t >> tipo)
                        tipo = logica.getAs1(tipo_t, tipo);
                    cmd = logica.getAs1(comando_cmp, tipo);
                    logica.addcomando(cmd);
                    //logica.adquire(cmd);
                    logica.adquire();
                }
            }
            else if (comando_cmp == "maisouro") {
                logica.mouro();
                logica.getAs2(comando_cmp);
            }
            else if (comando_cmp == "maisprod") {
                logica.mproduto();
                logica.getAs2(comando_cmp);
            }
            else if (comando_cmp == "maismilitar") {
                logica.mmilitar();
                logica.getAs2(comando_cmp);
            }
            else if (comando_cmp == "toma") {
                if (is >> tipo_t) {
                    if (tipo_t == "tec") {
                        if (is >> tipo)
                            logica.tomatec(tipo);
                    } else if (tipo_t == "terr") {
                        if (is >> tipo) {

                            logica.tomaterr(tipo);
                        }
                    }
                }
            }
            else if (comando_cmp == "modifica") {
                if (is >> tipo_t && is >> quantidade) {
                    if (tipo_t == "ouro") {
                        logica.mudaOuro(quantidade);
                    }
                    else if (tipo_t == "prod") {
                        logica.mudaProd(quantidade);
                    }
                }
            }
            else if (comando_cmp == "evento") {
                    logica.evento();
                logica.getAs2(comando_cmp);
            }
            else if (comando_cmp == "fevento") {
                if (is >> tipo_t)
                    logica.eventoforcado(tipo_t);
            }
             else if (comando_cmp == "avanca") {
                logica.avanca();
                logica.getAs2(comando_cmp);
            }
        } while (comando != "terminar");

    }

    void Interface::mostra(string tipo) {
        if (tipo == "tudo") {
            cout << logica.mostra() << endl;
        } else if (tipo == "meu") {
            cout << logica.territorioJogador() << endl;

        } else if (tipo == "cmd") {
            cout << logica.mostraCmd() << endl;
        } else {
            cout << logica.cadamostra(tipo);
        }


    }
