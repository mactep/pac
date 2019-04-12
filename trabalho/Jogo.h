#ifndef _JOGO_H
#define _JOGO_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class PlataformaDigital;

class Jogo {
    class Genero {
        private:
            string nome;

        public:
            Genero();
            Genero(string _nome);
            string getNome();
            void setNome(string _nome);
    };
    protected:
        Genero *gen;

        string nome;

        float valor;

        bool emPromocao;

        int id;


    public:
        static int qtdJogos;

        Jogo();

        Jogo(string _nome, float _valor, string _gen);

        ~Jogo();

        string getNome();

        void setNome(string _nome);

        float getValor();

        void setValor(float _valor);

        Jogo::Genero *getGenero();

        void setGenero(Genero *_gen);

        static void imprimeQtdJogos();

        virtual void imprimeInfoJogo() = 0;

        virtual float getValorPromocao() = 0;

        friend void presenteVirtual (PlataformaDigital *p, Jogo *presente);

        void setEmPromocao(bool emPromocao);

        bool getEmPromocao();

        void setId(int _id);

        int getId();

        virtual void salvarDados(ofstream &outfile) = 0;
};

#endif
