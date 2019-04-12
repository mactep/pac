#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <vector>
#include "EmpresaDesenvolvedora.h"
#include "PlataformaDigital.h"

using namespace std;

int Jogo::qtdJogos = 0;

void presenteVirtual(PlataformaDigital *presenteador, PlataformaDigital *presenteado, Jogo *presente){
    for (unsigned int i = 0; i < presenteado->getJogosCadastrados().size(); i++) {
        if (presenteado->getJogosCadastrados()[i]->getNome() == presente->getNome()) {
            cout << "Jogo ja cadastrado na plataforma do presenteado\n";
            cout << "Adicionando fundos...\n";
            presenteado->setCarteiraDigital(presente->getValorPromocao());
            return;
        }
    }
    if (presenteador->getCarteiraDigital() >= presente->getValorPromocao()) {
        cout << presente->getNome() << " foi presenteado\n";
        presenteado->jogosCadastrados.push_back(presente);
        presenteador->setCarteiraDigital(presenteador->getCarteiraDigital() - presente->getValorPromocao());
    } else {
        cout << "Nao possui creditos suficientes para comprar esse jogo\n";
    }
}

template<typename T>
int seleciona(vector<T> vetor) {
    int escolhido = -1;

    while (escolhido <= 0 || (unsigned int)escolhido > vetor.size()) {
        cout << "Selecione uma entidade\n";
        for (unsigned int i = 0; i < vetor.size(); i++) {
            cout << i + 1 << " - " << vetor[i]->getNome() << endl;
        }
        cout << "> ";
        cin >> escolhido;
    }
    return escolhido;
}

//int selecionaEmpresa() {
//    int empresa = -1;

//    while (empresa < 0 || empresa > 3) {
//        cout << "Selecione a empresa\n";
//        cout << "1 - Blizzard\n";
//        cout << "2 - Ubisoft\n";
//        cout << "3 - Konami\n";
//        cout << "> ";
//        cin >> empresa;
//    }
//    return empresa;
//}

//int selecionaPlataforma() {
//    int plataforma = -1;

//    while (plataforma < 0 || plataforma > 3) {
//        cout << "Selecione a plataforma\n";
//        cout << "1 - Steam\n";
//        cout << "2 - Uplay\n";
//        cout << "3 - Battlenet\n";
//        cout << "> ";
//        cin >> plataforma;
//    }
//    return plataforma;
//}

void imprime_menu() {
    cout << "1 - Criar Jogo\n";
    cout << "2 - Colocar Jogo em Promoção\n";
    cout << "3 - Tirar Jogo de Promoção\n";
    cout << "4 - Comprar Jogo\n";
    cout << "5 - Adicionar Créditos na Carteira\n";
    cout << "6 - Instalar Jogo\n";
    cout << "7 - Desinstalar Jogo\n";
    cout << "8 - Imprimir Jogos Cadastrados\n";
    cout << "9 - Imprimir Jogos Instalados\n";
    cout << "10 - Imprimir Jogos Cadastrados por Gênero\n";
    cout << "11 - Presentear Plataforma\n";
    cout << "12 - Imprimir Quantidade de Jogos Criados\n";
    cout << "13 - Salvar Empresa Desenvolvedora\n";
    cout << "14 - Salvar Plataforma Digital\n";
    cout << "15 - Carregar Empresa Desenvolvedora\n";
    cout << "16 - Carregar Plataforma Digital\n";
    cout << "17 - Exportar Biblioteca de uma Plataforma Digital\n";
    cout << "18 - Imprimir Quantidade de Créditos na Carteira\n";
    cout << "19 - Sair\n";
    cout << "Selecione uma opção: ";
}

int main(int argc, char const* argv[])
{
    vector<EmpresaDesenvolvedora*> empresas;
    vector<PlataformaDigital*> plataformas;

    EmpresaDesenvolvedora *blizzard;
    blizzard = new EmpresaDesenvolvedora("Blizzard");
    empresas.push_back(blizzard);

    EmpresaDesenvolvedora *ubisoft;
    ubisoft = new EmpresaDesenvolvedora("Ubisoft");
    empresas.push_back(ubisoft);

    EmpresaDesenvolvedora *konami;
    konami = new EmpresaDesenvolvedora("Konami");
    empresas.push_back(konami);

    PlataformaDigital *steam;
    steam = new PlataformaDigital("Steam", 0);
    plataformas.push_back(steam);

    PlataformaDigital *uplay;
    uplay = new PlataformaDigital("Uplay", 0);
    plataformas.push_back(uplay);

    PlataformaDigital *battlenet;
    battlenet = new PlataformaDigital("Battlenet", 0);
    plataformas.push_back(battlenet);

    while (1) {
        system("clear");
        imprime_menu();
        int opcaoEscolhida;
        cin >> opcaoEscolhida;

        switch (opcaoEscolhida) {
            case 1: // Criar Jogo
                {
                    int tipo = -1;
                    while (tipo != 1 && tipo != 2) {
                        cout << "Digite o tipo do jogo\n";
                        cout << "1 - Jogo PC\n";
                        cout << "2 - Jogo Console\n";
                        cout << "> ";
                        cin >> tipo;
                    }

                    empresas[seleciona<EmpresaDesenvolvedora*>(empresas) - 1]->criarJogo(tipo);
                }
                break;
            case 2: // Colocar jogo em promocao
                empresas[seleciona<EmpresaDesenvolvedora*>(empresas) - 1]->colocarJogoPromocao();
                break;
            case 3: //Tirar Jogo de Promoção
                // usuario escolhe a empresa e o metodo tirar jogo promocao e chamado
                empresas[seleciona<EmpresaDesenvolvedora*>(empresas) - 1]->tirarJogoPromocao();
                break;
            case 4: // Comprar jogo
                {
                    int empresaEscolhida = seleciona<EmpresaDesenvolvedora*>(empresas) - 1;
                    if (!empresas[empresaEscolhida]->getJogosDesenvolvidos().size()) {
                        cout << "Nenhum jogo desenvolvido\n";
                        break;
                    }
                    for (unsigned int i = 0; i < empresas[empresaEscolhida]->getJogosDesenvolvidos().size(); i++) {
                        cout << i + 1 << " - ";
                        empresas[empresaEscolhida]->getJogosDesenvolvidos()[i]->imprimeInfoJogo();
                    }
                    int escolhido = -1;
                    while (escolhido <= 0 || (unsigned int)escolhido > empresas[empresaEscolhida]->getJogosDesenvolvidos().size()) {
                        cout << "Escolha um jogo para comprar: ";
                        cin >> escolhido;
                    }
                    int plataformaEscolhida = seleciona<PlataformaDigital*>(plataformas) - 1;
                    plataformas[plataformaEscolhida]->comprarJogo(empresas[empresaEscolhida]->getJogosDesenvolvidos()[escolhido - 1]);
                    break;
                }
            case 5: // Adicionar creditos a carteira
                {
                    int plataformaEscolhida = seleciona<PlataformaDigital*>(plataformas) - 1;
                    float valor = -1;
                    while (valor < 0) {
                        cout << "Digite a quantia a ser adicionada: ";
                        cin >> valor;
                    }
                    plataformas[plataformaEscolhida]->adicionarCreditosCarteira(valor);
                }
                break;
            case 6: // Instalar jogo
                plataformas[seleciona<PlataformaDigital*>(plataformas) - 1]->instalarJogo();
                break;
            case 7: // Desinstalar jogo
                plataformas[seleciona<PlataformaDigital*>(plataformas) - 1]->desinstalarJogo();
                break;
            case 8: // Imprime jogos cadastrados
                plataformas[seleciona<PlataformaDigital*>(plataformas) - 1]->imprimeJogosCadastrados();
                break;
            case 9: // Imprime jogos Instalados
                plataformas[seleciona<PlataformaDigital*>(plataformas) - 1]->imprimeJogosInstalados();
                break;
            case 10: // Imprime jogos de um certo genero
                {
                    cout << "Digite o genero desejado: ";
                    string genero;
                    cin >> genero;
                    plataformas[seleciona<PlataformaDigital*>(plataformas) - 1]->imprimeJogos(genero);
                }
                break;
            case 11: // Presentear plataforma
                {
                    cout << "Escolha um presenteador:\n";
                    int presenteador = seleciona<PlataformaDigital*>(plataformas) - 1;
                    cout << "Escolha um presenteado:\n";
                    int presenteado = seleciona<PlataformaDigital*>(plataformas) - 1;
                    cout << "Escolha a empresa desenvolvedora:\n";
                    int empresa = seleciona<EmpresaDesenvolvedora*>(empresas) - 1;
                    for (unsigned int i = 0; i < empresas[empresa]->getJogosDesenvolvidos().size(); i++) {
                        cout << i + 1 << " - ";
                        empresas[empresa]->getJogosDesenvolvidos()[i]->imprimeInfoJogo();
                    }
                    int escolhido = -1;
                    while (escolhido <= 0 || (unsigned int)escolhido > empresas[empresa]->getJogosDesenvolvidos().size()) {
                        cout << "Escolha um jogo para presentear: ";
                        cin >> escolhido;
                    }
                    presenteVirtual(plataformas[presenteador], plataformas[presenteado], empresas[empresa]->getJogosDesenvolvidos()[escolhido - 1]);
                }
                break;
            case 12: //Imprimir quantidade de jogos criados
                cout << "O total de jogos criados é ";
                Jogo::imprimeQtdJogos();
                cout << endl;
                break;
            case 13: // Salvar Empresa Desenvolvedora
                empresas[seleciona<EmpresaDesenvolvedora*>(empresas) - 1]->salvarDados();
                break;
            case 14:
                plataformas[seleciona<PlataformaDigital*>(plataformas) - 1]->salvarDados();
                break;
            case 15: // Carregar Empresa Desenvolvedora
                {
                    string nomeArquivo;
                    cout << "Digite o nome da empresa: ";
                    cin >> nomeArquivo;
                    ifstream fp;

                    fp.open((nomeArquivo + ".txt").c_str());
           //         fp.open(nomeArquivo + ".txt");

                    if (!fp.is_open()) {
                        cout << "Nao existem dados salvos da empresa!\n";
                    } else {
                        for (unsigned int i = 0; i < empresas.size(); i++) {
                            if (empresas[i]->getNome() == nomeArquivo) {
                                empresas.erase(empresas.begin() + i);
                                break;
                            }
                        }
                        EmpresaDesenvolvedora *emp;
                        emp = new EmpresaDesenvolvedora();
                        emp->carregarDados(nomeArquivo);
                        empresas.push_back(emp);
                        fp.close();
                    }
                    break;
                }
            case 16: // Carregar Plataforma Digital
                {
                    string nomeArquivo;
                    cout << "Digite o nome da plataforma: ";
                    cin >> nomeArquivo;
                    ifstream fp;

                    fp.open((nomeArquivo +".txt").c_str());
                   // fp.open(nomeArquivo + ".txt");

                    if (!fp.is_open()) {
                        cout << "Nao existem dados salvos da plataforma!\n";
                    } else {
                        for (unsigned int i = 0; i < plataformas.size(); i++) {
                            if (plataformas[i]->getNome() == nomeArquivo) {
                                plataformas.erase(plataformas.begin() + i);
                                break;
                            }
                        }
                        PlataformaDigital *plat;
                        plat = new PlataformaDigital();
                        plat->carregarDados(nomeArquivo);
                        plataformas.push_back(plat);
                        fp.close();
                    }
                    break;
                }
            case 17: //Exportar Biblioteca de uma Plataforma Digital
                plataformas[seleciona<PlataformaDigital*>(plataformas) - 1]->exportarBibliotecaJogos();
                break;
            case 18: // Imprimir quantidade de creditos
                cout << "R$ " << plataformas[seleciona<PlataformaDigital*>(plataformas) - 1]->getCarteiraDigital() << endl;
                break;
            case 19: // Sair
                {
                    empresas.clear();
                    plataformas.clear();
                    return 0;
                }
                break;
        }
    sleep(1.5);
    }
    return 0;
}
