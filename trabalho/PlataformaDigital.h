#ifndef _PLATAFORMADIGITAL_H
#define _PLATAFORMADIGITAL_H

#include <iostream>
#include <string>
#include <vector>
#include "JogoPC.h"
#include "JogoConsole.h"

using namespace std;

class PlataformaDigital {
    private:
        string nome;
        float carteiraDigital;
        vector<Jogo*> jogosCadastrados;
        vector<Jogo*> jogosInstalados;

    public:
        PlataformaDigital();

        PlataformaDigital(string _nome, float _carteiraDigital);

        void imprimeJogosCadastrados();

        void imprimeJogosInstalados();

        void imprimeJogos(string genero);

        void adicionarCreditosCarteira(float creditos);

        int comprarJogo(Jogo *novoJogo);

        void instalarJogo();

        void desinstalarJogo();

        string getNome();

        void setNome(string _nome);

        float getCarteiraDigital();

        void setCarteiraDigital(float _carteiraDigital);

        vector<Jogo*> getJogosCadastrados();

        vector<Jogo*> getJogosInstalados();

        friend void presenteVirtual (PlataformaDigital *presenteador, PlataformaDigital *presenteado, Jogo *presente);

        void salvarDados();

        void carregarDados(string fileName);

        void exportarBibliotecaJogos();
};

#endif
