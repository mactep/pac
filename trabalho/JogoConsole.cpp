#include <iostream>
#include <string>
#include <vector>
#include "JogoConsole.h"


JogoConsole::JogoConsole(){}

JogoConsole::JogoConsole(string _nome, float _valor, string _gen, bool mult):Jogo(_nome, _valor, _gen) {
    this->setPossuiMultiplayer(mult);
};

bool JogoConsole::getPossuiMultiplayer() {
    return this->possuiMultiplayer;
}

void JogoConsole::setPossuiMultiplayer(bool mult) {
    this->possuiMultiplayer = mult;
}

void JogoConsole::imprimeInfoJogo() {
    cout << "[Jogo Console] ";
    cout << this->getNome();
    cout << " (" << this->getGenero()->getNome() << ")";
    cout << " ID: " << this->getId();
    cout << " Preco: " << this->getValorPromocao();
    cout << " Multiplayer: ";

    if (this->getPossuiMultiplayer()) {
            cout << "Sim\n";
        }
        else {
            cout << "Não\n";
        }
}

float JogoConsole::getValorPromocao() {
    if (this->getEmPromocao()) {
        return this->getValor() * 0.9;
    } else {
        return this->getValor();
    }
}

void JogoConsole::salvarDados(ofstream &outfile) {
    outfile << "2" << endl;
    outfile << this->getNome() << endl;
    outfile << this->getGenero()->getNome() << endl;
    outfile << this->getId() << endl;
    outfile << this->getEmPromocao() << endl;
    outfile << this->getValor() << endl;
    outfile << this->getPossuiMultiplayer() << endl;
}
