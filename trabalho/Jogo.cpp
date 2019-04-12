#include <iostream>
#include <string>
#include "Jogo.h"

Jogo::Jogo() {
    //cout << "Instanciando Jogo\n";
    //qtdJogos++;
    //this->id = qtdJogos;
};

Jogo::Jogo(string _nome, float _valor, string _gen) {
    this->nome = _nome;
    this->valor = _valor;
    this->gen = new Jogo::Genero();
    this->gen->setNome(_gen);
    qtdJogos++;
    this->id = qtdJogos;
}

Jogo::~Jogo() {
    cout << "Destruindo Jogo: " << this->nome << endl;
    qtdJogos--;
}

string Jogo::getNome() {
    return this->nome;
}

void Jogo::setNome(string _nome) {
    this->nome = _nome;
}

float Jogo::getValor() {
    return this->valor;
}

void Jogo::setValor(float _valor) {
    this->valor = _valor;
}

Jogo::Genero *Jogo::getGenero() {
    return this->gen;
}

void Jogo::setGenero(Genero *_gen) {
    this->gen = _gen;
}

void Jogo::imprimeQtdJogos() {
    cout << qtdJogos;
}

void Jogo::setEmPromocao(bool emPromocao) {
    this->emPromocao = emPromocao;
}

bool Jogo::getEmPromocao() {
    return this->emPromocao;
}

Jogo::Genero::Genero() {
    //cout << "Instanciando Genero\n";
}

Jogo::Genero::Genero(string _nome) {
    this->nome = _nome;
}
string Jogo::Genero::getNome() {
    return this->nome;
}

void Jogo::Genero::setNome(string _nome) {
    this->nome = _nome;
} 

void Jogo::setId(int _id) {
    this->id = _id;
}

int Jogo::getId() {
    return this->id;
}
