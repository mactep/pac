#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "EmpresaDesenvolvedora.h"
#include "JogoPC.h"
#include "JogoConsole.h"

EmpresaDesenvolvedora::EmpresaDesenvolvedora() {
    //cout << "Instanciando EmpresaDesenvolvedora\n";
}

EmpresaDesenvolvedora::EmpresaDesenvolvedora(string _nome) {
    this->nome = _nome;
}

void EmpresaDesenvolvedora::criarJogo(int tipo) {
    cout << "Criando novo jogo...\n";
    string nome, gen;
    float valor;
    cout << "Digite o nome do jogo: ";
    cin >> nome;
    cout << "Digite o valor do jogo: ";
    cin >> valor;
    cout << "Digite o genero do jogo: ";
    cin >> gen;
    if (tipo == 1) {
        float espaco;
        cout << "Digite o espaco requerido pelo jogo: ";
        cin >> espaco;
        JogoPC *j;
        j = new JogoPC(nome, valor, gen, espaco);
        this->jogosDesenvolvidos.push_back(j);
    } else if (tipo == 2) {
        bool multiplayer = -1;
        while (multiplayer != 0 && multiplayer != 1) {
            cout << "Digite 1 se o jogo possui modo multiplayer. Caso nao possua digite 0: ";
            cin >> multiplayer;
        }
        JogoConsole *j;
        j = new JogoConsole(nome, valor, gen, multiplayer);
        this->jogosDesenvolvidos.push_back(j);
    } else {
        cout << "Opcao invalida!\n";
        return;
    }
    cout << "Jogo criado com sucesso\n";
}

void EmpresaDesenvolvedora::colocarJogoPromocao() {
    if (!this->getJogosDesenvolvidos().size()) {
        cout << "Nenhum jogo desenvolvido\n";
        return;
    }
    for (unsigned int i = 0; i < this->getJogosDesenvolvidos().size(); i++) {
        if (this->getJogosDesenvolvidos()[i]->getEmPromocao() == false) {
            cout << i + 1 << " - ";
            this->getJogosDesenvolvidos()[i]->imprimeInfoJogo();
        }
    }
    int escolhido = -1;
    while (escolhido <= 0 || (unsigned int)escolhido > this->getJogosDesenvolvidos().size()) {
        cout << "Escolha um jogo para colocar na promocao: ";
        cin >> escolhido;
    }
    if (this->getJogosDesenvolvidos()[escolhido - 1]->getEmPromocao() == true) {
        cout << "Este jogo já está em promoção" << endl;
    } else {
        this->getJogosDesenvolvidos()[escolhido - 1]->setEmPromocao(true);
        cout << this->getJogosDesenvolvidos()[escolhido - 1]->getNome();
        cout << " agora custa ";
        cout << this->getJogosDesenvolvidos()[escolhido - 1]->getValorPromocao() << endl;
    }
}

void EmpresaDesenvolvedora::tirarJogoPromocao() {
    int jogosEmPromocao = 0;
    for (unsigned int i = 0; i < this->getJogosDesenvolvidos().size(); i++) {
        if (this->getJogosDesenvolvidos()[i]->getEmPromocao() == true) {
            jogosEmPromocao++;
        }
    }
    if (!jogosEmPromocao) {
        cout << "Nenhum jogo em promocao\n";
        return;
    }
    for (unsigned int i = 0; i < this->getJogosDesenvolvidos().size(); i++) {
        if (this->getJogosDesenvolvidos()[i]->getEmPromocao() == true) {
            cout << i + 1 << " - ";
            this->getJogosDesenvolvidos()[i]->imprimeInfoJogo();
        }
    }
    int escolhido = -1;
    while (escolhido <= 0 || escolhido > jogosEmPromocao) {
        cout << "Escolha um jogo para tirar da promocao: ";
        cin >> escolhido;
    }
    if (this->getJogosDesenvolvidos()[escolhido - 1]->getEmPromocao() == true) {
        this->getJogosDesenvolvidos()[escolhido - 1]->setEmPromocao(false);
        cout << this->getJogosDesenvolvidos()[escolhido - 1]->getNome();
        cout << " voltou a custar ";
        cout << this->getJogosDesenvolvidos()[escolhido - 1]->getValorPromocao() << endl;
    } else {
        cout << "Este jogo não está em promoção" << endl;
    }
}

string EmpresaDesenvolvedora::getNome() {
    return this->nome;
}

void EmpresaDesenvolvedora::setNome(string _nome) {
    this->nome = _nome;
}

vector<Jogo*> EmpresaDesenvolvedora::getJogosDesenvolvidos() {
    return this->jogosDesenvolvidos;
}

void EmpresaDesenvolvedora::salvarDados() {
    string fileName = this->getNome() + ".txt";
    ofstream fp;
    fp.open(fileName.c_str(), ios::out | ios::trunc);

    fp << this->getJogosDesenvolvidos().size() << endl;

    for(unsigned int i = 0; i < this->getJogosDesenvolvidos().size(); i++)
    {
        this->getJogosDesenvolvidos()[i]->salvarDados(fp);
    }

    fp.close();
    cout << "Dados salvos com sucesso\n";
}

void EmpresaDesenvolvedora::carregarDados(string fileName) {
    ifstream fp;
    string name = fileName + ".txt";
    fp.open(name.c_str(), ifstream::in);

    this->setNome(fileName);

    int tamanho;
    fp >> tamanho;

    Jogo::qtdJogos -= tamanho;

    for (int i = 0; i < tamanho; i++) {
        int tipo, id;
        string nome, gen;
        bool promocao;
        float valor;
        fp >> tipo;
        fp >> nome; // usar getline(fp, nome);
        fp >> gen;  // usar getline(fp, gen);
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
            this->jogosDesenvolvidos.push_back(j);
        } else if (tipo == 2) {
            bool multiplayer;
            fp >> multiplayer;
            JogoConsole *j;
            j = new JogoConsole(nome, valor, gen, multiplayer);
            j->setId(id);
            j->setEmPromocao(promocao);
            this->jogosDesenvolvidos.push_back(j);
        } else {
            cout << "Opcao invalida!\n";
        }
    }

    fp.close();
    cout << "Dados carregados com sucesso\n";
}
