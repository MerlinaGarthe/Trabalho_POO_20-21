//
// Created by Merlina Garthe on 01/12/2020.
//

#ifndef UNTITLED1_MUNDO_H
#define UNTITLED1_MUNDO_H
#include <iostream>
#include <vector>
#include "territorio.h"
#include "territorioJogador.h"
#include "territorioI.h"
using namespace std;

class Mundo {
    vector<Territorio *> te;    //vetor onde se vai guardar os territorios existentes no mundo
    TerritorioJogador tj;
    int turno;

public:
    Mundo() {}

    ~Mundo();    //destrutor para no fim destroi o vetor dinamico
    string getAsString() const;        //mostrar o conteudo do vetor
    bool addTerritorio(string tipo, int quantidade);    //adicionar um territorio
    bool conquista(string nome);    //conquista os territorio
    void adquire(string tipo);
    string imprimeTerritoriosJogador(); // imprimi o vetor de territorios conquistados
    string imprimeMeu();
    string imprimeTudo();
    bool ouro();
    bool produto();
    bool militar();
    bool toma(string nome);
    void tomatec(string tipo);
    bool mudaOuro(int quantidade);
    bool mudaProd(int quantidade);
    void evento();
    void eventoforcado(string tipo);
    string cadamostra(string nome);
    string mostraPontos();
    bool recolha(int f);
};

#endif