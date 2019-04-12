#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <pthread.h>

using namespace std;

void *thread1(void *data) {
    ifstream arquivo;
    arquivo.open("entrada1.txt");
    vector<int> *vetor;
    vetor = (vector<int>*)data;

    if (!arquivo.is_open()) {
        cerr << "Arquivo nao foi aberto corretamente!\n";
        exit(1);
    } else {
        int aux;
        while (arquivo >> aux) {
            vetor->push_back(aux);
        }
    }
    pthread_exit(NULL);
    arquivo.close();
}

void *thread2(void *data) {
    ifstream arquivo;
    arquivo.open("entrada2.txt");
    vector<int> *vetor;
    vetor = (vector<int>*)data;

    if (!arquivo.is_open()) {
        cerr << "Arquivo nao foi aberto corretamente!\n";
        exit(1);
    } else {
        int aux;
        while (arquivo >> aux) {
            vetor->push_back(aux);
        }
    }
    pthread_exit(NULL);
    arquivo.close();
}

void soma(vector<int> vetor1, vector<int> vetor2) {
    ofstream arquivo;
    arquivo.open("saida.txt");

    if (!arquivo.is_open()) {
        cerr << "Arquivo nao foi aberto corretamente\n";
        exit(1);
    } else {
        for (unsigned int i = 0; i < vetor1.size(); i++) {
            cout << vetor1[i] + vetor2[i] << endl;
            arquivo << vetor1[i] + vetor2[i] << endl;
        }
        arquivo.close();
    }
}

int main(int argc, char const *argv[]) {
    void *status;
    vector<int> A;
    vector<int> B;

    pthread_t t1;
    pthread_t t2;

    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    int rc1 = pthread_create(&t1, &attr, thread1, (void*)&A);
    int rc2 = pthread_create(&t2, &attr, thread2, (void*)&B);

    if (rc1) {
        cerr << "Erro ao criar a thread, " << rc1 << endl;
        return 1;
    }
    if (rc2) {
        cerr << "Erro ao criar a thread, " << rc2 << endl;
        return 1;
    }

    pthread_attr_destroy(&attr);

    rc1 = pthread_join(t1, &status);
    rc2 = pthread_join(t2, &status);

    soma(A, B);
    pthread_exit(NULL);
}
