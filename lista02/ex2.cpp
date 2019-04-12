#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename tipo1, typename tipo2>
class Setor {
    protected:
        tipo2 codigo;
        vector<tipo1*> membros;

    public:
        Setor(tipo2 _codigo) {
            this->codigo = _codigo;
        }

        tipo2 getCodigo() {
            return this->codigo;
        }
        void setCodigo(tipo2 _codigo) {
            this->codigo = _codigo;
        }

        vector<tipo1*> getMembros() {
            return this->membros;
        }

        // ?
        void setMembros(vector<tipo1*> _membros) {
            this->membros = _membros;
        }

        void adicionaMembro(tipo1* membro) {
            this->membros.push_back(membro);
        }

        void removeMembro() {
            this->membros.pop_back();
        }
};

class Funcionario {
    private:
        string nome;
        string matricula;
        float salario;
        int cargaHoraria;

    public:
        Funcionario() {}

        Funcionario(string _nome, string _matricula, float _salario, int _cargaHoraria) {
            this->nome = _nome;
            this->matricula = _matricula;
            this->salario = _salario;
            this->cargaHoraria = _cargaHoraria;
        }

        string getNome() {
            return this->nome;
        }

        void setNome(string _nome) {
            this->nome = _nome;
        }

        string getMatricula() {
            return this->matricula;
        }

        void setMatricula(string _matricula) {
            this->matricula = _matricula;
        }

        float getSalario() {
            return this->salario;
        }

        void setSalario(float _salario) {
            this->salario = _salario;
        }

        int getCaraHoraria() {
            return this->cargaHoraria;
        }

        void setCargaHoraria(int _cargaHoraria) {
            this->cargaHoraria = _cargaHoraria;
        }

        // Como é pra sobrescrever esse método?
        virtual void imprimirAtributos() = 0;

        virtual void imprimirFuncao() = 0;
};

class Analista: public Funcionario{
    public:
        Analista(string _nome, string _matricula, float _salario, int _cargaHoraria): Funcionario(_nome, _matricula, _salario, _cargaHoraria) {}

        void imprimirAtributos() {
            cout << "Nome: " << this->getNome() << endl;
            cout << "Matricula: " << this->getMatricula() << endl;
            cout << "Salario: " << this->getSalario() << endl;
            cout << "Carga Horária: " << this->getCaraHoraria() << endl;
        }
        void imprimirFuncao() {
            cout << "Analista\n";
        }
};
class Desenvolvedor: public Funcionario{
    public:
        Desenvolvedor(string _nome, string _matricula, float _salario, int _cargaHoraria): Funcionario(_nome, _matricula, _salario, _cargaHoraria) {}
        void imprimirAtributos() {
            cout << "Nome: " << this->getNome() << endl;
            cout << "Matricula: " << this->getMatricula() << endl;
            cout << "Salario: " << this->getSalario() << endl;
            cout << "Carga Horária: " << this->getCaraHoraria() << endl;
        }
        void imprimirFuncao() {
            cout << "Desenvolvedor\n";
        }
};
class Testador: public Funcionario{
    public:
        Testador(string _nome, string _matricula, float _salario, int _cargaHoraria): Funcionario(_nome, _matricula, _salario, _cargaHoraria) {}
        void imprimirAtributos() {
            cout << "Nome: " << this->getNome() << endl;
            cout << "Matricula: " << this->getMatricula() << endl;
            cout << "Salario: " << this->getSalario() << endl;
            cout << "Carga Horária: " << this->getCaraHoraria() << endl;
        }
        void imprimirFuncao() {
            cout << "Testador\n";
        }
};

int main(int argc, char const* argv[])
{
    Setor<Analista, int> *setor1;
    setor1 = new Setor<Analista, int>(999);
    Setor<Desenvolvedor, float> *setor2;
    setor2 = new Setor<Desenvolvedor, float>(0.999);
    Setor<Testador, string> *setor3;
    setor3 = new Setor<Testador, string>("qwe123");

    Analista *func1;
    func1 = new Analista("nome1", "matricula1", 1200, 40);
    Analista *func2;
    func2 = new Analista("nome2", "matricula2", 1250, 40);
    Desenvolvedor *func3;
    func3 = new Desenvolvedor("nome3", "matricula3", 1000, 40);
    Desenvolvedor *func4;
    func4 = new Desenvolvedor("nome4", "matricula4", 1000, 40);
    Testador *func5;
    func5 = new Testador("nome5", "matricula5", 500, 40);
    Testador *func6;
    func6 = new Testador("nome6", "matricula6", 500, 40);

    setor1->adicionaMembro(func1);
    setor1->adicionaMembro(func2);
    setor2->adicionaMembro(func3);
    setor2->adicionaMembro(func4);
    setor3->adicionaMembro(func5);
    setor3->adicionaMembro(func6);

    cout << "Setor: ";
    setor1->getMembros()[0]->imprimirFuncao();
    setor1->getMembros()[0]->imprimirAtributos();
    setor1->getMembros()[1]->imprimirAtributos();
    cout << endl;

    cout << "Setor: ";
    setor2->getMembros()[0]->imprimirFuncao();
    setor2->getMembros()[0]->imprimirAtributos();
    setor2->getMembros()[1]->imprimirAtributos();
    cout << endl;

    cout << "Setor: ";
    setor3->getMembros()[0]->imprimirFuncao();
    setor3->getMembros()[0]->imprimirAtributos();
    setor3->getMembros()[1]->imprimirAtributos();
    cout << endl;

    delete setor1;
    delete setor2;
    delete setor3;
    delete func1;
    delete func2;
    delete func3;
    delete func4;
    delete func5;
    delete func6;

    return 0;
}
