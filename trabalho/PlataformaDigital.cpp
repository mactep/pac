#include <iostream>
#include <string>
#include <vector>
#include "JogoConsole.h"
#include "JogoPC.h"
#include "EmpresaDesenvolvedora.h"
#include "PlataformaDigital.h"

PlataformaDigital::PlataformaDigital() {
    //cout << "Instanciando PlataformaDigital";
}

PlataformaDigital::PlataformaDigital(string _nome, float _carteiraDigital) {
    this->nome = _nome;
    this->carteiraDigital = _carteiraDigital;
}

void PlataformaDigital::imprimeJogosCadastrados() {
    if (this->getJogosCadastrados().size() == 0) {
        cout << "Nao existem jogos cadastrados\n";
    }
    for (unsigned int i = 0; i < this->getJogosCadastrados().size(); i++) {
        cout << i + 1 << " - ";
        jogosCadastrados[i]->imprimeInfoJogo();
    }
}

void PlataformaDigital::imprimeJogosInstalados() {
    if (this->getJogosInstalados().size() == 0) {
        cout << "Nao existem jogos instalados\n";
    }
    for (unsigned int i = 0; i < jogosInstalados.size(); i++) {
        cout << i + 1 << " - ";
        jogosInstalados[i]->imprimeInfoJogo();
    }
}

void PlataformaDigital::imprimeJogos(string genero) {
    if (this->getJogosCadastrados().size() == 0) {
        cout << "Nao existem jogos cadastrados\n";
        return;
    }
    int validos = 0;
    for (unsigned int i = 0;i < this->getJogosCadastrados().size(); i++) {
        if (this->getJogosCadastrados()[i]->getGenero()->getNome() == genero) {
            validos++;
            cout << i + 1 << " - ";
            jogosCadastrados[i]->imprimeInfoJogo();
        }
    }
    if (validos <= 0) {
        cout << "Nao existem jogos com este genero\n";
    }
}

void PlataformaDigital::adicionarCreditosCarteira(float creditos) {
    carteiraDigital += creditos;
    cout << "Foram adicionados " << creditos << " na carteira\n";
}

int PlataformaDigital::comprarJogo(Jogo *novoJogo) {
    for (unsigned int i = 0; i < this->getJogosCadastrados().size(); i++) {
        if (this->getJogosCadastrados()[i]->getNome() == novoJogo->getNome()) {
            cout << "Jogo ja cadastrado na Plataforma\n";
            return 0;
        }
    }
    if (this->getCarteiraDigital() >= novoJogo->getValorPromocao()) {
        cout << novoJogo->getNome() << " foi comprado\n";
        jogosCadastrados.push_back(novoJogo);
        this->setCarteiraDigital(this->getCarteiraDigital() - novoJogo->getValorPromocao());
        return 1;
    } else {
        cout << "Nao possui creditos suficientes para comprar esse jogo\n";
        return 0;
    }
}

void PlataformaDigital::instalarJogo() {
    if (!this->getJogosCadastrados().size()) {
        cout << "Nenhum jogo cadastrado\n";
        return;
    }
    for (unsigned int i = 0; i < this->getJogosCadastrados().size(); i++) {
        cout << i + 1 << " - ";
        cout << this->getJogosCadastrados()[i]->getNome() << endl;
    }
    int escolhido = -1;
    while (escolhido <= 0 || (unsigned int)escolhido > this->getJogosCadastrados().size()) {
        cout << "Escolha ums dos jogos abaixo para instalar: ";
        cin >> escolhido;
    }
    for (unsigned int i = 0; i < this->getJogosInstalados().size(); i++) {
        if (this->getJogosInstalados()[i]->getNome() == this->getJogosCadastrados()[escolhido - 1]->getNome()) {
            cout << "Jogo ja instalado\n";
            return;
        }
    }
    cout << "Instalando " << this->getJogosCadastrados()[escolhido - 1]->getNome() << "...\n";
    jogosInstalados.push_back(this->getJogosCadastrados()[escolhido - 1]);
}

void PlataformaDigital::desinstalarJogo() {
    if (!this->getJogosInstalados().size()) {
        cout << "Nenhum jogo instalado\n";
        return;
    }
    for (unsigned int i = 0; i < this->getJogosInstalados().size(); i++) {
        cout << i + 1 << " - ";
        cout << this->getJogosInstalados()[i]->getNome() << endl;
    }
    int escolhido = -1;
    while (escolhido <= 0 || (unsigned int)escolhido > this->getJogosInstalados().size()) {
        cout << "Escolha ums dos jogos abaixo para desinstalar: ";
        cin >> escolhido;
    }
    cout << "Desinstalando " << this->getJogosInstalados()[escolhido - 1]->getNome() << "...\n";
    jogosInstalados.erase(jogosInstalados.begin() + escolhido - 1);
}

string PlataformaDigital::getNome() {
    return this->nome;
}

void PlataformaDigital::setNome(string _nome) {
    this->nome = _nome;
}

float PlataformaDigital::getCarteiraDigital() {
    return this->carteiraDigital;
}

void PlataformaDigital::setCarteiraDigital(float _carteiraDigital) {
    this->carteiraDigital = _carteiraDigital;
}

vector<Jogo*> PlataformaDigital::getJogosCadastrados() {
    return this->jogosCadastrados;
}

vector<Jogo*> PlataformaDigital::getJogosInstalados() {
    return this->jogosInstalados;
}

void PlataformaDigital::salvarDados() {
    string fileName = this->getNome() + ".txt";
    ofstream fp;

    fp.open(fileName.c_str(), ofstream::out | ofstream::trunc);

    fp << this->getCarteiraDigital() << endl;

    fp << this->getJogosCadastrados().size() << endl;
    for(unsigned int i = 0; i < this->getJogosCadastrados().size(); i++)
    {
        this->getJogosCadastrados()[i]->salvarDados(fp);
    }

    fp << this->getJogosInstalados().size() << endl;
    for(unsigned int i = 0; i < this->getJogosInstalados().size(); i++)
    {
        this->getJogosInstalados()[i]->salvarDados(fp);
    }

    fp.close();
}

void PlataformaDigital::carregarDados(string fileName) {
    ifstream fp;

    string name = fileName + ".txt";
    fp.open(name.c_str(), ofstream::in);


    this->setNome(fileName);
    float carteira;
    fp >> carteira;
    this->setCarteiraDigital(carteira);

    int tamanho;
    fp >> tamanho;

    for (int i = 0; i < tamanho; i++) {
        int tipo, id;
        string nome, gen;
        bool promocao;
        float valor;
        fp >> tipo;
        fp >> nome;
        fp >> gen;
        fp >> id;
        fp >> promocao;
        fp >> valor;
        if (tipo == 1) {
            float espaco;
            fp >> espaco;
            JogoPC *j;
            j = new JogoPC(nome, valor, gen, espaco);
            j->setEmPromocao(promocao);
            this->jogosCadastrados.push_back(j);
        } else if (tipo == 2) {
            bool multiplayer;
            fp >> multiplayer;
            JogoConsole *j;
            j = new JogoConsole(nome, valor, gen, multiplayer);
            j->setEmPromocao(promocao);
            this->jogosCadastrados.push_back(j);
        } else {
            cout << "Opcao invalida!\n";
        }
    }

    fp >> tamanho;

    for (int i = 0; i < tamanho; i++) {
        int tipo, id;
        string nome, gen;
        bool promocao;
        float valor;
        fp >> tipo;
        fp >> nome;
        fp >> gen;
        fp >> id;
        fp >> promocao;
        fp >> valor;
        if (tipo == 1) {
            float espaco;
            fp >> espaco;
            JogoPC *j;
            j = new JogoPC(nome, valor, gen, espaco);
            j->setId(id);
            j->setEmPromocao(promocao);
            this->jogosInstalados.push_back(j);
        } else if (tipo == 2) {
            bool multiplayer;
            fp >> multiplayer;
            JogoConsole *j;
            j = new JogoConsole(nome, valor, gen, multiplayer);
            j->setId(id);
            j->setEmPromocao(promocao);
            this->jogosInstalados.push_back(j);
        } else {
            cout << "Opcao invalida!\n";
        }
    }

    fp.close();
}

void PlataformaDigital::exportarBibliotecaJogos() {
    string fileName = this->getNome() + ".html";
    ofstream fp;
    fp.open(fileName.c_str(), ofstream::out | ofstream::trunc);
    fp << "<!DOCTYPE HTML>";
    fp << "<html lang='pt-br'>";
    fp << "<head>";
    fp << "<title> " << this->getNome() << " - BIBLIOTECA DE JOGOS </title>";
    fp << "<style>";
    fp << "table {";
    fp << "font-family: arial, sans-serif;";
    fp << "border-collapse: collapse;";
    fp << "width: 100%;";
    fp << "}";
    fp << "";
    fp << "td, th {";
    fp << "border: 1px solid #dddddd;";
    fp << "text-align: left;";
    fp << "padding: 8px;";
    fp << "}";
    fp << "";
    fp << "tr:nth-child(even) {";
    fp << "background-color: #dddddd;";
    fp << "}";
    fp << "</style>";
    fp << "</head>";
    fp << "<body>";
    fp << "<h1 style='text-align:center;'> " << this->getNome() << " - BIBLIOTECA DE JOGOS </h1>";
    fp << "<table style='width:100%'>";
    fp << "<tr>";
    fp << "<th> N&#176 </th>";
    fp << "<th> Nome</th> ";
    fp << "<th> Valor </th>";
    fp << "<th> G&ecircnero </th> ";
    fp << "<th> Instalado? </th>";
    fp << "</tr>";
    for (unsigned int i = 0; i < this->getJogosCadastrados().size(); i++) {
        fp << "<tr>";
        fp << "<td> " << i + 1 << " </td>";
        fp << "<td> " << this->getJogosCadastrados()[i]->getNome()  << " </td> ";
        fp << "<td> R$ " << this->getJogosCadastrados()[i]->getValor() << " </td>";
        fp << "<td> " << this->getJogosCadastrados()[i]->getGenero()->getNome() << " </td>";
        int instalado = 0;
        for (unsigned int j = 0; j < this->getJogosInstalados().size(); j++) {
            if (this->getJogosInstalados()[j]->getNome() == this->getJogosCadastrados()[i]->getNome()) {
                instalado = 1;
                break;
            }
        }
        if (instalado) {
            fp << "<td> Sim </td> ";
        } else {
            fp << "<td> N&atildeo </td> ";
        }
        fp << "</tr>";
    }
    fp << "</body>";
    fp.close();
}
