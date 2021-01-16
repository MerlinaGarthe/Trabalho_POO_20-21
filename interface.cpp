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
int Interface::flag2=0;
int Interface::flag3=0;

void Interface::comandosi() //aqui vamos verificar os comando cria, lista e carrega (e conquista)
{
    string comando, comando_cmp, tipo_t, fich, comando_cmp1, tipo_t1, nome, tipo;
    int quantidade, quantidade1;

    cout << "*****************************************************************************************************" << endl;
    cout << "Comandos disponiveis ao longo do jogo: " << endl;
    cout << "-> maisouro (1 de ouro, perdendo 2 de produtos);" << endl;
    cout << "-> maisprod (1 de produtos, perdendo 2 de ouro);" << endl;
    cout << "-> maismilitar (compra uma unidade militar,reduz uma unidade de produtos e uma de ouro);" << endl;
    cout << "-> lista (informação geral do jogo);" << endl;
    cout << "-> lista tudo (todos os territorios existentes no mundo);" << endl;
    cout << "-> lista meu (os territorios conquistados, quantidade de ouro e prod, pontos acumulados, resistencia e forca militar); " << endl;
    cout << "-> lista resta (territorios do mundo que ainda não foram conquistados);" << endl;
    cout << "-> lista <territorio> (mostra a resistencia desse territorio em especifico) "<< endl;
    cout << "*****************************************************************************************************\n" << endl;
    cout << "\n***************************************************************************" << endl;
    cout << "Comandos por fases: " << endl;
    cout << "-> 1ª fase: conquista <territorio> ou passa" << endl;
    cout << "-> 2ª fase: se tiver a tecnologia bolsa valores pode ser utilizada" << endl;
    cout << "-> 3ª fase: adquire <tecnologia> ou maismilitar" << endl;
    cout << "****************************************************************************\n" << endl;

        do {

            cout << "Introduza o comando pretendido: ";
            getline(cin, comando);

            istringstream is(
                    comando); // o is contem o conteudo do comando para os posteriormente podermos dividir e comparar
            is>> comando_cmp;//>> tipo_t >> quantidade >> tipo; //aqui a string vai ser dividida e o comando_cmp = cria/carrega..., o tipo_t= castelo..., o quantidade= nº desejado

            if (comando_cmp == "cria") {
                if(flag3==0) {
                    if (is >> tipo_t && is >> quantidade) {
                        if (logica.addTerritorio(tipo_t, quantidade))
                            cout << "Foram adicionados territorios ao mundo. Pode consultar no comando lista tudo\n"
                                 << endl;
                        quantidade = 1;
                        tipo_t = " ";
                    }
                }
                else
                    cout << "Comando impossivel!\n"<< endl;
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
                            if(flag3==0) {
                                os >> tipo_t1 >> quantidade1;
                                if (logica.addTerritorio(tipo_t1, quantidade1))
                                    cout
                                            << "Foram adicionados territorios ao mundo. Pode consultar no comando lista tudo\n"
                                            << endl;
                                quantidade1 = 1;
                                tipo_t1 = " ";
                            }
                        } else if (comando_cmp1 == "conquista") {

                            if(logica.getfase()==1 && flag==0) {
                                if (os >> tipo_t)
                                    // logica.conquista(tipo_t);
                                    cmd = logica.getAs1(comando_cmp, tipo_t);
                                logica.addcomando(cmd);
                                if(logica.conquista())
                                    cout << "Conseguiu adquirir o território!Pode consultar no comando lista meu\n" <<endl;
                                else
                                    cout << "Não conseguiu adquirir o territótio! " << endl;
                                flag=1;
                            }
                            else
                            {
                                cout << "comando impossivel nesta fase\n" << endl;
                            }
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
                    cout << logica.fimturno() << endl;
                    tipo_t = " ";
                    comando_cmp = " ";
                }
            } else if (comando_cmp == "conquista") {
                if(logica.getfase()==1 && flag==0) {
                    if (is >> tipo_t)
                        // logica.conquista(tipo_t);
                        cmd = logica.getAs1(comando_cmp, tipo_t);
                    logica.addcomando(cmd);
                    if(logica.conquista())
                        cout << "Conseguiu adquirir o território!Pode consultar no comando lista meu\n" <<endl;
                    else
                        cout << "Não conseguiu adquirir o territótio!\n " << endl;
                    flag=1;
                }
                else
                {
                    cout << "comando impossivel nesta fase\n" << endl;
                }

            } else if (comando_cmp == "passa")
            {
                if(logica.getfase()==1 && flag==0 ) {
                    cout << "Nenhum territorio foi conquistado\n" << endl;
                    flag =1;
                }
                else
                {
                    cout << "comando impossivel nesta fase\n" << endl;
                }
            }
            else if (comando_cmp == "adquire") {
                if(logica.getfase()==3 && flag2==0) {
                    if (is >> tipo_t >> tipo)
                        tipo = logica.getAs1(tipo_t, tipo);
                    cmd = logica.getAs1(comando_cmp, tipo);
                    logica.addcomando(cmd);
                    //logica.adquire(cmd);
                    if(logica.adquire())
                        cout << "Pode consultar no comando lista meu\n" << endl;

                    flag2=1;
                }
                else
                {
                    cout << "comando impossivel nesta fase\n" << endl;
                }
            }
            else if (comando_cmp == "maisouro") {
                if(logica.mouro())
                    cout << "Pode consultar no comando lista meu\n" << endl;
                logica.getAs2(comando_cmp);
            }
            else if (comando_cmp == "maisprod") {
                if(logica.mproduto())
                {cout << "Pode consultar no comando lista meu\n" << endl;}
                logica.getAs2(comando_cmp);
            }
            else if (comando_cmp == "maismilitar") {
                if(logica.getfase()==3 && flag2==0) {
                    if(logica.mmilitar())
                        cout << "Pode consultar no comando lista meu\n" << endl;

                   //logica.getAs2(comando_cmp);
                    flag2=1;
               }
                else
                    cout << "comando impossivel nesta fase\n" << endl;
            }
            else if (comando_cmp == "toma") {
                if (is >> tipo_t) {
                    if (tipo_t == "tec") {
                        if (is >> tipo >> tipo_t)
                            cmd=logica.getAs1(tipo,tipo_t);
                            logica.tomatec(cmd);

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
                        if(logica.mudaOuro(quantidade))
                            cout << "Pode consultar no comando lista meu\n" << endl;

                    }
                    else if (tipo_t == "prod") {
                        if(logica.mudaProd(quantidade))
                            cout << "Pode consultar no comando lista meu\n" << endl;
                   }
                }
            }
            else if (comando_cmp == "evento") {
                    logica.evento();
                logica.getAs2(comando_cmp);
            }
            else if (comando_cmp == "fevento") {
                if (is >> tipo_t)
                   if( logica.eventoforcado(tipo_t))
                       cout << "Vai ser realizado o evento: " << tipo_t << "\n" << endl;
            }
             else if (comando_cmp == "avanca") {

                logica.avanca();
                if(logica.getTurno()<=6)
                    cout << "\nANO 1, turno: "<< logica.getTurno() << " ,fase " << logica.getfase()<< "\n" << endl;
                else
                    cout << "\nANO 2, turno: "<< logica.getTurno() << " ,fase " << logica.getfase() << "\n" << endl;

                if(logica.getfase()==2) {
                    cout << "Recolha de bens de todos os seus territorios. \n" << endl;

                   /* if(logica.verificabolsa())
                        cout << "Não possui a tecnologia bola de valores. Se quiseres comprar insira o comando adquire bolsa valores na fase 3" << endl;
                    else {
                        cout<< "Escola uma opção: 1- trocar duas unidades de ouro por uma de produtos; 2-trocar duas unidades de ouro por uma de produtos;\n Se não quiser nenhuma das opções digitar avanca"
                                << endl;
                        if(is >> quantidade)
                        {cout << quantidade << endl;
                            if(quantidade==1 || quantidade==2)
                               if(logica.trocabola(quantidade))
                                    cout << "Troca efetuada com sucesso.\n" << endl;
                                else
                                    cout << "Não possui meios suf\n" << endl;
                        }
                    }*/
                }
                if(logica.getfase()==1)
                {
                    cout << "Comandos disponiveis: -> conquista <territorio> ou passa \n" << endl;
               }
                if(logica.getfase()==3)
                {
                    cout << "Comandos disponiveis: -> adquire <tecnologia> ou maismilitar\n " << endl;
                }
                if(logica.getTurno()==13)
                {
                    cout << logica.aviso_final()<<endl;
                    comando = "terminar";
                }
                logica.getAs2(comando_cmp);
                flag=0;
                flag2=0;
                flag3=1;
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
        }
        else if(tipo == "resta")
        {
            cout << logica.mundoresta() << endl;
        }
        else {
            cout << logica.cadamostra(tipo);
        }


    }
