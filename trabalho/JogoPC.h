#ifndef _JOGOPC_H
#define _JOGOPC_H

#include <iostream>
#include <string>
#include <fstream>
#include "Jogo.h"


using namespace std;

class JogoPC: public Jogo{
    private:
        float espacoDiscoRequerido;

    public:
        JogoPC();

        JogoPC(string _nome, float _valor, string _gen, float espaco);

        float getEspacoDiscoReq();

        void setEspacoDiscoReq(float espaco);

        void imprimeInfoJogo();

        float getValorPromocao();

        void salvarDados(ofstream &outfile);
};

#endif
