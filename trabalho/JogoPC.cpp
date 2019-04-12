#include <iostream>
#include <string>
#include <vector>
#include "JogoPC.h"

JogoPC::JogoPC(){}

JogoPC::JogoPC(string _nome, float _valor, string _gen, float espaco):Jogo(_nome, _valor, _gen) {
    this->setEspacoDiscoReq(espaco);
};

float JogoPC::getEspacoDiscoReq() {
    return this->espacoDiscoRequerido;
}

void JogoPC::setEspacoDiscoReq(float espaco) {
    this->espacoDiscoRequerido = espaco;
}

void JogoPC::imprimeInfoJogo() {
    cout << "[Jogo PC] ";
    cout << this->getNome();
    cout << " (" << this->getGenero()->getNome() << ")";
    cout << " ID: " << this->getId();
    cout << " Preco: " << this->getValorPromocao();
    cout << " Tamanho: " << this->getEspacoDiscoReq() << endl;
}

float JogoPC::getValorPromocao() {
    if (this->getEmPromocao()) {
        return this->getValor() * 0.7;
    } else {
        return this->getValor();
    }
}

void JogoPC::salvarDados(ofstream &outfile) {
    outfile << "1" << endl;
    outfile << this->getNome() << endl;
    outfile << this->getGenero()->getNome() << endl;
    outfile << this->getId() << endl;
    outfile << this->getEmPromocao() << endl;
    outfile << this->getValor() << endl;
    outfile << this->getEspacoDiscoReq() << endl;
}
