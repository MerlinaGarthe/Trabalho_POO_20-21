//
// Created by Merlina Garthe on 13/01/2021.
//

#ifndef UNTITLED1_LOGICA_H
#define UNTITLED1_LOGICA_H
#include "mundo.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Logica {
    Mundo m;
    vector <string> comandos;
    static int turno;
    static int fase;
public:
    bool addTerritorio(string tipo, int quant);
    string mostra() const ;
    bool conquista(string tipo);
    bool adquire(string tipo);
    bool mouro();
    bool mproduto();
    bool mmilitar();
    string territorioJogador();
    bool tomaterr(string tipo);
    bool tomatec(string tipo);
    bool mudaOuro(int quant);
    bool mudaProd(int quant);
    bool evento();
    bool eventoforcado(string tipo);
    string cadamostra(string nome);
    bool avanca();
    bool addcomando(string comando);
    string getAs1(string comando, string tipo);
    string getAs2(string comando);
    string mostraCmd() const;
    bool conquista();
    bool adquire();
    int faseq();
    string aviso_final();
    int getfase();
    int getTurno();
    bool trocabola(int num);
    bool verificabolsa();
    string mundoresta();
    string fimturno();
    string tecnologias();

};

#endif //UNTITLED1_LOGICA_H