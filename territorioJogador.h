//
// Created by Merlina Garthe on 01/12/2020.
//
#ifndef TERRITORIOJOGADOR_H
#define TERRITORIOJOGADOR_H
#include <iostream>
#include <vector>
#include <string>
#include "territorio.h"
#include "tecnologias.h"
using namespace std;

class TerritorioJogador
{
    vector<Territorio*> territorios;
    vector<Tecnologias*> tecno;
    string nome;
    string tipo;
    int armazemmax;	//quantidade maxima
    int cofremax;		//quantidade maxima
    int resistencia ;
    int criacao_p ;
    int criacao_o ;
    int pontos;
   int forcamilitar ; //Nivel de forÁa militar, falta fazer o nivel
    int limforca;
   int ouro;
   int produtos;
public:
    ~TerritorioJogador();

    TerritorioJogador() ;
    string getForcaMil();
    string getResis();
    //string getNome() const;
    int getOuro() ;
    //string getAsString() const;
    int random();
    void conquista(Territorio &ter);
    string getAsString2() const;
    string getAsString() const;
    void adquire(string tipo) ;
   // string getTipo() const;
    bool maisOuro();
    bool maisproduto();
   bool maismilitar();
   bool encontra();
   string aviso() const;
   bool tam() ;
   void toma(Territorio &ter);
   void tomatec(string tipo);
   bool mudaOuro(int quant);
   bool mudaProd(int quant);
   int randomevento();
   void evento();
   int randomsorte();
   void eventoforcado(string tipo);
    bool verifica (Territorio &ter);
    string aviso_final();
    void recolha(int f);
};

#endif