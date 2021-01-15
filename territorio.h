//
// Created by Merlina Garthe on 01/12/2020.
//

#ifndef TERRITORIO_H
#define TERRITORIO_H
#include <iostream>
#include <string>


using namespace std;

class Territorio
{
   string tipo;
    string nome;
    int conta;
    int resistencia;
    int Produtos ;
    int Ouro ;
    int pontos ;
public:

    Territorio(string tp, int ct, int resis, int prod, int ou, int pont) ;//construtor que recebe o tipo de territorio
    string getNome() const;	// retorna o nome do territorio para ser usado no getAsString
    int getOuro();
    int getProd();
    int getPontos();
    int getResis();
    void Nome() ;
    string getTipo() const;
    virtual void getturno(int f) {}
    virtual string getAsString() const;
};


#endif