#ifndef _EMPRESADESENVOLVEDORA_H
#define _EMPRESADESENVOLVEDORA_H

#include <iostream>
#include <string>
#include <vector>
#include "JogoPC.h"
#include "JogoConsole.h"

class EmpresaDesenvolvedora {
    private:
        string nome;
        vector<Jogo*> jogosDesenvolvidos;

    public:
        EmpresaDesenvolvedora();

        EmpresaDesenvolvedora(string _nome);

        void criarJogo(int tipo);

        void colocarJogoPromocao();

        void tirarJogoPromocao();

        string getNome();

        void setNome(string _nome);

        vector<Jogo*> getJogosDesenvolvidos();

        void salvarDados();

        void carregarDados(string fileName);
};

#endif
