#ifndef _JOGOCONSOLE_H
#define _JOGOCONSOLE_H

#include <iostream>
#include <string>
#include "Jogo.h"


using namespace std;

class JogoConsole: public Jogo{
    private:
        bool possuiMultiplayer;

    public:
        JogoConsole();

        JogoConsole(string _nome, float _valor, string _gen, bool mult);

        bool getPossuiMultiplayer();

        void setPossuiMultiplayer(bool mult);

        void imprimeInfoJogo();

        float getValorPromocao();

        void salvarDados(ofstream &outfile);
};

#endif
