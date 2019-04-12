#include<iostream>

using namespace std;

template <typename tipo>
void ordenaVetor(tipo *v,int tam ,bool ordem){
  tipo aux;
  if (ordem == true){
    cout<<"crescente"<<endl;
    for (int i=0; i<tam; i++){
      for (int j=0; j<tam; j++){
        if (v[i] < v[j]){
          aux = v[i];
          v[i] = v[j];
          v[j] = aux;
        }
      }
    }
  }else{
      cout<<"decrescente"<<endl;
    for (int i=0; i<tam; i++){
      for (int j=0; j<tam; j++){
        if (v[i] > v[j]){
          aux = v[i];
          v[i] = v[j];
          v[j] = aux;
        }
       }
    }
  }
}

template <typename tipo>
tipo* leVetor(int tam){
    cout<<"digite seu vetor:"<<endl;
    tipo p;
    tipo* u;
    u = new tipo[tam];
    for (int i=0; i<tam; i++){
        cin>>p;
        u[i] = p;
    }
    return u;
}

template <typename tipo>
void imprimeVetor(tipo *v,int tam){
   for (int i=0; i<tam; i++){
     cout<<"["<<v[i]<<"]"<<endl;
   }
}


void menu(){
    cout<<"Escolha um tipo entre as opcoes abaixo:"<<endl;
    cout<<"1) Inteiro"<<endl;
    cout<<"2) Real"<<endl;
    cout<<"3) Inteiro longo"<<endl;
    cout<<"4) Real longo"<<endl;
    cout<<"5) Caractere"<<endl;
}



int main (){
    menu();
    bool ordem;
    int k,tam;
    cout<<"insira o  tamanho do seu vetor:"<<endl;
    cin>>tam;
    if (tam<0){
        cout<<"digite outro numero, maior que zero:";
        cin>>tam;
        }
    cout<<"informe o tipo do vetor:"<<endl;
    cin>>k;
    switch (k){
   case 1:
       int *u;
       u = leVetor<int>(tam);
       ordenaVetor<int>(u, tam, true);
       imprimeVetor<int>(u, tam);
       ordenaVetor<int>(u, tam, false);
       imprimeVetor<int>(u, tam);
       break;
    case 2:
       float *v;
       v = leVetor<float>(tam);
       ordenaVetor<float>(v, tam, true);
       imprimeVetor<float>(v, tam);
       ordenaVetor<float>(v, tam, false);
       imprimeVetor<float>(v, tam);
       break;
    case 3:
       long int *w;
       w = leVetor<long int>(tam);
       ordenaVetor<long int>(w, tam, true);
       imprimeVetor<long int>(w, tam);
       ordenaVetor<long int>(w, tam, false);
       imprimeVetor<long int>(w, tam);
       break;
    case 4:
       double *x;
       x = leVetor<double>(tam);
       ordenaVetor<double>(x, tam, true);
       imprimeVetor<double>(x, tam);
       ordenaVetor<double>(x, tam, false);
       imprimeVetor<double>(x, tam);
       break;
    case 5:
       char *y;
       y = leVetor<char>(tam);
       ordenaVetor<char>(y, tam, true);
       imprimeVetor<char>(y, tam);
       ordenaVetor<char>(y, tam, false);
       imprimeVetor<char>(y, tam);
       break;
    }

}

